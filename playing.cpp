#include "playing.h"
#include <cassert>
#include "AnimatedSprite.hpp"

//const int tileHeight = 24;
const int scale = 5;

void PlayController::logic(sf::Time frameTime) {
    hero.moveForward(0.75, view, frameTime);
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::Event& event, sf::RenderWindow& window, sf::Time frameTime) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            hero.xvel -= 10;
            hero.changeOrientation(EAST);
        }
        else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            hero.xvel += 10;
            hero.changeOrientation(WEST);
        }
        else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
            hero.yvel += 10;
            hero.changeOrientation(NORTH);
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
            hero.yvel -= 10;
            hero.changeOrientation(SOUTH);
        }
    }
    draw(window, frameTime);
}

void PlayController::draw(sf::RenderWindow& window, sf::Time frameTime) {
    AnimatedSprite sprite(sf::seconds(0.2f), true, false);
    sprite.setPosition(1920 / 2, 1080 / 2 );

    if (hero.direction == NORTH) {
        if (hero.isMoving)
            sprite.play(hero.walk.up);
        else
            sprite.play(hero.idle.up);
    }
    else if (hero.direction == EAST) {
        if (hero.isMoving)
            sprite.play(hero.walk.right);
        else
            sprite.play(hero.idle.right);
    }

    else if (hero.direction == WEST) {
        if (hero.isMoving)
            sprite.play(hero.walk.left);
        else
            sprite.play(hero.idle.left);
    }

    else if (hero.direction == SOUTH) {
        if (hero.isMoving)
            sprite.play(hero.walk.down);
        else
            sprite.play(hero.idle.down);
    }

    sprite.setScale(scale, scale);

    sprite.setPosition(1920/2, 1080/2);

    sf::CircleShape circle(50);
    circle.setPosition(1920/2, 1080/2);
    circle.setFillColor(sf::Color::Black);
    
    window.setView(view);
    window.clear(sf::Color::White);
    sprite.update(frameTime);
    window.draw(circle);
    window.display();
}

void PlayController::loadTextures() {
    assert(playerTexture.loadFromFile("./assets/NewHero.png"));
    playerTexture.setSmooth(false);
    hero.setupAnimations(playerTexture);
}

void PlayController::setup() {
    view.setSize(1920, 1080);
    view.setCenter(0, 0);
}
