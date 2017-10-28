#ifndef sprite_MANAGER_H
#define sprite_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class SpriteManager {
    private:
        static std::map<std::string, sf::Sprite> _sprites;
    public:
        static void newSprite(std::string name);

        //string to sprite ref
        static sf::Sprite& getRef(std::string sprite);
            
        static void deleteSprite(std::string sprite);

        //without deleting sprite manager
        static void deleteAll();
        SpriteManager() {}

};


#endif
