#ifndef SPLASH_SCREEN
#define SPLASH_SCREEN

#include "game.h"
#include <SFML/Graphics.hpp>
class Game;

class SplashScreen {
    private: 
    public:
        static bool loading;        
        void Show(sf::RenderWindow& window);
};

#endif
