/* rpg-engine, An rpg engine written in C++
   Copyright (C) 2014 firecoders

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
   OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "Sfml_event_to_dict.h"

using namespace engine::converters;
using namespace engine;

Sfml_event_to_dict::Sfml_event_to_dict ( events::Listener< std::shared_ptr< types::Dict > >* listener ) :
    listener ( listener )
{}

void Sfml_event_to_dict::handle_event ( std::shared_ptr< sf::Event > sfml_event )
{
    std::shared_ptr< types::Dict > converted = std::make_shared< types::Dict > ();

    converted->insert ( { std::string ( "type" ), "converted sf::Event of type " + event_type ( sfml_event->type ) } );
    switch ( sfml_event->type )
    {
        case sf::Event::Resized:
            converted->insert ( { std::string ( "size.width" ), sfml_event->size.width } );
            converted->insert ( { std::string ( "size.height" ), sfml_event->size.height } );
            break;

        case sf::Event::TextEntered:
            converted->insert ( { std::string ( "text.unicode" ), sfml_event->text.unicode } );
            break;

        case sf::Event::KeyPressed:
        case sf::Event::KeyReleased:
            converted->insert ( { std::string ( "key.code" ), key_code ( sfml_event->key.code ) } );
            converted->insert ( { std::string ( "key.alt" ), sfml_event->key.alt } );
            converted->insert ( { std::string ( "key.control" ), sfml_event->key.control } );
            converted->insert ( { std::string ( "key.shift" ), sfml_event->key.shift } );
            converted->insert ( { std::string ( "key.system" ), sfml_event->key.system } );
            break;

        case sf::Event::MouseWheelMoved:
            converted->insert ( { std::string ( "mouseWheel.delta" ), sfml_event->mouseWheel.delta } );
            converted->insert ( { std::string ( "mouseWheel.x" ), sfml_event->mouseWheel.x } );
            converted->insert ( { std::string ( "mouseWheel.y" ), sfml_event->mouseWheel.y } );
            break;

        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseButtonReleased:
            converted->insert ( { std::string ( "mouseButton.button" ), mouse_button ( sfml_event->mouseButton.button ) } );
            converted->insert ( { std::string ( "mouseButton.x" ), sfml_event->mouseButton.x } );
            converted->insert ( { std::string ( "mouseButton.y" ), sfml_event->mouseButton.y } );
            break;

        case sf::Event::MouseMoved:
            converted->insert ( { std::string ( "mouseMove.x" ), sfml_event->mouseMove.x } );
            converted->insert ( { std::string ( "mouseMove.y" ), sfml_event->mouseMove.y } );
            break;

            /* these are currently not supported:
             * sf::Event::JoystickButtonPressed:
             * sf::Event::JoystickButtonReleased:
             * sf::Event::JoystickMoved:
             * sf::Event::JoystickConnected:
             * sf::Event::JoystickDisconnected:
             */

        default: break;
    }

    listener->handle_event ( converted );
}
