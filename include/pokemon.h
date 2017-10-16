#ifndef POKEMON_H
#define POKEMON_H

#include "enums.h"
#include "move.h"
#include <string>
#include <vector>

/* 
 * Note: types will be in lower case
 */


// ---------------------------------- STRUCTS ---------------------------------

typedef struct GenderRatio {
    float male;
    float female;
} GenderRatio;

typedef struct PokemonValues {
    unsigned int healthPoints;
    unsigned int attackStat;
    unsigned int defenseStat;
    unsigned int speedStat;
    unsigned int specialAttackStat;
    unsigned int specialDefenseStat;
} PokemonValues;

typedef struct PokemonNature {
    std::string name;
    std::string increases;
    std::string decreases;
} PokemonNature;


typedef struct PokemonMetaData {
    float height;
    float catchRate; // This is from 0 - 100 represented as a float 0 - 1
    std::vector<std::string> eggGroups;
    float weight;
    int hatchSteps; // still researching egg cycles
    std::vector<std::string> possibleAbilities;
} PokemonMetaData;

typedef struct PokemonType {
    std::string name;
    std::vector<std::string> superEffective;
    std::vector<std::string> notVeryEffective;
    std::vector<std::string> notEffective;
} PokemonType;


// ---------------------------------- CLASSES ---------------------------------

class Pokemon {
    public:
        float healthPoints;
        std::string species;
        std::vector<PokemonType> types;
        std::string ability;

        PokemonValues baseValues;
        PokemonValues effortValues;
        PokemonValues individualValues;
        PokemonValues currentValues;
        PokemonValues battleValues;
        
        PokemonNature _nature;
        float expPoints;
        unsigned int level;

        //setup moves 
        BattleMove possibleMoves[4];
        std::vector<BattleMove> moveQueue;
        BattleMove struggle;

        unsigned int pokemonNumber;
        std::string name;
        Gender gender;

        bool doesEvolve;
        std::string nextEvolution;
        unsigned int evolutionLevel;

        float battleAccuracy, evasionRate;

        //function declarations
        void generateIVs();
        static void generateEVs(Pokemon faintedPokemon, Pokemon winningPokemon);
        void generateStats();

};


#endif
