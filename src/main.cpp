#include "game.h"
#include <iostream>
#include "gui-components.h"
#include <SFML/Graphics.hpp>

void testDraw() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pokemon: Thunder and Lightning");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //test draw here
    }
}

int main() {
    std::cout << "Starting game";
    Game::Start();
    return 0;
}

