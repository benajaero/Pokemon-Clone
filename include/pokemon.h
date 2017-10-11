#ifndef POKEMON_H
#define POKEMON_H

#include "enums.h"
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
    unsigned int specialStat;
} PokemonValues;

//individual values range from 0x0 to 0xF
typedef struct IndividualValues {
    unsigned char healthPoints;
    unsigned char attackStat;
    unsigned char defenseStat;
    unsigned char speedStat;
    unsigned char specialStat;
} IndividualValues;

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
        
        float expPoints;
        unsigned int level;

        unsigned int pokemonNumber;
        std::string name;
        Gender gender;

        bool doesEvolve;
        std::string nextEvolution;
        unsigned int evolutionLevel;

        float battleAccuracy, evasionRate;

        //function declarations
        void generateIVs();
        void generateEVs(Pokemon faintedPokemon, Pokemon winningPokemon);
        void generateStats();

};

#endif
