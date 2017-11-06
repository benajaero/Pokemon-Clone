#include "playing.h"
#include "definitions.h"

#include "AnimatedSprite.hpp"
#include "util.h"
#include "game.h"
#include "texturemanager.h"
#include "mapManager.h"
#include "tmxlite/Map.hpp" 
#include "SFMLOrthogonalLayer.hpp"
#include "spritemanager.h"
#include <cassert>


void PlayController::logic() {
    Game::hero.moveForward(0.75, view, Game::frameTime);
    //if(!sf::Event::KeyPressed)
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::RenderWindow& window) {
    _actionMap.update(window);
}

void PlayController::draw(sf::RenderWindow& window) {

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
    
    MapLayer layerZero(MapManager::getMap("outer"), 0);
    MapLayer layerOne(MapManager::getMap("outer"), 1);
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(150, 50, 250));

    // set a 10-pixel wide orange outline
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    window.clear(sf::Color::White);
    window.setView(view);
    window.draw(layerZero, sf::Transform().scale(SCALE, SCALE));
    window.draw(layerOne, sf::Transform().scale(SCALE, SCALE));
    window.draw(heroSprite);
    window.draw(shape);
    window.display();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
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
    
}
