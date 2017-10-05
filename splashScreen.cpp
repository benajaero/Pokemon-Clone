#include "splashScreen.h"
#include <cassert>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void SplashScreen::Show(sf::RenderWindow& window) {
    sf::Texture texture;
    
    assert(texture.loadFromFile("./assets/Title Screen.png"));

    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();

    sf::Event event;
    bool condition = true;
    while (window.pollEvent(event) && condition) {
        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed) {
            std::cout << "Closing window";
            window.clear(sf::Color::White);
            condition = false;
        }
    }
        
}
