#include "playing.h"
#include <cassert>
#include "AnimatedSprite.hpp"
#include "util.h"

//const int tileHeight = 24;
const int scale = 5;

void PlayController::logic(sf::Time frameTime) {
    hero.moveForward(0.75, view, frameTime);
    if(!sf::Event::KeyPressed)
        hero.isMoving = false;
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::Event& event, sf::RenderWindow& window, sf::Time frameTime, sf::Clock frameClock) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            hero.isMoving = true;
            hero.xvel = 10;
            hero.changeOrientation(EAST);
        }
        else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            hero.isMoving = true;
            hero.xvel += 10;
            hero.changeOrientation(WEST);
        }
        else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
            hero.isMoving = true;
            hero.yvel += 10;
            hero.changeOrientation(NORTH);
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
            hero.isMoving = true;
            hero.yvel -= 10;
            hero.changeOrientation(SOUTH);
        } 
    }
    frameTime = frameClock.restart();
    draw(window, frameTime, frameClock);
}

void PlayController::draw(sf::RenderWindow& window, sf::Time frameTime, sf::Clock frameClock) {

    Animation& currentAnimation = hero.idle.down;

    if (hero.direction == NORTH) {
        if (hero.isMoving)
            currentAnimation = hero.walk.up;
        else
            currentAnimation = hero.idle.up;
    }
    else if (hero.direction == EAST) {
        if (hero.isMoving)
            currentAnimation = hero.walk.right;
        else
            currentAnimation = hero.idle.right;
    }

    else if (hero.direction == WEST) {
        if (hero.isMoving)
            currentAnimation = hero.walk.left;
        else
            currentAnimation = hero.idle.left;
    }

    else if (hero.direction == SOUTH) {
        if (hero.isMoving)
            currentAnimation = hero.walk.down;
        else
            currentAnimation = hero.idle.down;
    }
    
    sprite.play(currentAnimation);
    sprite.setScale(scale, scale);

    sprite.setPosition(1920/2, 1080/2);

    //sf::CircleShape circle(50);
    //circle.setPosition(0, 0);
    //circle.setFillColor(sf::Color::Black);
    
    sprite.update(frameTime);
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();
}

void PlayController::loadTextures() {
    assert(playerTexture.loadFromFile("./assets/NewHero.png"));
    playerTexture.setSmooth(false);
    hero.setupAnimations(playerTexture);
    sprite.setLooped(false);
    sprite.pause();
}

void PlayController::setup(sf::RenderWindow& window) {
    view.setSize(1920, 1080);
    view.setCenter(1920/2, 1080/2);
    window.setView(view);
}
