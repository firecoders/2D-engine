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

#ifndef ENGINE_GUI_RESOURCE_MANAGER_GUARD
#define ENGINE_GUI_RESOURCE_MANAGER_GUARD

#include <map>
#include <string>
#include <memory>

#include <iostream>
#include <algorithm>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace engine
{
    namespace gui
    {
        class Resource_manager
        {
            public:
                Resource_manager ( std::string resources_path, std::string graphics_extension );
                ~Resource_manager () = default;

                sf::Texture& get_texture ( std::string name );
                sf::Font& get_font ( std::string name );

            private:
                Resource_manager ( Resource_manager const & ) = delete;
                void operator= ( Resource_manager const & ) = delete;

                std::string construct_path ( std::string name, std::string extension );

                std::string resources_path;
                std::string graphics_extension;
                std::string fonts_extension;
                std::string missing_placeholder;

                std::map< std::string, sf::Texture > textures;
                std::map< std::string, sf::Font > fonts;
        };
    } /* namespace gui */
} /* namespace engine */

#endif // ENGINE_GUI_RESOURCE_MANAGER_GUARD
