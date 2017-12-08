#include "hero.h"

void Hero::changeOrientation(Orientation newDir) {
    direction = newDir;
}

void Hero::moveForward(double movementDamper, sf::View& view, sf::Time frameTime) {
    yvel *= movementDamper;
    xvel *= movementDamper;
    //if ((xvel > 0.1f && xvel < -0.1f) && (yvel > 0.1f && yvel < -0.1f) )
       //isMoving = false;
    x += xvel * frameTime.asSeconds();
    y += yvel * frameTime.asSeconds();
    view.move(xvel * frameTime.asSeconds() , yvel * frameTime.asSeconds());
}

void Hero::setupAnimations(sf::Texture& texture) {

// ------------------------------ WALK ANIMATIONS -----------------------------

    CostumeSet rocket;
    rocket.walk.up.setSpriteSheet(texture);
    rocket.walk.up.addFrame(sf::IntRect(16, 407, 17, 26));
    rocket.walk.up.addFrame(sf::IntRect(36, 407, 17, 23));
    rocket.walk.up.addFrame(sf::IntRect(56, 407, 17, 26));
    rocket.walk.up.addFrame(sf::IntRect(36, 407, 17, 23));

    rocket.walk.left.setSpriteSheet(texture);
    rocket.walk.left.addFrame(sf::IntRect(11, 378, 20, 24));
    rocket.walk.left.addFrame(sf::IntRect(34, 378, 20, 24));
    rocket.walk.left.addFrame(sf::IntRect(57, 378, 20, 25));
    rocket.walk.left.addFrame(sf::IntRect(34, 378, 20, 24));

    rocket.walk.right.setSpriteSheet(texture);
    rocket.walk.right.addFrame(sf::IntRect(57, 435, 20, 25));
    rocket.walk.right.addFrame(sf::IntRect(34, 435, 20, 24));
    rocket.walk.right.addFrame(sf::IntRect(11, 435, 20, 24));
    rocket.walk.right.addFrame(sf::IntRect(34, 435, 20, 24));

    rocket.walk.down.setSpriteSheet(texture);
    rocket.walk.down.addFrame(sf::IntRect(36, 350, 17, 24));
    rocket.walk.down.addFrame(sf::IntRect(17, 350, 17, 26));
    rocket.walk.down.addFrame(sf::IntRect(36, 350, 17, 24));
    rocket.walk.down.addFrame(sf::IntRect(55, 350, 17, 26));
    rocket.walk.down.addFrame(sf::IntRect(36, 350, 17, 24));
    rocket.walk.down.addFrame(sf::IntRect(17, 350, 17, 26));
    
// ------------------------------ IDLE ANIMATIONS -----------------------------

    rocket.idle.up.setSpriteSheet(texture);
    rocket.idle.down.setSpriteSheet(texture);
    rocket.idle.right.setSpriteSheet(texture);
    rocket.idle.left.setSpriteSheet(texture);

    rocket.idle.up.addFrame(sf::IntRect(36, 407, 17, 23));
    rocket.idle.down.addFrame(sf::IntRect(36, 350, 17, 24));
    rocket.idle.right.addFrame(sf::IntRect(34, 435, 20, 24));
    rocket.idle.left.addFrame(sf::IntRect(34, 378, 20, 24));

    costumeSet.push_back(rocket);
    costumeIndex = 0;

}
