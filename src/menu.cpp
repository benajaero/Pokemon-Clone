#include "menu.h"

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
   window.display();
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
