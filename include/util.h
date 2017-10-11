#ifndef UTILITY_H
#define UTILITY_H

#include "pokemon.h"
#include "enums.h"
#include "AnimatedSprite.hpp"
#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <cmath>


class EllipseShape : public sf::Shape {
    public :

        explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
            m_radius(radius)
    {
        update();

    }

        void setRadius(const sf::Vector2f& radius)
        {
            m_radius = radius;
            update();

        }

        const sf::Vector2f& getRadius() const
        {
            return m_radius;

        }

        virtual std::size_t getPointCount() const
        {
            return 30; // fixed, but could be an attribute of the class if needed

        }

        virtual sf::Vector2f getPoint(std::size_t index) const
        {
            static const float pi = 3.141592654f;

            float angle = index * 2 * pi / getPointCount() - pi / 2;
            float x = std::cos(angle) * m_radius.x;
            float y = std::sin(angle) * m_radius.y;

            return sf::Vector2f(m_radius.x + x, m_radius.y + y);

        }

    private :

        sf::Vector2f m_radius;

};

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
        AnimatedSprite sprite;
        AnimationSet idle;
        AnimationSet walk;
        AnimationSet run;
        AnimationSet bicycle;
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
