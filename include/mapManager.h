#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include "tmxlite/Map.hpp"
#include "SFMLOrthogonalLayer.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <vector>

class MapManager {
    private:
        static std::map<std::string, tmx::Map> _maps;
        static std::map<std::string, MapLayer> _layers;
    public:
        static tmx::Map& loadMap(std::string name, std::string filePath);
        static void drawLayers(sf::RenderWindow& win);
        static void newLayer(std::string name, tmx::Map& _map, int layerNumber);
        static tmx::Map& getMap(std::string name);
        static MapLayer& getLayer(std::string name);
        static void drawLayers(sf::RenderWindow& win, std::vector<std::string> layerNames);

        static void deleteMap(std::string name);
        static void deleteLayer(std::string name);
        static void deleteAllMaps();
        static void deleteAllLayers();
};

#endif
