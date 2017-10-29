#ifndef PLAYING_H
#define PLAYING_H

#include "hero.h"
#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class PlayController {
    private:
        sf::Texture playerTexture;
        //Hero hero;
    public:
        sf::View view;
        void logic();
        void handleEvents(sf::Event& event, sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void setup(sf::RenderWindow& window);
        //PlayController() : hero("Adam", 0, 0, 0, 0, 0, EAST, 1) {}
    
};

#endif
