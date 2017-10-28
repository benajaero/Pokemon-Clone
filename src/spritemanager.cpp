#include "spritemanager.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

std::map<std::string, sf::Sprite> SpriteManager::_sprites;
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

