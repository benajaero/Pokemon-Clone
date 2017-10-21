#include "battle.h"
#include "game.h"
#include "imgui.h"
#include "imgui-SFML.h"
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
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                Game::_mainWindow.close();
        }

        frameTime = frameClock.restart();
        draw();
    } 
}

void BattleController::draw() {
    drawBackground();
    drawPokemon();
    drawOverlay();
    Game::_mainWindow.clear(sf::Color::White);
    ImGui::SFML::Render(Game::_mainWindow);
    Game::_mainWindow.display();
}

void BattleController::drawOverlay() {
    ImGui::SFML::Update(Game::_mainWindow, frameTime);
    ImGui::Begin("BATTLE");

    if(ImGui::Button("Test Button"))
        ;
    ImGui::End();
}

void BattleController::drawBackground() {

}

void BattleController::drawPokemon() {

}
