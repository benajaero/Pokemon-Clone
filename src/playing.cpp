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

void reactToCollision() {
}

double calculateModifier() {
    return 0.0;
}

void checkCollisionLayer(bool& boolVal, tmx::MapLoader& _map, Hero& hero, std::string layerName) {
    AnimatedSprite heroSprite = SpriteManager::getAnimRef("hero");
    sf::FloatRect heroRect = heroSprite.getGlobalBounds();
    std::vector<tmx::MapObject*> objects = _map.queryQuadTree(heroRect);
    
    for (const auto& object : objects) {
        std::cout << "Did colide\n" << std::endl;
        if (object->getParent() == "Collision3" || object->getParent() == "Collision2") {
            boolVal = true;
        }
    }
} 

void PlayController::logic(tmx::MapLoader& _map) {
    _map.updateQuadTree(view.getViewport());
    bool didCollide = false;

    checkCollisionLayer(didCollide, _map, Game::hero, "Collision"); 
    //checkCollisionLayer(didCollide, _map, Game::hero, "Collision2"); 
    if (didCollide)
        reactToCollision();
    else {
        double modifier = 1;
        Game::hero.moveForward(modifier, view, Game::frameTime);
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
        }

    }
}

void PlayController::draw(sf::RenderWindow& window, tmx::MapLoader& _map) {

    AnimatedSprite& heroSprite = SpriteManager::getAnimRef("hero");
    Animation& currentAnimation = Game::hero.idle.down;

    if (!Game::hero.isMoving) {
        heroSprite.stop();
    }
    if (Game::hero.direction == NORTH) {
        if (Game::hero.isMoving)
            currentAnimation = Game::hero.walk.up;
        else
            currentAnimation = Game::hero.idle.up;
    }
    else if (Game::hero.direction == EAST) {
        if (Game::hero.isMoving)
            currentAnimation = Game::hero.walk.right;
        else
            currentAnimation = Game::hero.idle.right;
    }

    else if (Game::hero.direction == WEST) {
        if (Game::hero.isMoving)
            currentAnimation = Game::hero.walk.left;
        else
            currentAnimation = Game::hero.idle.left;
    }

    else if (Game::hero.direction == SOUTH) {
        if (Game::hero.isMoving)
            currentAnimation = Game::hero.walk.down;
        else
            currentAnimation = Game::hero.idle.down;
    }
    
    heroSprite.play(currentAnimation);
    heroSprite.update(Game::frameTime);
    heroSprite.setPosition(view.getCenter());
    //sf::CircleShape circle(50);
    //circle.setPosition(0, 0);
    //circle.setFillColor(sf::Color::Black);
    


    window.clear(sf::Color::White);
    window.setView(view);
    window.draw(_map);
    _map.drawLayer(window, tmx::MapLayer::Debug);
    window.draw(heroSprite);
    window.display();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    Game::hero.setPos(sf::Vector2f(42, 102));
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
    
}
