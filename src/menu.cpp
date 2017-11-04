#include "menu.h"
#include "font_manager.h"

void MainMenuController::handleEvents(sf::Event evt) {
    if (menuState == OVERVIEW) overviewMenu.handleEvents(evt);
}

void MainMenuController::draw(sf::RenderWindow& window) {
    if (menuState == OVERVIEW) overviewMenu.draw(window);
}

void OverviewMenu::handleEvents(sf::Event evt) {

}

void OverviewMenu::draw(sf::RenderWindow& window) {
   window.clear(sf::Color::White);
   window.draw(SpriteManager::getRef("overviewBackground"));
   //buttons[0].draw(window);
   window.display();
}

void OverviewMenu::buttonSetup() {
    for (int i = 0; i < 3; i++) {
        //looks
        buttons[i].setBackgroundSize(sf::Vector2f(500, 132));
        buttons[i].setButtonFont(FontManager::getFont("Generica"));
        buttons[i].setTextSize(64);
        buttons[i].setRadius(27);
        sf::RoundedRectangleShape& background = buttons[i].getBackground(); 
        background.setFillColor(sf::Color(46, 111, 182));
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
        }
        //position
        //function states and that 
    }
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
            handleEvents(event);
        }
        draw(window);
    }
}
