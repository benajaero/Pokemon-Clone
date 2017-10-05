#include "hero.h"

void Hero::changeOrientation(Orientation newDir) {
    direction = newDir;
}

void Hero::moveForward(double movementDamper, sf::View& view) {
    yvel *= movementDamper;
    xvel *= movementDamper;
    x += xvel;
    y += yvel;
    view.move(xvel, yvel);
}
