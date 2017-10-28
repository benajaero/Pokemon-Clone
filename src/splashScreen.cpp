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

void Load() {
    while (true) {}
    SplashScreen::loading = false;
    Game::_gameState = Game::SHOWING_MENU;
}

void SplashScreen::Show(sf::RenderWindow& window) {

    sf::Sprite splashScreenSprite;
    splashScreenSprite.setTexture(TextureManager::getRef("splashScreenBackground"));


    loading = true; 

    std::thread loadingThread(Load);
    loadingThread.detach();

    while (loading) {
        
        window.clear(sf::Color::White);
        window.draw(splashScreenSprite);
        window.display();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::_gameState = Game::EXITING;
                return;
            }
        }
    }


}


