#include "texturemanager.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

std::map<std::string, sf::Texture> TextureManager::_textures;
sf::Texture& TextureManager::loadTexture(std::string name, std::string filename) {
    sf::Texture texture;
    texture.loadFromFile(filename);
    TextureManager::_textures[name] = texture;
    return TextureManager::_textures.at(name);
}

sf::Texture& TextureManager::getRef(std::string texture) {
    return TextureManager::_textures.at(texture);
}

void TextureManager::deleteTexture(std::string texture) {
    std::map<std::string, sf::Texture>::iterator it = TextureManager::_textures.find(texture);
    TextureManager::_textures.erase(it);
}

void TextureManager::deleteAll() {
   TextureManager::_textures.erase(TextureManager::_textures.begin(), TextureManager::_textures.end()); 
}

