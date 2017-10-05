#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "playing.h"

class Game {
    private:
        static bool IsExiting();
        static void GameLoop();
        static void ShowSplash();

        enum GameState {
            UNINITIALIZED,
            SHOWING_SPLASH,
            PAUSED,
            SHOWING_MENU,
            PLAYING,
            BATTLING,
            EXITING
        };

        static GameState _gameState;
        static sf::RenderWindow _mainWindow;
        static PlayController pController;


    public:
        static void Start();

};

#endif
