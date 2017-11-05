#include "hero.h"

void Hero::changeOrientation(Orientation newDir) {
    direction = newDir;
}

void Hero::moveForward(double movementDamper, sf::View& view, sf::Time frameTime) {
    yvel *= movementDamper;
    xvel *= movementDamper;
    //if ((xvel > 0.1f && xvel < -0.1f) || (yvel > 0.1f && yvel < -0.1f) )
    //   isMoving = false;
    x += xvel * frameTime.asSeconds();
    y += yvel * frameTime.asSeconds();
    view.move(xvel * frameTime.asSeconds(), yvel * frameTime.asSeconds());
}

void Hero::setupAnimations(sf::Texture& texture) {

// ------------------------------ WALK ANIMATIONS -----------------------------

    walk.up.setSpriteSheet(texture);
    walk.up.addFrame(sf::IntRect(16, 407, 17, 26));
    walk.up.addFrame(sf::IntRect(36, 407, 17, 23));
    walk.up.addFrame(sf::IntRect(56, 407, 17, 26));
    walk.up.addFrame(sf::IntRect(36, 407, 17, 23));

    walk.left.setSpriteSheet(texture);
    walk.left.addFrame(sf::IntRect(11, 378, 20, 24));
    walk.left.addFrame(sf::IntRect(34, 378, 20, 24));
    walk.left.addFrame(sf::IntRect(57, 378, 20, 25));
    walk.left.addFrame(sf::IntRect(34, 378, 20, 24));

    walk.right.setSpriteSheet(texture);
    walk.right.addFrame(sf::IntRect(57, 435, 20, 25));
    walk.right.addFrame(sf::IntRect(34, 435, 20, 24));
    walk.right.addFrame(sf::IntRect(11, 435, 20, 24));
    walk.right.addFrame(sf::IntRect(34, 435, 20, 24));

    walk.down.setSpriteSheet(texture);
    walk.down.addFrame(sf::IntRect(16, 350, 18, 26));
    walk.down.addFrame(sf::IntRect(38, 350, 17, 24));
    walk.down.addFrame(sf::IntRect(55, 350, 17, 26));
    walk.down.addFrame(sf::IntRect(38, 350, 17, 24));
    
// ------------------------------ IDLE ANIMATIONS -----------------------------

    idle.up.setSpriteSheet(texture);
    idle.down.setSpriteSheet(texture);
    idle.right.setSpriteSheet(texture);
    idle.left.setSpriteSheet(texture);

    idle.up.addFrame(sf::IntRect(36, 407, 17, 23));
    idle.down.addFrame(sf::IntRect(38, 350, 17, 24));
    idle.right.addFrame(sf::IntRect(34, 435, 20, 24));
    idle.left.addFrame(sf::IntRect(34, 378, 20, 24));

}
