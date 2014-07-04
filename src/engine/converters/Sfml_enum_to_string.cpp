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

#include "Sfml_enum_to_string.h"

namespace engine
{
    namespace converters
    {
        const std::map< sf::Event::EventType, std::string > event_types =
        {
            { sf::Event::Closed, "Closed" },
            { sf::Event::Resized, "Resized" },
            { sf::Event::LostFocus, "LostFocus" },
            { sf::Event::GainedFocus, "GainedFocus" },
            { sf::Event::TextEntered, "TextEntered" },
            { sf::Event::KeyPressed, "KeyPressed" },
            { sf::Event::KeyReleased, "KeyReleased" },
            { sf::Event::MouseWheelMoved, "MouseWheelMoved" },
            { sf::Event::MouseButtonPressed, "MouseButtonPressed" },
            { sf::Event::MouseButtonReleased, "MouseButtonReleased" },
            { sf::Event::MouseMoved, "MouseMoved" },
            { sf::Event::MouseEntered, "MouseEntered" },
            { sf::Event::MouseLeft, "MouseLeft" },
            { sf::Event::JoystickButtonPressed, "JoystickButtonPressed" },
            { sf::Event::JoystickButtonReleased, "JoystickButtonReleased" },
            { sf::Event::JoystickMoved, "JoystickMoved" },
            { sf::Event::JoystickConnected, "JoystickConnected" },
            { sf::Event::JoystickDisconnected, "JoystickDisconnected" }
        };

