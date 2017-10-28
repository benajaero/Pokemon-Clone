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
