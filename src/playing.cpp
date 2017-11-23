#include "playing.h"
#include "definitions.h"

#include "AnimatedSprite.hpp"
#include "util.h"
#include "game.h"
#include "texturemanager.h"
#include "spritemanager.h"
#include <cassert>


void PlayController::logic() {
    double modifier = 1;
    Game::hero.moveForward(0.75, view, Game::frameTime);
    //if(!sf::Event::KeyPressed)
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::RenderWindow& window) {
    _actionMap.update(window);
    if (_actionMap.isActive("closeWindow"))
        Game::_gameState = Game::EXITING;
    else {
        if (_actionMap.isActive("moveRight")) {
            Game::hero.xvel += MOVE_VAL;
            Game::hero.changeOrientation(EAST);
            Game::hero.isMoving = true;
        }
        else if (_actionMap.isActive("moveLeft")) {
            Game::hero.xvel -= MOVE_VAL;
            Game::hero.changeOrientation(WEST);
            Game::hero.isMoving = true;
        }
        else if (_actionMap.isActive("moveUp")) {
            Game::hero.yvel += MOVE_VAL;
            Game::hero.changeOrientation(NORTH);
            Game::hero.isMoving = true;
        }
        else if (_actionMap.isActive("moveDown")) {
            Game::hero.yvel -= MOVE_VAL;
            Game::hero.changeOrientation(SOUTH);
            Game::hero.isMoving = true;
        }
        else {
            Game::hero.isMoving = false;
        }
           

    }
}

void PlayController::draw(sf::RenderWindow& window, tmx::TileMap& _map) {

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
    

    // set a 10-pixel wide orange outline

    //tmx::TileMap _map("./assets/testmap2.tmx");
    _map.ShowObjects();
    window.clear(sf::Color::White);
    window.setView(view);
    window.draw(_map);
    //window.draw(Game::_map);
    window.draw(heroSprite);
    window.display();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    Game::hero.setPos(sf::Vector2f(70, 70));
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

    thor::Action moveLeft = leftArrowHold || holdKeyA;
    thor::Action moveRight = rightArrowHold || holdKeyD;
    thor::Action moveUp = upArrowHold || holdKeyW;
    thor::Action moveDown = downArrowHold || holdKeyS;
   //bind actions 
   _actionMap["moveLeft"] = moveLeft;
   _actionMap["moveRight"] = moveRight;
   _actionMap["moveUp"] = moveUp;
   _actionMap["moveDown"] = moveDown;
   _actionMap["closeWindow"] = thor::Action(sf::Event::Closed);
    
}
