#include "generalManager.h"
#include <iostream>

std::map<std::string, sf::IntRect> GeneralManager::_intRects;
std::map<std::string, Animation> GeneralManager::_animations;

sf::IntRect& GeneralManager::newIntRect(std::string name, sf::IntRect rect) {
    GeneralManager::_intRects[name] = rect;
    std::cout << "here we are again\n";
    return GeneralManager::_intRects.at(name); 
}

sf::IntRect& GeneralManager::getIntRect(std::string name) {
    return GeneralManager::_intRects.at(name); 
}

void GeneralManager::deleteIntRect(std::string name) {
    std::map<std::string, sf::IntRect>::iterator it = GeneralManager::_intRects.find(name);
    GeneralManager::_intRects.erase(it);
}

void GeneralManager::deleteAllIntRect() {
    GeneralManager::_intRects.erase(_intRects.begin(), _intRects.end());
}

Animation& GeneralManager::newAnimation(std::string name) {
    _animations[name] = Animation();
    return _animations.at(name);
}

Animation& GeneralManager::getAnimation(std::string name) {
    return _animations.at(name);
}

void GeneralManager::deleteAnimation(std::string name) {
    std::map<std::string, Animation>::iterator it = _animations.find(name);
    _animations.erase(it);
}

void GeneralManager::deleteAllAnimations() {
    _animations.erase(_animations.begin(), _animations.end());
}

