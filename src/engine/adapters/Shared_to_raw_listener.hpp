/* 2D-engine, A C++ library wrapping sfml, to be used for 2D games
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

#ifndef ENGINE_ADAPTERS_SHARED_TO_RAW_LISTENER_GUARD
#define ENGINE_ADAPTERS_SHARED_TO_RAW_LISTENER_GUARD

#include <memory>

#include "engine/events/interfaces/Listener.h"

namespace engine
{
    namespace adapters
    {
        template < typename Event_type >
            class Shared_to_raw_listener : public events::Listener< std::shared_ptr< Event_type > >
        {
            public:
                Shared_to_raw_listener ( events::Listener< Event_type* >* listener );

                void handle_event ( std::shared_ptr< Event_type > event );

            private:
                events::Listener< Event_type* >* listener;
        };

        template < typename Event_type >
            Shared_to_raw_listener< Event_type >::Shared_to_raw_listener ( events::Listener< Event_type* >* listener ) :
                listener ( listener )
        {}

        template < typename Event_type >
            void Shared_to_raw_listener< Event_type >::handle_event ( std::shared_ptr< Event_type > event )
            {
                listener->handle_event ( event.get () );
            }


    } /* namespace adapters */
} /* namespace engine */

#endif // ENGINE_ADAPTERS_SHARED_TO_RAW_LISTENER_GUARD
