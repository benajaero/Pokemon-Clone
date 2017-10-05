#include "game.h"

void Game::Start(void) {
    if (_gameState != Game::UNINITIALIZED)
        return;
    _mainWindow.create(sf::VideoMode(1920, 1080), "Pokemon: Thunder and Lightning");
    _gameState = Game::PLAYING;

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
    sf::Event event;
    while(_mainWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _gameState = Game::EXITING;

        else if (_gameState == Game::PLAYING) {

        }
        else if (_gameState == Game::BATTLING) {

        }
        
    }
}

Game::GameState Game::_gameState = Game::UNINITIALIZED;
sf::RenderWindow Game::_mainWindow;

