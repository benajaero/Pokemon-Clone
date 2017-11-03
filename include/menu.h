#ifndef MENU_H
#define MENU_H

#include "gui-components.h"
#include "texturemanager.h"
#include "spritemanager.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

class Game;
class OverviewMenu {
    private:

    public:
        //init sprite creation and so forth
        OverviewMenu() {
            sf::Texture& texture = TextureManager::loadTexture("overviewBackground", "assets/PokemonTitleScreenBackground.png");
            sf::Sprite& sprite = SpriteManager::newSprite("overviewBackground");
            sprite.setTexture(texture);
            sprite.setPosition(0, 0);
        }
        //sprite deletion
        ~OverviewMenu() {
            SpriteManager::deleteSprite("overviewBackground");
            TextureManager::deleteTexture("overviewBackground");
        }

        void buttonSetup();
        void handleEvents(sf::Event evt);
        void draw(sf::RenderWindow& window);
};

class NewMenu {

};

class MainMenuController {
    private:
        OverviewMenu overviewMenu;
    public:
        enum MenuState {
            OVERVIEW,
            NEW,
            LOAD,
            OPTIONS
        };
        MenuState prevState;
        MenuState menuState;
        MainMenuController() {
            prevState = OVERVIEW;
            menuState = OVERVIEW;
        }
        MainMenuController(MenuState initialState) : menuState(initialState), prevState(initialState) {}
        void handleEvents(sf::Event evt);
        void draw(sf::RenderWindow& window);
        void loop(sf::RenderWindow& window);
};

class ContextMenuController {

};

#endif
