#include "menu.h"
#include "font_manager.h"
#include "spritemanager.h"
#include <iostream>

void MainMenuController::handleEvents(sf::Event evt, sf::RenderWindow& win) {
    if (menuState == OVERVIEW) overviewMenu.handleEvents(evt, win, *this);
}

void MainMenuController::draw(sf::RenderWindow& window) {
    if (menuState == OVERVIEW) overviewMenu.draw(window);
}

void OverviewMenu::handleEvents(sf::Event evt, sf::RenderWindow& win, MainMenuController& controller) {
    if (evt.type == sf::Event::MouseButtonPressed) {
        for (int i = 0; i < 3; i++) { 
            sf::Vector2i mousePos = sf::Mouse::getPosition(win);
            buttons[i].setClicked(win.mapPixelToCoords(mousePos));
        }
    }
    if (buttons[0].isClicked()) { 
        controller.changeState(MainMenuController::TO_ORIENTATION);
    }
    
}

void OverviewMenu::draw(sf::RenderWindow& window) {
   window.clear(sf::Color::White);
   
   window.draw(SpriteManager::getRef("overviewBackground"));
   for (int i = 0; i < 3; i++) {
       buttons[i].draw(window);
   }
   window.display();
}

void OverviewMenu::buttonSetup() {

    buttons[0].textureInit();
    buttons[0].newSprite("NewButton");
    buttons[1].newSprite("LoadButton");
    buttons[2].newSprite("OptionsButton");
    buttons[0].getSprite().setPosition(710, 445);
    buttons[1].getSprite().setPosition(710, 620);
    buttons[2].getSprite().setPosition(710, 810);
}

void MainMenuController::loop(sf::RenderWindow& window) {
    bool showMenu = true;
    while (showMenu) {
        sf::Event event;
        Game::computeFrameTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::_gameState = Game::EXITING;
                return;
            }
            if (menuState == TO_PLAYING) {
                Game::_gameState = Game::PLAYING;
                return;
            }
            else if (menuState == TO_ORIENTATION) {
                Game::_gameState = Game::BATTLING;
                return;
            }
            handleEvents(event, window);
        }
        draw(window);
    }
}

void MainMenuController::changeState(MenuState state) {
    prevState = menuState;
    menuState = state;
}
