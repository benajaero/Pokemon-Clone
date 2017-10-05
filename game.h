#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game {
    private:
        static bool IsExiting();
        static void GameLoop();

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

    public:
        static void Start();

};

#endif
