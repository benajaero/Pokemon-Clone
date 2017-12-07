#ifndef GAME_H
#define GAME_H

#include "menu.h"
#include "playing.h"
#include "hero.h"
#include <tmx/MapLoader.hpp>
#include <cassert>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Game {
    private:
        static bool IsExiting();
        static void GameLoop(tmx::MapLoader& _map);
        static void ShowSplash();
        static void Menu();

    public:
        enum GameState {
            UNINITIALIZED,
            SHOWING_SPLASH,
            PAUSED,
            SHOWING_MENU,
            PLAYING,
            BATTLING,
            EXITING,
        };
        
        static Hero hero;
        static sf::Time frameTime;
        static sf::Clock frameClock;
        static PlayController pController;
        static GameState _gameState;
        static sf::RenderWindow _mainWindow;

        static void Start();
        static void computeFrameTime();

};

#endif
