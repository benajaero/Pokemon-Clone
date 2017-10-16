#include "pokemon.h"
#include "move.h"

#include <iostream>


// First thing is general functions: damage calculation, PP point deductions,

unsigned int calculateDamage(Pokemon attacker, Pokemon target, BattleMove move) {
    return 0;
}

void deductDamage(Pokemon attacker, Pokemon target, BattleMove move, unsigned int damage) {

}

void pokemonMoveNothing(Pokemon attacker, Pokemon target, BattleMove move) {
    std::cout << attacker.name << "charges";
}
