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
    awayPlatform.setTexture(TextureManager::getRef("PokemonBattlePlatformsOriginal"));
    homePlatform.setTexture(TextureManager::getRef("PokemonBattlePlatformsOriginal"));
    homePlatform.setScale(SCALE, SCALE);
    awayPlatform.setScale(SCALE, SCALE);
    homePlatform.setPosition(2, 700);
    awayPlatform.setPosition(1400, 400);

    std::cout << "got this far\n";
    changeWeather(Game::biome);
}

void BattleController::drawOverlay() {
}

void BattleController::drawBackground() {
    Game::_mainWindow.draw(SpriteManager::getRef("battleBackground"));
    Game::_mainWindow.draw(homePlatform);
    Game::_mainWindow.draw(awayPlatform);
}

void BattleController::drawPokemon() {

}

void BattleController::changeWeather(std::string newWeather) {
    std::string homeString = "PokemonBattlePlatformHome";
    homeString += newWeather;    
    std::string awayString = "PokemonBattlePlatformAway";
    awayString += newWeather;    
    std::cout << "Here we are: " << newWeather << " : " << homeString << "\n" ;
    homePlatform.setTextureRect(GeneralManager::getIntRect(homeString));
    awayPlatform.setTextureRect(GeneralManager::getIntRect(awayString));
}
