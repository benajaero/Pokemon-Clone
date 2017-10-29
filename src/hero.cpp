#include "hero.h"

void Hero::changeOrientation(Orientation newDir) {
    direction = newDir;
}

void Hero::moveForward(double movementDamper, sf::View& view, sf::Time frameTime) {
    yvel *= movementDamper;
    xvel *= movementDamper;
    if ((xvel > 0.1f && xvel < -0.1f) || (yvel > 0.1f && yvel < -0.1f) )
       isMoving = false;
    x += xvel * frameTime.asSeconds();
    y += yvel * frameTime.asSeconds();
    view.move(xvel * frameTime.asSeconds(), yvel * frameTime.asSeconds());
}

void Hero::setupAnimations(sf::Texture& texture) {

// ------------------------------ WALK ANIMATIONS -----------------------------

    walk.up.setSpriteSheet(texture);
    walk.up.addFrame(sf::IntRect(235, 37, 17, 23));
    walk.up.addFrame(sf::IntRect(270, 36, 17, 25));
    walk.up.addFrame(sf::IntRect(305, 36, 17, 25));

    walk.left.setSpriteSheet(texture);
    walk.left.addFrame(sf::IntRect(340, 37, 17, 23));
    walk.left.addFrame(sf::IntRect(375, 36, 17, 24));
    walk.left.addFrame(sf::IntRect(410, 36, 17, 23));

    walk.right.setSpriteSheet(texture);
    walk.right.addFrame(sf::IntRect(131, 37, 17, 23));
    walk.right.addFrame(sf::IntRect(165, 36, 17, 25));
    walk.right.addFrame(sf::IntRect(200, 36, 17, 25));

    walk.down.setSpriteSheet(texture);
    walk.down.addFrame(sf::IntRect(25, 37, 17, 23));
    walk.down.addFrame(sf::IntRect(60, 36, 17, 25));
    walk.down.addFrame(sf::IntRect(95, 36, 17, 25));
    
// ------------------------------ IDLE ANIMATIONS -----------------------------

    idle.up.setSpriteSheet(texture);
    idle.down.setSpriteSheet(texture);
    idle.right.setSpriteSheet(texture);
    idle.left.setSpriteSheet(texture);

    idle.up.addFrame(sf::IntRect(235, 37, 17, 23));
    idle.down.addFrame(sf::IntRect(25, 37, 17, 23));
    idle.right.addFrame(sf::IntRect(131, 37, 17, 23));
    idle.left.addFrame(sf::IntRect(340, 37, 17, 23));


}
