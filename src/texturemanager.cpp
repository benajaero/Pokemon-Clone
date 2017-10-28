#include "texturemanager.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    texture.loadFromFile(filename);
    _textures[name] = texture;
}

sf::Texture& TextureManager::getRef(const std::string& texture) {
    return _textures.at(texture);
}

void TextureManager::deleteTexture(const std::string& texture) {
    std::map<std::string, sf::Texture>::iterator it = _textures.find(texture);
    _textures.erase(it);
}

void TextureManager::deleteAll() {
   _textures.erase(_textures.begin(), _textures.end()); 
}
