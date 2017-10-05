#include "playing.h"
#include <cassert>

//const int tileHeight = 24;
const int scale = 5;

void PlayController::logic() {
    hero.moveForward(0.75, view);
}

//reminder check for collisons, for water contact, for slowing down
void PlayController::handleEvents(sf::Event& event, sf::RenderWindow& window) {
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
    draw(window);
}

void PlayController::draw(sf::RenderWindow& window) {
    sf::Sprite sprite;
    sprite.setTexture(playerTexture);
    sprite.setTextureRect(sf::IntRect(198, 102, 24, 24));
    sprite.setPosition(hero.x, hero.y);
    sprite.setScale(scale, scale);

    window.setView(view);
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();
}

void PlayController::loadTextures() {
    assert(playerTexture.loadFromFile("./assets/NewHero.png"));
    playerTexture.setSmooth(false);
}

void PlayController::setup() {
    view.setSize(1920, 1080);
    view.setCenter(0, 0);
}
