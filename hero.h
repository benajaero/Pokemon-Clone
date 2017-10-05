#ifndef HERO_H
#define HERO_H

#include "util.h"

class Hero : public Person {
    private:

    public:
        bool upgraded;
        bool isMoving;

        Hero(std::string pname, double px, double py, double pz, double pxvel, double pyvel, Orientation dir, int layerr, bool pupgraded) : Person(pname, px, py, pz, pxvel, pyvel, dir, layerr), upgraded(pupgraded) {}

        void changeOrientation(Orientation newDir);
        void moveForward(double movementDamper);
};

#endif
