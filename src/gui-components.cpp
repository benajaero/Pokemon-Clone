#include "gui-components.h"

void Button::setBackgroundSize(sf::Vector2f dimensions) {
    _background.setSize(dimensions);
}
void Button::setButtonFont(sf::Font font) {
   _text.setFont(font); 
}
void Button::setText(std::string text) {
    _text.setString(text);
}
void Button::setRadius(float radius) {
    _background.setCornersRadius(radius);
}
sf::Vector2f Button::getBackgroundSize(sf::Vector2f size) {
    return _background.getSize();
}
void Button::setPosition(sf::Vector2f pos) {
    _background.setPosition(pos);
    sf::Vector2f size = _background.getSize();
    _text.setPosition(pos.x + size.x / 2, pos.y + size.y / 2);
}
void Button::setTextSize(int size) {
    _text.setCharacterSize(24);
} 
void Button::setClicked(sf::Vector2f mousePos) {
    _isClicked = _background.getGlobalBounds().contains(mousePos);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(_background);
    window.draw(_text); 
}
