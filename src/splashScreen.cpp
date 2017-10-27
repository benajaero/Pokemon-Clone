#include "util.h"
#include "definitions.h"
#include "splashScreen.h"
#include <cassert>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void SplashScreen::Show(sf::RenderWindow& window) {
    sf::Texture raindiraTexture;
    sf::Texture phoboltTexture; 
    assert(raindiraTexture.loadFromFile("./assets/raindiraPaintedTransparent.png"));
    assert(phoboltTexture.loadFromFile("./assets/PhoboltTransparent.png"));
    
    sf::Sprite raindiraSprite;
    sf::Sprite phoboltSprite;
    raindiraSprite.setTexture(raindiraTexture);
    phoboltSprite.setTexture(phoboltTexture);

    raindiraSprite.setOrigin(1191 / 2, 902 / 2);
    phoboltSprite.setOrigin(1107 / 2, 1102 / 2);

    raindiraSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    phoboltSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    raindiraSprite.setScale(0.5, 0.5);
    phoboltSprite.setScale(0.5, 0.5);



    sf::Event event;
    while (true) {
        window.clear(sf::Color::White);
        window.draw(raindiraSprite);
        window.draw(phoboltSprite);
        window.display();
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
