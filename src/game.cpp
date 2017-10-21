#include "game.h"
#include "splashScreen.h"
#include "battle.h"

#include "imgui.h"
#include "imgui-SFML.h"


void Game::Start(void) {
    if (_gameState != Game::UNINITIALIZED)
        return;
    _mainWindow.create(sf::VideoMode(1920, 1080), "Pokemon: Thunder and Lightning");
    _mainWindow.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(_mainWindow);
     
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

void Game::ShowSplash() {
    SplashScreen splash;
    splash.Show(_mainWindow);
    //splash.chooseGender(_mainWindow);
    _gameState = Game::BATTLING;
}

Game::GameState Game::_gameState = Game::UNINITIALIZED;
sf::RenderWindow Game::_mainWindow;
sf::Time Game::frameTime;
sf::Clock Game::frameClock;
Hero Game::hero("Adam", 0, 0, 0, 0, 0, EAST, 1);
PlayController Game::pController = PlayController();

