#ifndef FADER_H_
#define FADER_H_

#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

class Fader
{
    public:
        typedef std::function<void(sf::Event&)> onEventUpdate ;
        typedef std::function<void()> onDrawUpdate ;
        enum Dir { Out, In } ;


        const static sf::Time defaultTimestep ;

        Fader(sf::RenderWindow& window,                      // The window to manipulate. 
                onDrawUpdate drawUpdate,                     // The callback for drawing updates
                Dir direction = Out,                         // Fading in or fading out?
                onEventUpdate eventUpdate = nullptr,         // The callback for events
                sf::Color faded=sf::Color(0,0,0),            // The color when fully faded.
                sf::Time fadeDuration= sf::seconds(1.0),     // The duration to fully fade/unfade
                sf::Time timeStep = defaultTimestep) ;       // The target timestep for the drawUpdate callback.

    private:

        void _workIt() ;

        sf::RenderWindow & _window ;

        onEventUpdate _eventUpdate ;
        onDrawUpdate _drawUpdate ;

        Dir _direction ;

        sf::Color _faded ;

        sf::RectangleShape _overlay ;

        sf::Time _timestep ;
        sf::Time _fadeDuration ;

        Fader(const Fader &) ;
        Fader& operator=(const Fader&);
};

#endif
