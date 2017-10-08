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
        //Hero hero;
    public:
        sf::View view;
        void logic();
        void handleEvents(sf::Event& event, sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void loadTextures();
        void setup(sf::RenderWindow& window);
        //PlayController() : hero("Adam", 0, 0, 0, 0, 0, EAST, 1) {}
    
};

#endif
