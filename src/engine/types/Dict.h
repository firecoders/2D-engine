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

#ifndef ENGINE_TYPES_DICT_GUARD
#define ENGINE_TYPES_DICT_GUARD

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <exception>

namespace sf
{
    class RenderTarget;
} /* namespace sf */

namespace engine
{
    namespace types
    {
        class Dict_element;
        union Value;

        typedef std::map< std::string, Dict_element > Dict;

        enum class Type
        {
            string, integer, floating, boolean, rendertarget, dict, empty
        };

        class Dict_element
        {
            public:
                Dict_element ();
                Dict_element ( std::shared_ptr< Dict > dict );
                Dict_element ( std::string string );
                Dict_element ( sf::RenderTarget* rendertarget );
                Dict_element ( int integer );
                Dict_element ( float floating );
                Dict_element ( bool boolean );

                Type get_type () const;

                std::shared_ptr< Dict > dict () const;
                std::string& string () const;
                sf::RenderTarget* rendertarget () const;
                int integer () const;
                float floating () const;
                bool boolean () const;

            private:
                Type type;
                std::shared_ptr< Value > value;
        };

        union Value
        {
            std::shared_ptr< Dict > dict;
            std::shared_ptr< std::string > string;
            sf::RenderTarget* rendertarget;
            int integer;
            float floating;
            bool boolean;

            Value ( std::shared_ptr< Dict > dict ) { this->dict = dict; };
            Value ( std::shared_ptr< std::string > string ) { this->string = string; };
            Value ( sf::RenderTarget* rendertarget ) { this->rendertarget = rendertarget; };
            Value ( int integer ) { this->integer = integer; };
            Value ( float floating ) { this->floating = floating; };
            Value ( bool boolean ) { this->boolean = boolean; };
            ~Value () {};
        };
    } /* namespace types */
} /* namespace engine */

#endif // ENGINE_TYPES_DICT_GUARD
