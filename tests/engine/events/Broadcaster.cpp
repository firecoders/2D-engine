/* 2D-engine, A C++ library wrapping sfml, to be used for 2D games
   Copyright (c) 2014 firecoders

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE. */

#include <gtest/gtest.h>

#include "Test_receiver.hpp"
#include "engine/events/Broadcaster.hpp"
#include <memory>

using namespace engine::events;

TEST ( engineEventsBroadcaster, generalTest )
{
    Broadcaster < int > test_broadcaster;
    std::shared_ptr < Test_receiver < int > > test_receiver = std::make_shared < Test_receiver < int > > ();

    test_broadcaster.subscribe ( test_receiver );
    test_broadcaster.receive ( 5 );
    EXPECT_EQ ( test_receiver->result, 5 );

    test_broadcaster.unsubscribe ( test_receiver.get () );
    test_broadcaster.receive ( 6 );
    EXPECT_NE ( test_receiver->result, 6 );
    EXPECT_EQ ( test_receiver->result, 5 );
}

template < typename Event_type >
    class Auto_unsubscribe_receiver : public Receiver < Event_type >
    {
        public:
            Auto_unsubscribe_receiver ( Broadcaster < Event_type >* broadcaster ) : broadcaster ( broadcaster ) {}

            virtual void receive ( Event_type e )
            {
                broadcaster->unsubscribe ( this );
            }

        private:
            Broadcaster < Event_type >* broadcaster;
    };

TEST ( engineEventsBroadcaster, unsubscribeOnReceive )
{
    Broadcaster < int > test_broadcaster;
    std::shared_ptr < Auto_unsubscribe_receiver < int > > auto_unsubscribe_receiver
        = std::make_shared < Auto_unsubscribe_receiver < int > > ( &test_broadcaster );
    test_broadcaster.subscribe ( auto_unsubscribe_receiver );
    test_broadcaster.receive ( 1 );
}

template < typename Event_type >
    class Subscribe_receiver : public Receiver < Event_type >
    {
        public:
            Subscribe_receiver ( Broadcaster < Event_type >* broadcaster, std::shared_ptr < Test_receiver < Event_type > > subscribe_receiver )
                : broadcaster ( broadcaster ),
                  subscribe_receiver ( subscribe_receiver )
            {}

            virtual void receive ( Event_type e )
            {
                broadcaster->subscribe ( subscribe_receiver );
            }

        private:
            Broadcaster < Event_type >* broadcaster;
            std::shared_ptr < Test_receiver < Event_type > > subscribe_receiver;
    };

TEST ( engineEventsBroadcaster, subscribeOnReceive )
{
    Broadcaster < int > test_broadcaster;
    std::shared_ptr < Test_receiver < int > > test_receiver = std::make_shared < Test_receiver < int > > ();
    std::shared_ptr < Subscribe_receiver < int > > subscribe_receiver
        = std::make_shared < Subscribe_receiver < int > > ( &test_broadcaster, test_receiver );
    test_broadcaster.subscribe ( subscribe_receiver );
    test_broadcaster.receive ( 1 );
}

template < typename Event_type >
    class Auto_receive_receiver : public Receiver < Event_type >
    {
        public:
            Auto_receive_receiver ( Broadcaster < Event_type >* broadcaster ) : broadcaster ( broadcaster ), sent ( false ) {}

            virtual void receive ( Event_type e )
            {
                if ( !sent )
                {
                    broadcaster->receive ( 1 );
                    sent = true;
                }
            }

        private:
            Broadcaster < Event_type >* broadcaster;
            bool sent;
    };

TEST ( engineEventsBroadcaster, sendOnReceive )
{
    Broadcaster < int > test_broadcaster;
    std::shared_ptr < Auto_receive_receiver < int > > auto_receive_receiver
        = std::make_shared < Auto_receive_receiver < int > > ( &test_broadcaster );
    test_broadcaster.subscribe ( auto_receive_receiver );
    test_broadcaster.receive ( 1 );
}

template < typename Event_type >
    class Auto_unsubscribe_and_receive_receiver : public Receiver < Event_type >
    {
        public:
            Auto_unsubscribe_and_receive_receiver ( Broadcaster < Event_type >* broadcaster ) : broadcaster ( broadcaster ) {}

            virtual void receive ( Event_type e )
            {
                result = e;
                broadcaster->receive ( 2 );
                broadcaster->unsubscribe ( this );
            }

            Event_type result;

        private:
            Broadcaster < Event_type >* broadcaster;
    };

TEST ( engineEventsBroadcaster, unsubscribeOverReceive )
{
    Broadcaster < int > test_broadcaster;
    std::shared_ptr < Auto_unsubscribe_and_receive_receiver < int > > auto_unsubscribe_and_receive_receiver
        = std::make_shared < Auto_unsubscribe_and_receive_receiver < int > > ( &test_broadcaster );
    test_broadcaster.subscribe ( auto_unsubscribe_and_receive_receiver );
    test_broadcaster.receive ( 1 );
    EXPECT_EQ ( auto_unsubscribe_and_receive_receiver->result, 1 );
}

template < typename Event_type >
    class Auto_subscribe_and_receive_receiver : public Receiver < Event_type >
    {
        public:
            Auto_subscribe_and_receive_receiver ( Broadcaster < Event_type >* broadcaster, std::shared_ptr < Receiver < Event_type > > target )
                : broadcaster ( broadcaster ), sent ( false ), target ( target )
                {}

            virtual void receive ( Event_type e )
            {
                if ( !sent )
                {
                    broadcaster->receive ( 2 );
                    broadcaster->subscribe ( target );
                    sent = true;
                }
            }

        private:
            Broadcaster < Event_type >* broadcaster;
            bool sent;
            std::shared_ptr < Receiver < Event_type > > target;
    };

TEST ( engineEventsBroadcaster, subscribeOverReceive )
{
    Broadcaster < int > test_broadcaster;
    std::shared_ptr < Test_receiver < int > > test_receiver = std::make_shared < Test_receiver < int > > ();
    std::shared_ptr < Auto_subscribe_and_receive_receiver < int > > auto_subscribe_and_receive_receiver
        = std::make_shared < Auto_subscribe_and_receive_receiver < int > > ( &test_broadcaster, test_receiver );
    test_broadcaster.subscribe ( auto_subscribe_and_receive_receiver );
    test_broadcaster.receive ( 1 );
    EXPECT_EQ ( test_receiver->result, 2 );
}
