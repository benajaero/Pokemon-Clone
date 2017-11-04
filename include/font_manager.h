#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

//TODO CONVERT TO CLASS TEMPLATES
class FontManager {
    private:
        static std::map<std::string, sf::Font> _fonts;
    public:
        static sf::Font& loadFont(std::string name, std::string filePath);
        static sf::Font& getFont(std::string fontIdentifier);
        static void deleteFont(std::string fontIdentifier);
        static void deleteAll();
        FontManager() {}
};

#endif
