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

#ifndef ENGINE_EVENTS_HUB_FORWARDER_GUARD
#define ENGINE_EVENTS_HUB_FORWARDER_GUARD

#include "interfaces/Hub.h"

namespace engine
{
    namespace events
    {
        template< typename Event_type >
            class Hub_forwarder : public Hub< Event_type >
            {
                public:
                    Hub_forwarder ();
                    void set_target ( Hub< Event_type>* t );

                    void subscribe ( Listener< Event_type* >* listener, Filter< Event_type* >* filter );
                    void unsubscribe ( Listener< Event_type* >* listener, Filter< Event_type* >* filter );
                    void broadcast_event ( Event_type* event );
                    void queue_event ( std::shared_ptr< Event_type > event );
                    void flush_queue ();

                private:
                    Hub< Event_type >* target;
            };


        /*                     Hub_forwarder Methods                   */
        template < typename Event_type >
            Hub_forwarder< Event_type >::Hub_forwarder ()
                : target ( nullptr )
            {}

        template < typename Event_type >
            void Hub_forwarder< Event_type >::set_target ( Hub< Event_type >* t )
            {
                target = t;
            }


        /*                     Hub Methods                             */
        template< typename Event_type >
            void Hub_forwarder< Event_type >::subscribe
                ( Listener< Event_type* >* listener, Filter< Event_type* >* filter)
            {
                if ( target != nullptr )
                    target->subscribe ( listener, filter );
            }

        template< typename Event_type >
            void Hub_forwarder< Event_type >::unsubscribe
                ( Listener< Event_type* >* listener, Filter< Event_type* >* filter )
            {
                if ( target != nullptr )
                    target->unsubscribe ( listener, filter );
            }

        template< typename Event_type >
            void Hub_forwarder< Event_type >::broadcast_event ( Event_type* event)
            {
                if ( target != nullptr )
                    target->broadcast_event ( event );
            }

        template< typename Event_type >
            void Hub_forwarder< Event_type >::queue_event
                ( std::shared_ptr< Event_type > event )
            {
                if ( target != nullptr )
                    target->queue_event ( event );
            }

        template< typename Event_type >
            void Hub_forwarder< Event_type >::flush_queue ()
            {
                if ( target != nullptr )
                    target->flush_queue ();
            }

    } /* namespace events */
} /* namespace engine */

#endif // ENGINE_EVENTS_HUB_FORWARDER_GUARD
