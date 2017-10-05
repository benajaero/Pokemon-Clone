#ifndef HERO_H
#define HERO_H

#include "util.h"
#include "SFML/Graphics.hpp"

class Hero : public Person {
    private:

    public:
        bool upgraded;
        bool isMoving;

        Hero(std::string pname, double px, double py, double pz, double pxvel, double pyvel, Orientation dir, int layerr) : Person(pname, px, py, pz, pxvel, pyvel, dir, layerr) {}

        void changeOrientation(Orientation newDir);
        void moveForward(double movementDamper, sf::View& view);
};

#endif
