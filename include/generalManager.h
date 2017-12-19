#ifndef GENERAL_MANAGER_H
#define GENERAL_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <map>
#include <string>

class GeneralManager {
    private:
        static std::map<std::string, sf::IntRect> _intRects;  
        static std::map<std::string, Animation> _animations;
    public:
        static sf::IntRect& newIntRect(std::string name, sf::IntRect rect);
        static sf::IntRect& getIntRect(std::string name);
        static void deleteIntRect(std::string name);
        static void deleteAllIntRect();

        static Animation& newAnimation(std::string name);
        static Animation& getAnimation(std::string name);
        static void deleteAnimation(std::string name);
        static void deleteAllAnimations();


};

#endif
