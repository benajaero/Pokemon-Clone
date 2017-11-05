#include "mapManager.h"
#include <cassert>

std::map<std::string, tmx::Map> MapManager::_maps;
std::map<std::string, MapLayer> MapManager::_layers;

tmx::Map& MapManager::loadMap(std::string name, std::string filePath) {
    MapManager::_maps.emplace(name, tmx::Map());
    assert(MapManager::_maps.at(name).load(filePath));
    return MapManager::_maps.at(name);
}

void MapManager::drawLayers(sf::RenderWindow& win) {
    std::map<std::string, MapLayer>::iterator it = MapManager::_layers.begin(); 
    
    for (auto& elem : MapManager::_layers) {
        win.draw(elem.second);
    }
}

void MapManager::newLayer(std::string name, tmx::Map& _map, int layerNumber) {

}

void MapManager::deleteMap(std::string name) {

}

void MapManager::deleteLayer(std::string name) {

}

void MapManager::deleteAllMaps() {
    
}

void MapManager::deleteAllLayers() {

}
