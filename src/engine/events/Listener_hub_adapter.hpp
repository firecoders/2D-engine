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

#ifndef ENGINE_EVNETS_LISTENER_HUB_ADAPTER_GUARD
#define ENGINE_EVNETS_LISTENER_HUB_ADAPTER_GUARD

#include <memory>

#include "interfaces/Hub.h"
#include "interfaces/Listener.h"

namespace magic
{
    template < typename Event_type >
        struct Is_shared_ptr
        {
            static const bool value = false;
        };

    template < typename Event_type >
        struct Is_shared_ptr< std::shared_ptr < Event_type > >
        {
            static const bool value = true;
        };

    template < typename Event_type >
        struct Remove_pointer
        {
            typedef Event_type value;
        };

    template < typename Event_type >
        struct Remove_pointer< Event_type* >
        {
            typedef Event_type value;
        };

    template < typename Event_type >
        struct Remove_pointer< std::shared_ptr< Event_type > >
        {
            typedef Event_type value;
        };
} /* namespace template_magic */

namespace engine
{
    namespace events
    {
        template
            <
                typename Event_type,
                bool use_queue = magic::Is_shared_ptr< Event_type >::value
            >
            class Listener_hub_adapter : public Listener< Event_type >
            {
                public:
                    Listener_hub_adapter ( Hub< typename magic::Remove_pointer< Event_type >::value >* wrapped );

                    void handle_event ( Event_type event );

                private:
                    Hub< typename magic::Remove_pointer< Event_type >::value >* wrapped;
            };

        template < typename Event_type >
            class Listener_hub_adapter< Event_type, true > : public Listener< Event_type >
            {
                public:
                    Listener_hub_adapter ( Hub< typename magic::Remove_pointer< Event_type >::value >* wrapped );

                    void handle_event ( Event_type event );

                private:
                    Hub< typename magic::Remove_pointer< Event_type >::value >* wrapped;
            };

        template < typename Event_type, bool use_queue >
            Listener_hub_adapter< Event_type, use_queue >::Listener_hub_adapter ( Hub< typename magic::Remove_pointer< Event_type >::value >* wrapped ) :
                wrapped ( wrapped )
        {}


        template < typename Event_type, bool use_queue >
            void Listener_hub_adapter< Event_type, use_queue >::handle_event ( Event_type event )
            {
                wrapped->broadcast_event ( event );
            }


        template < typename Event_type >
            Listener_hub_adapter< Event_type, true >::Listener_hub_adapter ( Hub< typename magic::Remove_pointer< Event_type >::value >* wrapped ) :
                wrapped ( wrapped )
        {}

        template < typename Event_type >
            void Listener_hub_adapter< Event_type, true >::handle_event ( Event_type event )
            {
                wrapped->queue_event ( event );
            }

    } /* namespace events */
} /* namespace engine */

#endif // ENGINE_EVNETS_LISTENER_HUB_ADAPTER_GUARD
