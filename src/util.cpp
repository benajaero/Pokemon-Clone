#include "util.h"
#include <tmx/MapLoader.hpp>

void Person::add(Pokemon pokemon) {
    pokemonArr.push_back(pokemon);
}

void Person::add(Item item) {
    items.push_back(item);
}

void Person::removePokemon(int index) {
    pokemonArr.erase(pokemonArr.begin() + index);
}

void Person::removeItem(int index) {
    items.erase(items.begin() + index);
}

