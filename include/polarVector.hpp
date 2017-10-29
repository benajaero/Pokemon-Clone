#ifndef POLARVECTOR_HPP
#define POLARVECTOR_HPP

///Polar Vector class
#include <SFML/System/Vector2.hpp>

///The class uses radians as angles, where r is the radius and t is the angle.

class PolarVector
{ 
  public:
        float r;
        float t;

        PolarVector();
        PolarVector(float radius, float angle);

        sf::Vector2f TurnToRectangular() const;
  private:
        static const float EPSILON;

        friend bool operator ==(const PolarVector& left, const PolarVector& right);
};

PolarVector TurnToPolar(const sf::Vector2f& point);

bool operator ==(const PolarVector& left, const PolarVector& right);

bool operator !=(const PolarVector& left, const PolarVector& right);

#endif // POLARVECTOR_HPP


#include <cmath>

const float PolarVector::EPSILON = 0.0001;

PolarVector::PolarVector()
  :r(0.0), t(0.0)
{}

PolarVector::PolarVector(float radius, float angle)
  :r(radius), t(angle)
{}

sf::Vector2f PolarVector::TurnToRectangular() const
{
  sf::Vector2f Rect;
  Rect.x = static_cast<float>(r*std::cos(t)); Rect.y = static_cast<float>(r*std::sin(t));
  return Rect;
}

bool operator ==(const PolarVector& left, const PolarVector& right)
{
  float diffR = left.r - right.r;
  float diffA = left.t - right.t;
  return ((diffR <= PolarVector::EPSILON) && (diffA <= PolarVector::EPSILON));
}

bool operator !=(const PolarVector& left, const PolarVector& right)
{ return !(left == right); }

PolarVector TurnToPolar(const sf::Vector2f& point)
{
    PolarVector PV;
    PV.r = sqrt((point.x * point.x) + (point.y * point.y));
    PV.t = std::atan2(point.y, point.x);
    return PV;
}
