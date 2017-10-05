#ifndef PLAYING_H

#define PLAYING_H
#include <SFML/Graphics.hpp>
#include "hero.h"

class PlayController {
    private:
        sf::Texture playerTexture;
        Hero hero;
    public:
        sf::View view;
        void logic();
        void handleEvents(sf::Event& event, sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void loadTextures();
        void setup();
        PlayController() : hero("Adam", 0, 0, 0, 0, 0, EAST, 1){}
};

#endif
