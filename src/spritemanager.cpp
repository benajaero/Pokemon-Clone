#include "spritemanager.h"
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <map>
#include <string>

std::map<std::string, sf::Sprite> SpriteManager::_sprites;
std::map<std::string, AnimatedSprite> SpriteManager::_animatedSprites;

void SpriteManager::newSprite(std::string name) {
    sf::Sprite sprite;
    SpriteManager::_sprites[name] = sprite;
}

sf::Sprite& SpriteManager::getRef(std::string sprite) {
    return SpriteManager::_sprites.at(sprite);
}

void SpriteManager::deleteSprite(std::string sprite) {
    std::map<std::string, sf::Sprite>::iterator it = SpriteManager::_sprites.find(sprite);
    SpriteManager::_sprites.erase(it);
}

void SpriteManager::deleteAll() {
   SpriteManager::_sprites.erase(SpriteManager::_sprites.begin(), SpriteManager::_sprites.end()); 
}

void SpriteManager::newAnimatedSprite(std::string name) {
    AnimatedSprite sprite;
    SpriteManager::_animatedSprites[name] = sprite;
}

AnimatedSprite& SpriteManager::getAnimRef(std::string animatedSprite) {
    return SpriteManager::_animatedSprites.at(animatedSprite);
}

void SpriteManager::deleteAnimatedSprite(std::string animatedSprite) {
    std::map<std::string, AnimatedSprite>::iterator it = SpriteManager::_animatedSprites.find(animatedSprite);
    SpriteManager::_animatedSprites.erase(it);
}
void SpriteManager::deleteAllAnimated() {
    SpriteManager::_animatedSprites.erase(SpriteManager::_animatedSprites.begin(), SpriteManager::_animatedSprites.end());
}


