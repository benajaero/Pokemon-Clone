#ifndef BATTLE_H
#define BATTLE_H

#include "enums.h"
#include "pokemon.h"
#include "hero.h"
#include "util.h"
#include "spritemanager.h"
#include "texturemanager.h"
#include "font_manager.h"
#include <SFML/Graphics.hpp>
#include <vector>

/* This will be almost like a standalone game
 * It will take in a set of options, data from playing controller or another controller
 * It will play then report data back after playing
 * Backlog: Multiplayer as well as dialogue inside of battle
 */

/* 
 * Specification:
 * Battle: A scenario where teams of varying sizes fight until ALL pokemon on team have a HP of 0 (fainted),
 * Battle Controller - Controls Battle Flow
 * Preturn (Buffs, status conditions, Show usable moves (if none, then add struggle))
 * Turn
 * Sort attacks based on speed and quick attack
 * End Turn
 */

/* IDEA: POKEMON SHOULD BE ABLE TO APPLY POISON TO OTHER POKEMON */
// Should there be a generic battle controller for all types of battles or a separate battle controller for doubles singles and so on;

class BattleController {
    private:
        sf::Time frameTime;
        sf::Clock frameClock; 
        BattleType battleType;
        Pokemon _wildPokemon;
        bool isExiting = false;
        Hero* _hero = NULL;
        Person* _person = NULL;

        
    public:
        enum BattleState {
            PRETURN,
            TURN
        };
        BattleController(Hero* hero, Person* person) {
            _hero = hero; 
            _person = person;
            battleType = TRAINER;
            SpriteInit();
        }

        BattleController(Hero* hero, Person* person, BattleType type) {
            _hero = hero; 
            _person = person;
            battleType = type;
            SpriteInit();
        }

        BattleController(Hero* hero, Pokemon wildPokemon) {
            _hero = hero;
            _wildPokemon = wildPokemon;
            battleType = WILD;
            SpriteInit();
        }

        ~BattleController() {
            //cleanup
            SpriteManager::deleteSprite("battleBackground");
        }

        void preturn();
        void turn();
        void sort();
        void loop();
        void draw();
        void drawOverlay();
        void drawBackground();
        void drawPokemon();
        void SpriteInit();
};

#endif
