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
class MainMenuController;
class OverviewMenu {
    private:
        GuiButton buttons[5];
    public:
        //init sprite creation and so forth
        OverviewMenu() {
            sf::Texture& texture = TextureManager::loadTexture("overviewBackground", "assets/PokemonTitleScreenBackground.png");
            sf::Sprite& sprite = SpriteManager::newSprite("overviewBackground");
            sprite.setTexture(texture);
            sprite.setPosition(0, 0);
            buttonSetup();
        }
        //sprite deletion
        ~OverviewMenu() {
            SpriteManager::deleteSprite("overviewBackground");
            TextureManager::deleteTexture("overviewBackground");
        }

        void buttonSetup();
        void handleEvents(sf::Event evt, sf::RenderWindow& win, MainMenuController& controller);
        void draw(sf::RenderWindow& window);
};

class OrientationMenu {

};

class MainMenuController {
    private:
        OverviewMenu overviewMenu;
        OrientationMenu orientationMenu;
    public:
        enum MenuState {
            OVERVIEW,
            NEW,
            LOAD,
            OPTIONS,
            TO_PLAYING,
            TO_ORIENTATION
        };
        MenuState prevState;
        MenuState menuState;
        MainMenuController() {
            prevState = OVERVIEW;
            menuState = OVERVIEW;
        }
        MainMenuController(MenuState initialState) : menuState(initialState), prevState(initialState) {}
        void handleEvents(sf::Event evt, sf::RenderWindow& win);
        void draw(sf::RenderWindow& window);
        void loop(sf::RenderWindow& window);
        void changeState(MenuState state);
};

class OverworldOverlay : public sf::Drawable {
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
    public:
        enum MenuState {
            SHOWING_POKEMON_LIST,
            SHOWING_ONE_POKEMON,
            SHOWING_BAG,
            DISPLAY_OVERLAY_BUTTONS,
            SHOWING_POKEDEX,
        };


};

class ContextMenuController {

};

#endif
