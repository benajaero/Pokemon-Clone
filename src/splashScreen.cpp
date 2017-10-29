#include "splashScreen.h"
#include "util.h"
#include "definitions.h"
#include "texturemanager.h"
#include "game.h"
#include <cassert>
#include <iostream>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

bool SplashScreen::loading = true;

void loadTextures() {

}

void loadSprites() {

}

void loadAnimations() {

}

void Load() {
    Game::_gameState = Game::PLAYING;
    SplashScreen::loading = false;
}

void SplashScreen::Show(sf::RenderWindow& window) {

    sf::Sprite splashScreenSprite;
    splashScreenSprite.setTexture(TextureManager::getRef("splashScreenBackground"));


    loading = true; 

    std::thread loadingThread(Load);
    loadingThread.detach();

    do {
        window.clear(sf::Color::White);
        window.draw(splashScreenSprite);
        window.display();
        sf::Event event;
        Game::computeFrameTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::_gameState = Game::EXITING;
                return;
            }
        }
    } while (loading && window.isOpen());


}


