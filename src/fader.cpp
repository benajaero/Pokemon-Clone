#include "fader.h"

namespace{  // utility functions:
    template <typename T>
        sf::Vector2f to_v2f(T v)
        { return sf::Vector2f(static_cast<float>(v.x), static_cast<float>(v.y)) ; }

    unsigned clamp(float value)
    {
        if ( value < 0.1 )
            return 0 ;
        if ( value > 254.9 )
            return 255 ;
        return static_cast<unsigned>(value) ;
    }
}


const sf::Time Fader::defaultTimestep = sf::seconds(1.0f / 60.0f) ;

Fader::Fader(sf::RenderWindow& window, onDrawUpdate drawUpdate, Dir direction, onEventUpdate eventUpdate, 
        sf::Color faded, sf::Time fadeDuration, sf::Time timeStep)
    : _window(window), _eventUpdate(eventUpdate), _drawUpdate(drawUpdate), _direction(direction), _faded(faded), 
    _overlay(to_v2f(_window.getSize())), _timestep(timeStep), _fadeDuration(fadeDuration)
{
    _overlay.setPosition(0,0);
    _workIt() ;
}

void Fader::_workIt()
{
    sf::Clock total, iteration ;

    while ( _window.isOpen() && total.getElapsedTime() < _fadeDuration )
    {
        sf::Event event ;
        while ( _window.pollEvent(event) )
        {
            switch( event.type )
            {
                case sf::Event::Closed:
                    _window.close() ;
                    break;
                case sf::Event::MouseButtonPressed:
                case sf::Event::MouseButtonReleased:
                case sf::Event::MouseMoved:
                    if ( _eventUpdate )
                        _eventUpdate(event) ;
                    break ;
                default:
                    break;
            }
        }

        if ( iteration.getElapsedTime() >= _timestep )
        {
            const float complete = total.getElapsedTime().asSeconds() / _fadeDuration.asSeconds()  ;
            const unsigned alpha = clamp(_direction == Out ? (complete * 255.0f) : ((1.0f - complete) * 255.0f)) ;
            _overlay.setFillColor(sf::Color(_faded.r, _faded.g, _faded.b, alpha)) ;

            if ( _drawUpdate )
                _drawUpdate() ;
            else
                _window.clear() ;

            _window.draw(_overlay) ;
            _window.display() ;
            iteration.restart() ;
        }
    }
}
