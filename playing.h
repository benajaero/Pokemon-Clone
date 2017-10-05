#ifndef PLAYING_H
#define PLAYING_H
#include <SFML/Graphics.hpp>

class PlayController {
    private:

    public:
        void logic();
        void handleEvents(sf::Event& event, sf::RenderWindow& window);
        void draw(sf::RenderWindow& window);
        void loadTextures();
};

#endif
