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

#ifndef ENGINE_EVENTS_HUB_GUARD
#define ENGINE_EVENTS_HUB_GUARD

#include <memory>

#include "Listener.h"
#include "Filter.h"

namespace engine {
    namespace events {
        template <typename Event_type>
            class Hub {
                public:
                    virtual ~Hub () = default;

                    virtual void subscribe (Listener<Event_type>* listener, Filter<Event_type>* filter) = 0;
                    virtual void unsubscribe (Listener<Event_type>* listener, Filter<Event_type>* filter) = 0;

                    virtual void broadcast_event (Event_type* event) = 0;
                    virtual void queue_event (std::shared_ptr<Event_type> event) = 0;
                    virtual void flush_queue () = 0;
            };
    } /* namespace events */
} /* namespace engine */

#endif // ENGINE_EVENTS_HUB_GUARD
