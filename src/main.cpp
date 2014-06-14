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

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <memory>

#include "engine/events/Central_hub.hpp"

#include "engine/events/Lambda_listener.hpp"
#include "engine/events/Lambda_filter.hpp"

#include "engine/gui/Window.h"
#include "engine/gui/Draw_event.h"
#include "engine/gui/Resource_manager.h"

int main()
{
    engine::gui::Resource_manager resource_manager { "res/", ".png" };
    sf::Sprite sprite;
    sprite.setTexture ( resource_manager.get_texture ( "splash.welcome" ) );

    std::shared_ptr< engine::events::Listener < engine::gui::Draw_event* > > draw_listener =
        std::make_shared < engine::events::Lambda_listener < engine::gui::Draw_event* > >
        (
            [ sprite ] ( engine::gui::Draw_event* draw_event )
            {
                draw_event->get_target ()->draw ( sprite );
            }
        );

    std::shared_ptr < engine::events::Listener < sf::Event* > > sfml_listener =
        std::make_shared < engine::events::Lambda_listener < sf::Event* > >
        (
            [] ( sf::Event* event )
            {
                std::cout << "Event!" << std::endl;
            }
        );

    std::shared_ptr < sf::RenderWindow > render_window = std::make_shared < sf::RenderWindow >
    (
        sf::VideoMode { 200, 200 }, "Test window"
    );

    engine::gui::Window window { render_window, draw_listener, sfml_listener };

    window.loop ( 40 );

    return 0;
}
