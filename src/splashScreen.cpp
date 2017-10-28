#include "splashScreen.h"
#include "util.h"
#include "definitions.h"
#include "texturemanager.h"
#include <cassert>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void SplashScreen::Show(sf::RenderWindow& window) {

    sf::Sprite splashScreenSprite;
    splashScreenSprite.setTexture(TextureManager::getRef("splashScreenBackground"));

    window.clear(sf::Color::White);
    window.draw(splashScreenSprite);
    window.display();
    bool loading = true; 
    while (loading) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::_gameState = Game::EXITING;
                return;
            }
        }
    }


}


