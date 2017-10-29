#include "splashScreen.h"
#include "util.h"
#include "definitions.h"
#include "texturemanager.h"
#include "spritemanager.h"
#include "game.h"
#include <cassert>
#include <iostream>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

bool SplashScreen::loading = true;

void loadTextures() {
    TextureManager::loadTexture("heroTexture", "assets/NewHero.png");
}

void loadSprites() {
    SpriteManager::newAnimatedSprite("hero");
    AnimatedSprite& heroSprite = SpriteManager::getAnimRef("hero");
    heroSprite.setLooped(false);
    heroSprite.pause();
    heroSprite.setScale(SCALE, SCALE);
    heroSprite.setPosition(Game::_mainWindow.getView().getCenter());
}

void loadAnimations() {
    Game::hero.setupAnimations(TextureManager::getRef("heroTexture"));
    TextureManager::getRef("heroTexture").setSmooth(false);

}

void Load() {
    loadTextures();
    loadSprites();
    loadAnimations();
    Game::_gameState = Game::PLAYING;
    SplashScreen::loading = false;
}

void SplashScreen::Show(sf::RenderWindow& window) {

    sf::Sprite splashScreenSprite;
    splashScreenSprite.setTexture(TextureManager::getRef("splashScreenBackground"));


    loading = true; 

    std::thread loadingThread(Load);
    loadingThread.detach();

    do {
        window.clear(sf::Color::White);
        window.draw(splashScreenSprite);
        window.display();
        sf::Event event;
        Game::computeFrameTime();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Game::_gameState = Game::EXITING;
                return;
            }
        }
    } while (loading && window.isOpen());


}


