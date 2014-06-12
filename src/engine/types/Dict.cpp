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

#include "Dict.h"

using namespace engine::types;

Dict_element::Dict_element () :
    type ( Type::empty )
{}

Dict_element::Dict_element ( std::shared_ptr< Dict > dict ) :
    type ( Type::dict ),
    value ( std::make_shared< Value > ( dict ) )
{}

Dict_element::Dict_element ( std::string string ) :
    type ( Type::string ),
    value ( std::make_shared< Value > ( std::make_shared< std::string > ( string ) ) )
{}

Dict_element::Dict_element ( sf::RenderTarget* rendertarget ) :
    type ( Type::rendertarget ),
    value ( std::make_shared< Value > ( rendertarget ) )
{}

Dict_element::Dict_element ( int integer ) :
    type ( Type::integer ),
    value ( std::make_shared< Value > ( integer ) )
{}

Dict_element::Dict_element ( float floating ) :
    type ( Type::floating ),
    value ( std::make_shared< Value > ( floating ) )
{}

Dict_element::Dict_element ( bool boolean ) :
    type ( Type::boolean ),
    value ( std::make_shared< Value > ( boolean ) )
{}

Type Dict_element::get_type () const
{
    return type;
}

const std::map< Type, std::string > strings
{
    { Type::dict, "dict" },
    { Type::rendertarget, "rendertarget" },
    { Type::string, "string" },
    { Type::integer, "integer" },
    { Type::floating, "floating" },
    { Type::boolean, "boolean" },
    { Type::empty, "empty" }
};

void check_type ( Type actual, Type check )
{
    if ( actual != check )
    {
        throw std::logic_error ( "Cannot retrieve " + strings.at ( check ) +
                " from a Dict_element whose type is " + strings.at ( actual ) + "." );
    }
}

std::shared_ptr< Dict > Dict_element::dict () const
{
    check_type ( type, Type::dict );
    return value->dict;
}

std::string& Dict_element::string () const
{
    check_type ( type, Type::string );
    return * (value->string);
}

sf::RenderTarget* Dict_element::rendertarget () const
{
    check_type ( type, Type::rendertarget );
    return value->rendertarget;
}

int Dict_element::integer () const
{
    check_type ( type, Type::integer );
    return value->integer;
}

float Dict_element::floating () const
{
    check_type ( type, Type::floating );
    return value->floating;
}

bool Dict_element::boolean () const
{
    check_type ( type, Type::boolean );
    return value->boolean;
}
