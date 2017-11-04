#include "battle.h"
#include "game.h"
#include <SFML/Graphics.hpp>

// preturn and turn should be self-contained procedures rather than coroutines - I think that this is less complicated

void BattleController::preturn() {

}

void BattleController::turn() {

}

void BattleController::sort() {

}

void BattleController::loop() {
    while (!isExiting) {
        sf::Event event;
        while (Game::_mainWindow.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                Game::_mainWindow.close();
        }

        frameTime = frameClock.restart();
        draw();
    } 
}

void BattleController::draw() {
    Game::_mainWindow.clear(sf::Color::White);
    drawBackground();
    drawPokemon();
    drawOverlay();
    Game::_mainWindow.display();
}

void BattleController::SpriteInit() {
    sf::Sprite& background =  SpriteManager::newSprite("battleBackground");
    background.setTexture(TextureManager::getRef("PokemonBattleBackgroundNormal"));
}

void BattleController::drawOverlay() {
}

void BattleController::drawBackground() {
    Game::_mainWindow.draw(SpriteManager::getRef("battleBackground"));
}

void BattleController::drawPokemon() {

}
