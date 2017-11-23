#include "game.h"
#include "texturemanager.h"
#include "splashScreen.h"
#include "battle.h"
#include "definitions.h"
#include <cassert>

Game::GameState Game::_gameState = Game::UNINITIALIZED;
sf::RenderWindow Game::_mainWindow;
sf::Time Game::frameTime;
sf::Clock Game::frameClock;
Hero Game::hero("Tim", 55, 60, 0, 0, 0, EAST, 1);
//tmx::TileMap Game::_map("./assets/assets/desert.tmx");
PlayController Game::pController = PlayController();

void Game::Start(void) {
    if (_gameState != Game::UNINITIALIZED)
        return;

    _mainWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Pokemon: Thunder and Lightning", sf::Style::Default);
    _mainWindow.setFramerateLimit(60);
     
    //load initial textures
    TextureManager::loadTexture("splashScreenBackground", "assets/SplashScreen.png");
    pController.setup(_mainWindow);
    _gameState = Game::SHOWING_SPLASH;

    while(!IsExiting())
        GameLoop();
    _mainWindow.close();
}

bool Game::IsExiting() { return (_gameState == Game::EXITING); }

void Game::GameLoop() {
    if (_gameState == Game::SHOWING_SPLASH) 
        ShowSplash();
    if (_gameState == Game::SHOWING_MENU)
        Menu();
    else if (_gameState == Game::BATTLING) {
        Pokemon pokemon;
        BattleController bController(&hero, pokemon);
        bController.loop();
    }
    else {
        if (_gameState == Game::PLAYING) {
            pController.handleEvents(_mainWindow);
            pController.logic();
            pController.draw(_mainWindow);
        } else {
            sf::Event event;
            while(_mainWindow.pollEvent(event)) {
                computeFrameTime();
                if (event.type == sf::Event::Closed)
                    _gameState = Game::EXITING;
            }
        }
    }

}

void Game::computeFrameTime() {
    Game::frameTime = Game::frameClock.restart();
}

void Game::Menu() {
    MainMenuController mainMenuController;
    mainMenuController.loop(_mainWindow);    
}

void Game::ShowSplash() {
    SplashScreen splash;
    splash.Show(_mainWindow);
    TextureManager::deleteTexture("splashScreenBackground");
    _gameState = Game::SHOWING_MENU;
}


