#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <string>
//forward declaration
class Pokemon;

class BattleMove {
    private:
         
    public: 
        std::string name;
        float accuracy; // from 0 - 1
        float recoil;
        unsigned int power;
         
        unsigned int powerPointsTotal, powerPointsLeft;

        void execute(Pokemon& attacker, std::vector<Pokemon>& targets);
};

#endif
