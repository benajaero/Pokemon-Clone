#ifndef SPLASH_SCREEN
#define SPLASH_SCREEN

#include "game.h"
#include <SFML/Graphics.hpp>
class Game;

class SplashScreen {
    private: 

    public:
        void Show(sf::RenderWindow& window);
        void showMenu(sf::RenderWindow& window);
        void chooseGender(sf::RenderWindow& window);
};

#endif
