#include "playing.h"
#include "definitions.h"

#include "AnimatedSprite.hpp"
#include "util.h"
#include "game.h"
#include "texturemanager.h"
#include "spritemanager.h"
#include <cassert>
#include <iostream>

bool AABBIntersection(sf::Vector2f objPos, sf::Vector2f objSize, sf::Vector2f objPos1, sf::Vector2f objSize1) {
    bool x_overlaps = (objPos.x < objPos1.x + objSize1.x) && (objPos.x + objSize.x > objPos1.x);
    bool y_overlaps = (objPos.y < objPos1.y + objSize1.y) && (objPos.y + objSize.y > objPos1.y);
    //std::cout << x_overlaps << "- " << y_overlaps << "\n";
    return x_overlaps && y_overlaps;
}

void reactToCollision(sf::Vector2f diff, sf::Vector2f didCollide) {
    diff.x += 1;
    diff.y += 1;
    Game::hero.moveBack(diff, didCollide);
}

double calculateModifier() {
    return 0.0;
}

sf::Vector2f checkCollisionLayer(sf::Vector2f& boolVal, tmx::MapLoader& _map, Hero& hero, std::string layerName, sf::RenderWindow& window) {
    AnimatedSprite heroSprite = SpriteManager::getAnimRef("hero");
    sf::FloatRect heroRect = heroSprite.getGlobalBounds();
    std::vector<tmx::MapObject*> objects = _map.queryQuadTree(heroRect);
    //std::stringstream stream;
    //stream << "Query object count: " << objects.size();
    //window.setTitle(stream.str()); 
    for (const auto& object : objects) {
        //std::cout << "Did colide\n" << std::endl;
        if (object->getParent() == "Collision2") {
            //sf::Vector2f points[4] = {sf::Vector2f(heroRect.left, heroRect.top), sf::Vector2f(heroRect.left + heroRect.width, heroRect.top), sf::Vector2f(heroRect.left, heroRect.top + heroRect.height), sf::Vector2f(heroRect.left + heroRect.width, heroRect.top + heroRect.height) };
            if (object->getAABB().intersects(heroRect)) {
                sf::FloatRect objAABB = object->getAABB();
                float heroRight = heroRect.left + heroRect.width;
                float heroBottom = heroRect.top + heroRect.height;
                float objRight = objAABB.left + objAABB.width;
                float objBottom = objAABB.top + heroRect.height;

                sf::Vector2f diff(0,0);
                //hit left
                if (heroRight > objAABB.left && heroRect.left < objAABB.left) {
                    diff.x = heroRight - objAABB.left;
                    boolVal.x = 1;
                }
                //hit right
                else if (heroRect.left < objRight && heroRight > objRight) {
                    diff.x = objRight - heroRect.left;
                    boolVal.x = 2;
                }
                //hit top
                if (heroBottom > objAABB.top && heroRect.top < objAABB.top) {
                    diff.y = heroBottom - objAABB.top;
                    boolVal.y = 1;
                }
                //hit bottom
                else if (heroRect.top < objBottom && heroBottom > objBottom) {
                    diff.y = objBottom - heroRect.top;
                    boolVal.y = 2;
                }

                return diff;


            }
        }
    }
    return sf::Vector2f(0,0);
} 

void PlayController::logic(tmx::MapLoader& _map) {
    _map.updateQuadTree(sf::FloatRect(view.getCenter().x, view.getCenter().y, view.getSize().x, view.getSize().y));
    sf::Vector2f didCollide(0,0);

    sf::Vector2f diff = checkCollisionLayer(didCollide, _map, Game::hero, "Collision", Game::_mainWindow); 
    //checkCollisionLayer(didCollide, _map, Game::hero, "Collision2"); 
    if (didCollide.x || didCollide.y)
        reactToCollision(diff, didCollide);
    double modifier = 1;
    Game::hero.moveForward(modifier, view, Game::frameTime);
    if (didCollide.x || didCollide.y) {
        Game::hero.xvel = 0;
        Game::hero.yvel = 0;
    }
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::RenderWindow& window) {
    _actionMap.update(window);
    if (_actionMap.isActive("closeWindow"))
        Game::_gameState = Game::EXITING;
    else {

        if (_actionMap.isActive("releaseLeft") || _actionMap.isActive("releaseRight"))
            Game::hero.xvel = 0;
        if (_actionMap.isActive("releaseUp") || _actionMap.isActive("releaseDown"))
            Game::hero.yvel = 0;
        if (_actionMap.isActive("releaseRun"))
            Game::hero.personState = Hero::NORMAL;
        if (_actionMap.isActive("moveRight")) {
            Game::hero.xvel = MOVE_VAL;
            Game::hero.changeOrientation(EAST);
            Game::hero.isMoving = true;
        }
        else if (_actionMap.isActive("moveLeft")) {
            Game::hero.xvel =  0 - MOVE_VAL;
            Game::hero.changeOrientation(WEST);
            Game::hero.isMoving = true;
        }
        else if (_actionMap.isActive("moveUp")) {
            Game::hero.yvel = 0 - MOVE_VAL;
            Game::hero.changeOrientation(NORTH);
            Game::hero.isMoving = true;
        }
        else if (_actionMap.isActive("moveDown")) {
            Game::hero.yvel = MOVE_VAL;
            Game::hero.changeOrientation(SOUTH);
            Game::hero.isMoving = true;
        }
        else {
            Game::hero.isMoving = false;
            if (Game::hero.personState == Hero::RUNNING)
                Game::hero.personState = Hero::NORMAL;
        }

        if (_actionMap.isActive("holdCycle") && (Game::hero.personState == Hero::NORMAL || Game::hero.personState == Hero::RUNNING) && Game::hero.isMoving == true) {
            Game::hero.personState = Hero::RUNNING; 
            Game::hero.xvel *= 1.5;
            Game::hero.yvel *= 1.5;
        }
        else if (_actionMap.isActive("pressCycle")) {
            if (Game::hero.personState == Hero::CYCLING)
                Game::hero.personState = Hero::NORMAL;
            else if (Game::hero.personState == Hero::NORMAL)
                Game::hero.personState = Hero::CYCLING;
        }


    }
}

