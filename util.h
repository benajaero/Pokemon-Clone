#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <vector>
#include "pokemon.h"

//clockwise
enum Orientation {
    NORTH,
    EAST,
    SOUTH,
    WEST
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
        int layer;
        Orientation direction;
        PhysicalEntity(double px, double py, double pz, double pxvel, double pyvel, Orientation dir, int layerr) : x(px), y(py), z(pz),
        direction(dir), layer(layerr), xvel(pxvel), yvel(pyvel)
    {}
};

class Person : private PhysicalEntity {
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
