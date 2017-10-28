#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
    private:
        static std::map<std::string, sf::Texture> _textures;
    public:
        static void loadTexture(const std::string& name, const std::string& filename);

        //string to texture ref
        static sf::Texture& getRef(const std::string& texture);
            
        static void deleteTexture(const std::string& texture);

        //without deleting texture manager
        static void deleteAll();
        TextureManager() {}

};


#endif
