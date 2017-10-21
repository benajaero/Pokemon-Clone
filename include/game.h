#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "playing.h"
#include "hero.h"


class Game {
    private:
        static bool IsExiting();
        static void GameLoop();
        static void ShowSplash();

    public:
        enum GameState {
            UNINITIALIZED,
            SHOWING_SPLASH,
            PAUSED,
            SHOWING_MENU,
            PLAYING,
            BATTLING,
            EXITING,
            LOADING
        };

        static void Start();
        static Hero hero;
        static sf::Time frameTime;
        static sf::Clock frameClock;
        static PlayController pController;
        static GameState _gameState;
        static sf::RenderWindow _mainWindow;

};

#endif
