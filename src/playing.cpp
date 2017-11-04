#include "playing.h"
#include "definitions.h"

#include "AnimatedSprite.hpp"
#include "util.h"
#include "game.h"
#include "texturemanager.h"
#include "tmxlite/Map.hpp" 
#include "SFMLOrthogonalLayer.hpp"
#include "spritemanager.h"
#include <cassert>


void PlayController::logic() {
    Game::hero.moveForward(0.75, view, Game::frameTime);
    //if(!sf::Event::KeyPressed)
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            Game::hero.isMoving = true;
            Game::hero.xvel = 50;
            Game::hero.changeOrientation(EAST);
        }
        else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            Game::hero.isMoving = true;
            Game::hero.xvel = -50;
            Game::hero.changeOrientation(WEST);
        }
        else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
            Game::hero.isMoving = true;
            Game::hero.yvel = -50;
            Game::hero.changeOrientation(NORTH);
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
            Game::hero.isMoving = true;
            Game::hero.yvel = 50;
            Game::hero.changeOrientation(SOUTH);
        } 
        else {
            Game::hero.isMoving = false;
            Game::hero.xvel = 0;
            Game::hero.yvel = 0;
        }
    }
    draw(window);
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
    
    tmx::Map _map;
    assert(_map.load("assets/testmap.tmx"));
    MapLayer layerZero(_map, 0);
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(150, 50, 250));

    // set a 10-pixel wide orange outline
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color(250, 150, 100));

    window.clear(sf::Color::White);
    window.setView(view);
    window.draw(layerZero, sf::Transform().scale(SCALE, SCALE));
    window.draw(heroSprite);
    window.draw(shape);
    window.display();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    window.setView(view);
}
