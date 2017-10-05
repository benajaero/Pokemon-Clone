#include "game.h"
#include "splashScreen.h"

void Game::Start(void) {
    if (_gameState != Game::UNINITIALIZED)
        return;
    _mainWindow.create(sf::VideoMode(1920, 1080), "Pokemon: Thunder and Lightning");
    pController.setup();
    pController.loadTextures();
    _gameState = Game::SHOWING_SPLASH;

    while(!IsExiting())
        GameLoop();
    _mainWindow.close();
}

bool Game::IsExiting() {
    if (_gameState == Game::EXITING)
        return true;
    else
        return false;
}

void Game::GameLoop() {
    if (_gameState == Game::SHOWING_SPLASH) 
        ShowSplash();
    else {
        sf::Event event;
        while(_mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _gameState = Game::EXITING;
            else if (_gameState == Game::PLAYING) {
                pController.logic();
                pController.handleEvents(event, _mainWindow);
            }
            else if (_gameState == Game::BATTLING) {

            }

        }
    }

}

void Game::ShowSplash() {
    SplashScreen splash;
    splash.Show(_mainWindow);
    _gameState = Game::PLAYING;
}

Game::GameState Game::_gameState = Game::UNINITIALIZED;
sf::RenderWindow Game::_mainWindow;
PlayController Game::pController = PlayController();
