#ifndef MOVE_H
#define MOVE_H

#include <functional>
#include <vector>
#include <string>
//forward declaration
class Pokemon;


class BattleMove {
    private:
         
    public: 
        std::string name;
        float accuracy; // from 0 - 1
        unsigned int power;
        unsigned int powerPointsTotal, powerPointsLeft;
        
        std::function<void(Pokemon, Pokemon, BattleMove)> execute;
};

// --------------------------- FUNCTION DECLARATIONS --------------------------

unsigned int calculateDamage(Pokemon attacker, Pokemon target, BattleMove move);
void deductDamage(Pokemon attacker, Pokemon target, BattleMove move, unsigned int damage);


#endif
