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
        for (int i = 0; i < 3; i++) { buttons[i].setClicked(sf::Mouse::getPosition(win)); }
    }
    if (buttons[0].isClicked()) { controller.changeState(MainMenuController::TO_PLAYING); }
    
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
    //old code please ignore
    /*for (int i = 0; i < 3; i++) {
        //looks
        buttons[i].setBackgroundSize(sf::Vector2f(500, 132));
        buttons[i].setButtonFont(FontManager::getFont("Generica"));
        buttons[i].setTextSize(64);
        buttons[i].setRadius(27);
        sf::RoundedRectangleShape& background = buttons[i].getBackground(); 
        background.setFillColor(sf::Color(46, 111, 182));
        std::cout << "set color";
        background.setOutlineThickness(5);
        background.setOutlineColor(sf::Color(33, 56, 112));

        switch (i) {
            case 0:
                buttons[i].setText("New");
                buttons[i].setPosition(sf::Vector2f(710, 445));
                break;
            case 1:
                buttons[i].setText("Load");
                buttons[i].setPosition(sf::Vector2f(710, 620));
                break;
            case 2:
                buttons[i].setText("Options");
                buttons[i].setPosition(sf::Vector2f(710, 810));
                break;
            default:
                buttons[i].setText("New");
                buttons[i].setPosition(sf::Vector2f(710, 445));
                break;
        }
        //position
        //function states and that 
    }*/

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
                Game::_gameState = Game::PLAYING;
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
