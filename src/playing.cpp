#include "playing.h"
#include "definitions.h"
#include <cassert>

#include "AnimatedSprite.hpp"
#include "util.h"
#include "game.h"

//const int tileHeight = 24;
const int scale = 5;

void PlayController::logic() {
    Game::hero.moveForward(0.75, view, Game::frameTime);
    if(!sf::Event::KeyPressed)
        Game::hero.isMoving = false;
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            Game::hero.isMoving = true;
            Game::hero.xvel = 10;
            Game::hero.changeOrientation(EAST);
        }
        else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            Game::hero.isMoving = true;
            Game::hero.xvel = -10;
            Game::hero.changeOrientation(WEST);
        }
        else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
            Game::hero.isMoving = true;
            Game::hero.yvel = +10;
            Game::hero.changeOrientation(NORTH);
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
            Game::hero.isMoving = true;
            Game::hero.yvel = -10;
            Game::hero.changeOrientation(SOUTH);
        } 
    }
    draw(window);
}

void PlayController::draw(sf::RenderWindow& window) {

    Animation& currentAnimation = Game::hero.idle.down;

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
    
    Game::hero.sprite.play(currentAnimation);
    Game::hero.sprite.setScale(scale, scale);

    Game::hero.sprite.setPosition(window.getView().getCenter());

    //sf::CircleShape circle(50);
    //circle.setPosition(0, 0);
    //circle.setFillColor(sf::Color::Black);
    
    Game::hero.sprite.update(Game::frameTime);
    window.clear(sf::Color::White);
    window.draw(Game::hero.sprite);
    window.display();
}

void PlayController::loadTextures() {
    assert(playerTexture.loadFromFile("assets/NewHero.png"));
    playerTexture.setSmooth(false);
    Game::hero.setupAnimations(playerTexture);
    Game::hero.sprite.setLooped(false);
    Game::hero.sprite.pause();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view.setCenter(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    window.setView(view);
}
