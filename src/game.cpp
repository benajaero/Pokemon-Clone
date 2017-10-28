#include "game.h"
#include "texturemanager.h"
#include "splashScreen.h"
#include "battle.h"
#include "definitions.h"
#include <cassert>

void Game::Start(void) {
    if (_gameState != Game::UNINITIALIZED)
        return;

    _mainWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Pokemon: Thunder and Lightning", sf::Style::Default);
    _mainWindow.setVerticalSyncEnabled(true);
     
    //load initial textures
    TextureManager::loadTexture("splashScreenBackground", "./assets/SplashScreen.png");
    pController.setup(_mainWindow);
    pController.loadTextures();
    _gameState = Game::SHOWING_SPLASH;

    while(!IsExiting())
        GameLoop();
    _mainWindow.close();
}

bool Game::IsExiting() { return (_gameState == Game::EXITING); }

void Game::GameLoop() {
    if (_gameState == Game::SHOWING_SPLASH) 
        ShowSplash();
    else if (_gameState == Game::SHOWING_MENU)
        Menu();
    else if (_gameState == Game::BATTLING) {
        Pokemon pokemon;
        BattleController bController(&hero, pokemon);
        bController.loop();
    }
    else {
        sf::Event event;
        while(_mainWindow.pollEvent(event)) {
            Game::frameTime = Game::frameClock.restart();
            if (event.type == sf::Event::Closed)
                _gameState = Game::EXITING;
            else if (_gameState == Game::PLAYING) {
                pController.logic();
                pController.handleEvents(event, _mainWindow);
            }
            

        }
    }

}

void Game::Menu() {

}

void Game::ShowSplash() {
    SplashScreen splash;
    splash.Show(_mainWindow);
    TextureManager::deleteTexture("splashScreenBackground");
    _gameState = Game::PLAYING;
}

Game::GameState Game::_gameState = Game::UNINITIALIZED;
sf::RenderWindow Game::_mainWindow;
sf::Time Game::frameTime;
sf::Clock Game::frameClock;
Hero Game::hero("Adam", 0, 0, 0, 0, 0, EAST, 1);
PlayController Game::pController = PlayController();

