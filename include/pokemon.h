#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

/* 
 * Note: types will be in lower case
 */

enum Gender {
    MALE,
    FEMALE
};

typedef struct GenderRatio {
    float male;
    float female;
} GenderRatio;

typedef struct EffortValues {
    public:
        float maxHP;
        float attackStat;
        float defenseStat;
        float speedStat;
        float specialAttackStat;
        float specialDefenseStat; 
} EffortValues;

typedef struct PokemonMetaData {
    float height;
    float catchRate; // This is from 0 - 100 represented as a float 0 - 1
    std::vector<std::string> eggGroups;
    float weight;
    int hatchSteps;
    std::vector<std::string> possibleAbilities;
} PokemonMetaData;

class Pokemon {
    public:
        //maxes
        float maxHP;
        float attackStat;
        float defenseStat;
        float speedStat;
        float specialAttackStat;
        float specialDefenseStat; 

        float healthPoints;
        std::string species;
        std::vector<std::string> types;
        std::string ability;

        EffortValues effortValues;
        float expPoints;

        int pokemonNumber;
        std::string name;
        Gender gender;

};


#endif
