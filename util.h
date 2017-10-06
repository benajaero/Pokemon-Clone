#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <vector>
#include "pokemon.h"
#include "AnimatedSprite.hpp"

//clockwise
enum Orientation {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class AnimationSet {
    public:
        Animation up;
        Animation right;
        Animation left;
        Animation down;
};
class Item {
    private:

    public:

};

class PhysicalEntity {
    public:
        double x;
        double y;
        double z;
        double xvel;
        double yvel;
        Orientation direction;
        int layer;
        PhysicalEntity(double px, double py, double pz, double pxvel, double pyvel, Orientation dir, int layerr) : x(px), y(py), z(pz), xvel(pxvel), yvel(pyvel), direction(dir), layer(layerr) {}
};

class Person : public PhysicalEntity {
    private:

    public:
        std::string name;
        std::vector<Pokemon> pokemonArr;
        std::vector<Item> items;
        
        Person(std::string pname, double px, double py, double pz, double pxvel, double pyvel, Orientation dir, int layerr) : PhysicalEntity(px, py, pz, pxvel, pyvel, dir, layerr), name(pname) {
            pokemonArr.empty();
            items.empty();
        }

        void add(Pokemon pokemon);
        void removePokemon(int index);
        void add(Item item);
        void removeItem(int index);

};
#endif
