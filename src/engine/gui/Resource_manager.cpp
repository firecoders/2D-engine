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

#include "Resource_manager.h"

using namespace engine::gui;

Resource_manager::Resource_manager ( std::string resources_path, std::string graphics_extension ) :
    resources_path ( resources_path ),
    graphics_extension (graphics_extension ),
    fonts_extension ( ".ttf" ),
    missing_placeholder ( "placeholder.missing" )
{
    sf::err().rdbuf(NULL);
}

sf::Texture& Resource_manager::get_texture ( std::string name )
{
    if ( textures.find ( name ) != textures.end () )
    {
        return textures.at ( name );
    }
    std::string path = construct_path ( name, graphics_extension );
    std::cout << "Loading texture " << name << " from " << path << std::endl;

    sf::Texture texture;
    if ( !texture.loadFromFile ( path ) )
    {
        std::cerr << "[FAILED] to load texture " << name << ", ";
        if ( name != missing_placeholder )
        {
            std::cerr << "using " << missing_placeholder << " instead." << std::endl;
            return get_texture ( missing_placeholder );
        }
        std::cerr << "exiting." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    textures.insert ( std::make_pair ( name, texture ) );
    return textures.at ( name );
}

sf::Font& Resource_manager::get_font ( std::string name )
{
    if ( fonts.find ( name ) != fonts.end () )
    {
        return fonts.at ( name );
    }
    std::string path = construct_path ( name, fonts_extension );
    std::cout << "Loading font " << name << " from " << path << std::endl;

    sf::Font font;
    if ( !font.loadFromFile ( path ) )
    {
        std::cerr << "[FAILED] to load font " << name << ", exiting." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    fonts.insert( std::make_pair ( name, font ) );
    return fonts.at ( name );
}

std::string Resource_manager::construct_path ( std::string name, std::string extension )
{
    std::string path = resources_path;
    std::replace_copy ( name.begin (), name.end (), std::back_inserter ( path ), '.', '/' );
    path.append ( extension );
    return path;
}
