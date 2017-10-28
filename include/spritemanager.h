#ifndef sprite_MANAGER_H
#define sprite_MANAGER_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <string>
#include <map>

class SpriteManager {
    private:
        static std::map<std::string, sf::Sprite> _sprites;
        static std::map<std::string, AnimatedSprite> _animatedSprites;
    public:
        static void newSprite(std::string name);
        //string to sprite ref
        static sf::Sprite& getRef(std::string sprite);
        static void deleteSprite(std::string sprite);
        //without deleting sprite manager
        static void deleteAll();

        static void newAnimatedSprite(std::string name);
        //string to sprite ref
        static AnimatedSprite& getAnimRef(std::string animatedSprite);
        static void deleteAnimatedSprite(std::string animatedSprite);
        //without deleting sprite manager
        static void deleteAllAnimated();

        SpriteManager() {}

};


#endif
