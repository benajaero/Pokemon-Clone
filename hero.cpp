#include "hero.h"

void Hero::changeOrientation(Orientation newDir) {
    direction = newDir;
}

void Hero::moveForward(double movementDamper) {
    yvel *= movementDamper;
    xvel *= movementDamper;
    x += xvel;
    y += yvel;
}
