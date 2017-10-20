#include "splashScreen.h"
#include <cassert>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.h"

void SplashScreen::Show(sf::RenderWindow& window) {
    sf::Texture texture;
    
    assert(texture.loadFromFile("./assets/Title Screen.png"));
    std::cout << std::endl;
    std::cout << "Setting sprite";
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::_gameState = Game::EXITING;
                return;
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << "Closing window";
                window.clear(sf::Color::White);
                window.display();
                return;
            }

        }
    }


}

void SplashScreen::chooseGender(sf::RenderWindow& window) {
    sf::Texture texture;
    
    assert(texture.loadFromFile("./assets/titlescreen-back.png"));
    sf::Sprite sprite;

    sprite.setTexture(texture);

    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.display();
    

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            
        }
    }
}
