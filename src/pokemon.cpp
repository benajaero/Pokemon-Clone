#include "pokemon.h"
#include <string>
#include <random> 
#include <cmath>


void Pokemon::generateIVs() {
    std::random_device rd;
    std::default_random_engine rng;
    std::uniform_int_distribution<int> distribution(0, 31);

    individualValues.attackStat = distribution(rng);
    individualValues.defenseStat = distribution(rng);
    individualValues.speedStat = distribution(rng);
    individualValues.specialStat = distribution(rng);
    individualValues.healthPoints = distribution(rng); 
    //individualValues.healthPoints = ((individualValues.attackStat & 0x1) << 3) + ((individualValues.defenseStat & 0x1) << 2) + ((individualValues.speedStat & 0x1) << 1) + (individualValues.specialStat & 0x1);

}              

void Pokemon::generateEVs(Pokemon faintedPokemon, Pokemon winningPokemon) {

    winningPokemon.effortValues.healthPoints += faintedPokemon.baseValues.healthPoints;
    winningPokemon.effortValues.specialStat += faintedPokemon.baseValues.specialStat;
    winningPokemon.effortValues.attackStat += faintedPokemon.baseValues.attackStat;
    winningPokemon.effortValues.defenseStat += faintedPokemon.baseValues.defenseStat;
    winningPokemon.effortValues.speedStat += faintedPokemon.baseValues.speedStat;

    winningPokemon.generateStats();
}

void generalStatCalculator(unsigned int& stat, unsigned int baseVal, unsigned int level, unsigned int evVal, unsigned int ivVal, std::string name, PokemonNature nature) {
    stat = (((baseVal * 2) + ivVal + ((evVal == 0 ? 0 : evVal / 4)) * level)) / 100 + 5;    
    if (name == nature.increases)
        stat *= 1.1;
    else if (name == nature.decreases)    
        stat *= 0.9; 
}

void Pokemon::generateStats() {
    //health is calculated differently; See: https://bulbapedia.bulbagarden.net/wiki/Statistic 
    
    generalStatCalculator(currentValues.attackStat, baseValues.attackStat, level, effortValues.attackStat, individualValues.attackStat, "attack", _nature);
    generalStatCalculator(currentValues.defenseStat, baseValues.defenseStat, level, effortValues.defenseStat, individualValues.defenseStat, "defense", _nature);
    generalStatCalculator(currentValues.speedStat, baseValues.speedStat, level, effortValues.speedStat, individualValues.speedStat, "speed", _nature);
    generalStatCalculator(currentValues.specialStat, baseValues.specialStat, level, effortValues.specialStat, individualValues.specialStat, "special", _nature);

    currentValues.healthPoints = (((baseValues.healthPoints * 2) + individualValues.healthPoints + ((effortValues.healthPoints == 0 ? 0 : effortValues.healthPoints / 4)) * level)) / 100 + level + 10;     
}
