#ifndef GUI_COMPONENTS
#define GUI_COMPONENTS

#include <SFML/Graphics.hpp>
#include "roundedRectangle.h"
#include <functional>
#include <string>
//just the buttons (menu should be overlaid over title screen)

class Button {
    private:
        std::function<void()> _callback;
        bool _isClicked;
    public:
        //just helpful functions its probably easier just to get the objects for other functions
        void setBackgroundSize(sf::Vector2f dimensions);
        void setButtonFont(sf::Font font);
        void setText(std::string text);
        void setRadius(float radius);
        void setPosition(sf::Vector2f pos);
        sf::Vector2f getBackgroundSize(sf::Vector2f size);
        void setTextSize(int size);

        sf::RoundedRectangleShape _background;
        sf::Text _text;      
        
        sf::RoundedRectangleShape& getBackground() { return _background; };
        sf::RoundedRectangleShape getBackgroundCopy() { return _background; }
        sf::Text& getText() { return _text; };
        sf::Text getTextCopy() { return _text; }
        bool isClicked() { return _isClicked; };
        void setClicked(sf::Vector2f mousePos);
        void draw(sf::RenderWindow& window);

        Button() {
            _background = sf::RoundedRectangleShape();
            _text = sf::Text();
        }
};

class MainMenu {
    private:

    public:

};

#endif