void PlayController::draw(sf::RenderWindow& window, tmx::MapLoader& _map) {

    AnimatedSprite& heroSprite = SpriteManager::getAnimRef("hero");
    Game::hero.handleAnimations(heroSprite);
    heroSprite.update(Game::frameTime);

    if (!Game::hero.isMoving) {
        heroSprite.stop();
    }
    heroSprite.setPosition(view.getCenter());
    //sf::CircleShape circle(50);
    //circle.setPosition(0, 0);
    //circle.setFillColor(sf::Color::Black);
    
    bool debug = true;


    window.clear(sf::Color::White);
    window.setView(view);
    window.draw(_map);

    if (debug) {
        _map.drawLayer(window, tmx::MapLayer::Debug);
        sf::RectangleShape rectangle(sf::Vector2f(heroSprite.getGlobalBounds().width, heroSprite.getGlobalBounds().height));
        rectangle.setPosition(heroSprite.getPosition());
        window.draw(rectangle);
    }

    window.draw(heroSprite);
    window.display();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    Game::hero.setPos(sf::Vector2f(55, 82));
    //Game::_map.ShowObjects();
    view.setCenter(Game::hero.x * TILE_HEIGHT, Game::hero.y * TILE_HEIGHT);
    view.zoom(0.25f);
    setupActions();
}

void PlayController::setupActions() {
   //define actions
    thor::Action leftArrowHold(sf::Keyboard::Left, thor::Action::Hold);
    thor::Action rightArrowHold(sf::Keyboard::Right, thor::Action::Hold);
    thor::Action upArrowHold(sf::Keyboard::Up, thor::Action::Hold);
    thor::Action downArrowHold(sf::Keyboard::Down, thor::Action::Hold);

    thor::Action holdKeyA(sf::Keyboard::A, thor::Action::Hold);
    thor::Action holdKeyD(sf::Keyboard::D, thor::Action::Hold);
    thor::Action holdKeyW(sf::Keyboard::W, thor::Action::Hold);
    thor::Action holdKeyS(sf::Keyboard::S, thor::Action::Hold);

    thor::Action leftArrowRelease(sf::Keyboard::Left, thor::Action::ReleaseOnce);
    thor::Action rightArrowRelease(sf::Keyboard::Right, thor::Action::ReleaseOnce);
    thor::Action upArrowRelease(sf::Keyboard::Up, thor::Action::ReleaseOnce);
    thor::Action downArrowRelease(sf::Keyboard::Down, thor::Action::ReleaseOnce);

    thor::Action releaseKeyA(sf::Keyboard::A, thor::Action::ReleaseOnce);
    thor::Action releaseKeyD(sf::Keyboard::D, thor::Action::ReleaseOnce);
    thor::Action releaseKeyW(sf::Keyboard::W, thor::Action::ReleaseOnce);
    thor::Action releaseKeyS(sf::Keyboard::S, thor::Action::ReleaseOnce);

    thor::Action holdRunKey(sf::Keyboard::R, thor::Action::Hold);
    thor::Action releaseRunKey(sf::Keyboard::R, thor::Action::ReleaseOnce);
    thor::Action pressCycleKey(sf::Keyboard::C, thor::Action::PressOnce);

    thor::Action moveLeft = leftArrowHold || holdKeyA;
    thor::Action moveRight = rightArrowHold || holdKeyD;
    thor::Action moveUp = upArrowHold || holdKeyW;
    thor::Action moveDown = downArrowHold || holdKeyS;

    thor::Action releaseLeft = leftArrowRelease || releaseKeyA;
    thor::Action releaseRight = rightArrowRelease || releaseKeyD;
    thor::Action releaseUp = upArrowRelease || releaseKeyW;
    thor::Action releaseDown = downArrowRelease || releaseKeyS;

   //bind actions 
   _actionMap["moveLeft"] = moveLeft;
   _actionMap["moveRight"] = moveRight;
   _actionMap["moveUp"] = moveUp;
   _actionMap["moveDown"] = moveDown;
   _actionMap["closeWindow"] = thor::Action(sf::Event::Closed);
   _actionMap["releaseLeft"] = releaseLeft;
   _actionMap["releaseRight"] = releaseRight;
   _actionMap["releaseUp"] = releaseUp;
   _actionMap["releaseDown"] = releaseDown;
   _actionMap["holdRun"] = holdRunKey;
   _actionMap["releaseRun"] = releaseRunKey;
   _actionMap["pressCycle"] = pressCycleKey;
    
}