        const std::map< sf::Keyboard::Key, std::string > key_codes =
        {
            { sf::Keyboard::Key::Unknown, "Unknown" },
            { sf::Keyboard::Key::A, "A" },
            { sf::Keyboard::Key::B, "B" },
            { sf::Keyboard::Key::C, "C" },
            { sf::Keyboard::Key::D, "D" },
            { sf::Keyboard::Key::E, "E" },
            { sf::Keyboard::Key::F, "F" },
            { sf::Keyboard::Key::G, "G" },
            { sf::Keyboard::Key::H, "H" },
            { sf::Keyboard::Key::I, "I" },
            { sf::Keyboard::Key::J, "J" },
            { sf::Keyboard::Key::K, "K" },
            { sf::Keyboard::Key::L, "L" },
            { sf::Keyboard::Key::M, "M" },
            { sf::Keyboard::Key::N, "N" },
            { sf::Keyboard::Key::O, "O" },
            { sf::Keyboard::Key::P, "P" },
            { sf::Keyboard::Key::Q, "Q" },
            { sf::Keyboard::Key::R, "R" },
            { sf::Keyboard::Key::S, "S" },
            { sf::Keyboard::Key::T, "T" },
            { sf::Keyboard::Key::U, "U" },
            { sf::Keyboard::Key::V, "V" },
            { sf::Keyboard::Key::W, "W" },
            { sf::Keyboard::Key::X, "X" },
            { sf::Keyboard::Key::Y, "Y" },
            { sf::Keyboard::Key::Z, "Z" },
            { sf::Keyboard::Key::Num0, "Num0" },
            { sf::Keyboard::Key::Num1, "Num1" },
            { sf::Keyboard::Key::Num2, "Num2" },
            { sf::Keyboard::Key::Num3, "Num3" },
            { sf::Keyboard::Key::Num4, "Num4" },
            { sf::Keyboard::Key::Num5, "Num5" },
            { sf::Keyboard::Key::Num6, "Num6" },
            { sf::Keyboard::Key::Num7, "Num7" },
            { sf::Keyboard::Key::Num8, "Num8" },
            { sf::Keyboard::Key::Num9, "Num9" },
            { sf::Keyboard::Key::Escape, "Escape" },
            { sf::Keyboard::Key::LControl, "LControl" },
            { sf::Keyboard::Key::LShift, "LShift" },
            { sf::Keyboard::Key::LAlt, "LAlt" },
            { sf::Keyboard::Key::LSystem, "LSystem" },
            { sf::Keyboard::Key::RControl, "RControl" },
            { sf::Keyboard::Key::RShift, "RShift" },
            { sf::Keyboard::Key::RAlt, "RAlt" },
            { sf::Keyboard::Key::RSystem, "RSystem" },
            { sf::Keyboard::Key::Menu, "Menu" },
            { sf::Keyboard::Key::LBracket, "LBracket" },
            { sf::Keyboard::Key::RBracket, "RBracket" },
            { sf::Keyboard::Key::SemiColon, "SemiColon" },
            { sf::Keyboard::Key::Comma, "Comma" },
            { sf::Keyboard::Key::Period, "Period" },
            { sf::Keyboard::Key::Quote, "Quote" },
            { sf::Keyboard::Key::Slash, "Slash" },
            { sf::Keyboard::Key::BackSlash, "BackSlash" },
            { sf::Keyboard::Key::Tilde, "Tilde" },
            { sf::Keyboard::Key::Equal, "Equal" },
            { sf::Keyboard::Key::Dash, "Dash" },
            { sf::Keyboard::Key::Space, "Space" },
            { sf::Keyboard::Key::Return, "Return" },
            { sf::Keyboard::Key::BackSpace, "BackSpace" },
            { sf::Keyboard::Key::Tab, "Tab" },
            { sf::Keyboard::Key::PageUp, "PageUp" },
            { sf::Keyboard::Key::PageDown, "PageDown" },
            { sf::Keyboard::Key::End, "End" },
            { sf::Keyboard::Key::Home, "Home" },
            { sf::Keyboard::Key::Insert, "Insert" },
            { sf::Keyboard::Key::Delete, "Delete" },
            { sf::Keyboard::Key::Add, "Add" },
            { sf::Keyboard::Key::Subtract, "Subtract" },
            { sf::Keyboard::Key::Multiply, "Multiply" },
            { sf::Keyboard::Key::Divide, "Divide" },
            { sf::Keyboard::Key::Left, "Left" },
            { sf::Keyboard::Key::Right, "Right" },
            { sf::Keyboard::Key::Up, "Up" },
            { sf::Keyboard::Key::Down, "Down" },
            { sf::Keyboard::Key::Numpad0, "Numpad0" },
            { sf::Keyboard::Key::Numpad1, "Numpad1" },
            { sf::Keyboard::Key::Numpad2, "Numpad2" },
            { sf::Keyboard::Key::Numpad3, "Numpad3" },
            { sf::Keyboard::Key::Numpad4, "Numpad4" },
            { sf::Keyboard::Key::Numpad5, "Numpad5" },
            { sf::Keyboard::Key::Numpad6, "Numpad6" },
            { sf::Keyboard::Key::Numpad7, "Numpad7" },
            { sf::Keyboard::Key::Numpad8, "Numpad8" },
            { sf::Keyboard::Key::Numpad9, "Numpad9" },
            { sf::Keyboard::Key::F1, "F1" },
            { sf::Keyboard::Key::F2, "F2" },
            { sf::Keyboard::Key::F3, "F3" },
            { sf::Keyboard::Key::F4, "F4" },
            { sf::Keyboard::Key::F5, "F5" },
            { sf::Keyboard::Key::F6, "F6" },
            { sf::Keyboard::Key::F7, "F7" },
            { sf::Keyboard::Key::F8, "F8" },
            { sf::Keyboard::Key::F9, "F9" },
            { sf::Keyboard::Key::F10, "F10" },
            { sf::Keyboard::Key::F11, "F11" },
            { sf::Keyboard::Key::F12, "F12" },
            { sf::Keyboard::Key::F13, "F13" },
            { sf::Keyboard::Key::F14, "F14" },
            { sf::Keyboard::Key::F15, "F15" },
            { sf::Keyboard::Key::Pause, "Pause" },
            { sf::Keyboard::Key::KeyCount, "KeyCount" }
        };

        const std::map< sf::Mouse::Button, std::string > mouse_buttons =
        {
            { sf::Mouse::Button::Left, "Left" },
            { sf::Mouse::Button::Right, "Right" },
            { sf::Mouse::Button::Middle, "Middle" },
            { sf::Mouse::Button::XButton1, "XButton1" },
            { sf::Mouse::Button::XButton2, "XButton2" },
            { sf::Mouse::Button::ButtonCount, "ButtonCount" }
        };

        std::string event_type ( sf::Event::EventType type )
        {
            return event_types.at ( type );
        }
        std::string key_code ( sf::Keyboard::Key key )
        {
            return key_codes.at ( key );
        }
        std::string mouse_button ( sf::Mouse::Button button )
        {
            return mouse_buttons.at ( button );
        }
    } /* namespace converters */
} /* namespace engine */

