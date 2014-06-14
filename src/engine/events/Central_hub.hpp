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

/* TODO: optimize: Currently, multiple subscriptions with the same filter
 * will run the filter multiple times when broadcasting.
 */

#ifndef ENGINE_EVENTS_CENTRAL_HUB_GUARD
#define ENGINE_EVENTS_CENTRAL_HUB_GUARD

#include <queue>
#include <vector>

#include <algorithm>

#include "interfaces/Hub.h"

namespace engine
{
    namespace events
    {
        template < typename Event_type >
            struct Subscription
            {
                Listener< Event_type >* listener;
                Filter< Event_type >* filter;

                bool operator== ( const Subscription< Event_type >& other ) const
                {
                    return listener == other.listener && filter == other.filter;
                }
            };

        template < typename Event_type >
            class Central_hub : public Hub< Event_type >
        {
            public:
                Central_hub () = default;
                ~Central_hub () = default;

                void subscribe ( Listener< Event_type* >* listener, Filter< Event_type* >* filter );
                void unsubscribe ( Listener< Event_type* >* listener, Filter< Event_type* >* filter );

                void broadcast_event ( Event_type* event );
                void queue_event ( std::shared_ptr< Event_type > event );
                void flush_queue ();

            private:
                std::queue< std::shared_ptr< Event_type > > event_queue;
                std::vector< Subscription< Event_type* > > subscriptions;
        };

        template < typename Event_type >
            void Central_hub< Event_type >::subscribe ( Listener< Event_type* >* listener, Filter< Event_type* >* filter )
            {
                subscriptions.push_back ( Subscription< Event_type* > { listener, filter } );
            }

        template < typename Event_type >
            void Central_hub< Event_type >::unsubscribe ( Listener< Event_type* >* listener, Filter< Event_type* >* filter )
            {
                subscriptions.erase ( std::remove ( subscriptions.begin (), subscriptions.end (),
                            Subscription< Event_type* > { listener, filter } ), subscriptions.end () );
            }

        template < typename Event_type >
            void Central_hub< Event_type >::broadcast_event ( Event_type* event )
            {
                for ( auto subscription : subscriptions )
                {
                    if ( subscription.filter->qualifies ( event ) )
                        subscription.listener->handle_event ( event );
                }
            }

        template < typename Event_type >
            void Central_hub< Event_type >::queue_event ( std::shared_ptr< Event_type > event )
            {
                event_queue.push ( event );
            }

        template < typename Event_type >
            void Central_hub< Event_type >::flush_queue ()
            {
                while ( !event_queue.empty () )
                {
                    auto next = event_queue.front ();
                    event_queue.pop ();
                    broadcast_event ( next.get () );
                }
            }
    } /* namespace events */
} /* namespace engine */

#endif // ENGINE_EVENTS_CENTRAL_HUB_GUARD
