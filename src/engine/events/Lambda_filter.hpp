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

#ifndef ENGINE_EVENTS_LAMBDA_FILTER_GUARD
#define ENGINE_EVENTS_LAMBDA_FILTER_GUARD

#include <functional>

#include "interfaces/Filter.h"

namespace engine
{
    namespace events
    {
        template < typename Event_type >
            class Lambda_filter : public Filter< Event_type >
        {
            public:
                Lambda_filter ( std::function< bool ( Event_type* ) > f );

                bool qualifies ( Event_type* event );

            private:
                std::function< bool ( Event_type* ) > fun;
        };

        template < typename Event_type >
            Lambda_filter< Event_type >::Lambda_filter ( std::function< bool ( Event_type* ) > f )
            {
                fun = f;
            }

        template < typename Event_type >
            bool Lambda_filter< Event_type >::qualifies ( Event_type* event )
            {
                return fun ( event );
            }
    } /* namespace events */
} /* namespace engine */

#endif // ENGINE_EVENTS_LAMBDA_FILTER_GUARD
