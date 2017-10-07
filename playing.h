#ifndef PLAYING_H

#define PLAYING_H
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include "hero.h"
#include "AnimatedSprite.hpp"

class PlayController {
    private:
        sf::Texture playerTexture;
        AnimatedSprite sprite;
        //Hero hero;
    public:
        sf::View view;
        void logic(sf::Time frameTime);
        void handleEvents(sf::Event& event, sf::RenderWindow& window, sf::Time frameTime, sf::Clock frameClock);
        void draw(sf::RenderWindow& window, sf::Time frameTime, sf::Clock frameClock);
        void loadTextures();
        void setup(sf::RenderWindow& window);
        //PlayController() : hero("Adam", 0, 0, 0, 0, 0, EAST, 1) {}
    
};

#endif
