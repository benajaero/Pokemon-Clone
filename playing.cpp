#include "playing.h"
#include <cassert>

//const int tileHeight = 24;
const int scale = 5;

void PlayController::logic() {

}

void PlayController::handleEvents(sf::Event& event, sf::RenderWindow& window) {
    draw(window);
}

void PlayController::draw(sf::RenderWindow& window) {
    sf::Sprite sprite;
    sprite.setTexture(playerTexture);
    sprite.setTextureRect(sf::IntRect(198, 102, 24, 24));
    sprite.setPosition(1920/2, 1080/2);
    sprite.setScale(scale, scale);

    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();
}

void PlayController::loadTextures() {
    assert(playerTexture.loadFromFile("./assets/NewHero.png"));
}
