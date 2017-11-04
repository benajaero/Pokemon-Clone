#include "font_manager.h"
#include <cassert>

std::map<std::string, sf::Font> FontManager::_fonts;
sf::Font& FontManager::loadFont(std::string name, std::string filePath) {
    sf::Font font;
    assert(font.loadFromFile(filePath));
    FontManager::_fonts[name] = font;
    return FontManager::_fonts.at(name);
}

sf::Font& FontManager::getFont(std::string fontIdentifier) {
    return FontManager::_fonts.at(fontIdentifier);
}

void FontManager::deleteFont(std::string fontIdentifier) {
    std::map<std::string, sf::Font>::iterator it = FontManager::_fonts.find(fontIdentifier);
    FontManager::_fonts.erase(it);
}

void FontManager::deleteAll() {
    FontManager::_fonts.erase(FontManager::_fonts.begin(), FontManager::_fonts.end());
}
