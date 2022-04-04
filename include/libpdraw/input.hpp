
/*
 * Libpdraw: A Versitile GUI for use with a primitive drawing system!
 * Copyright (C) 2022 Rebekah Rowe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <string_view>

enum CatKey {
    CATKEY_NONE,
    CATKEY_0,
    CATKEY_1,
    CATKEY_2,
    CATKEY_3,
    CATKEY_4,
    CATKEY_5,
    CATKEY_6,
    CATKEY_7,
    CATKEY_8,
    CATKEY_9,
    CATKEY_A,
    CATKEY_B,
    CATKEY_C,
    CATKEY_D,
    CATKEY_E,
    CATKEY_F,
    CATKEY_G,
    CATKEY_H,
    CATKEY_I,
    CATKEY_J,
    CATKEY_K,
    CATKEY_L,
    CATKEY_M,
    CATKEY_N,
    CATKEY_O,
    CATKEY_P,
    CATKEY_Q,
    CATKEY_R,
    CATKEY_S,
    CATKEY_T,
    CATKEY_U,
    CATKEY_V,
    CATKEY_W,
    CATKEY_X,
    CATKEY_Y,
    CATKEY_Z,

    CATKEY_ESCAPE,
    CATKEY_LBRACKET,
    CATKEY_RBRACKET,
    CATKEY_SEMICOLON,
    CATKEY_APOSTROPHE,
    CATKEY_BACKQUOTE,
    CATKEY_COMMA,
    CATKEY_PERIOD,
    CATKEY_SLASH,
    CATKEY_BACKSLASH,
    CATKEY_MINUS,
    CATKEY_EQUAL,
    CATKEY_ENTER,
    CATKEY_SPACE,
    CATKEY_BACKSPACE,
    CATKEY_TAB,
    CATKEY_CAPSLOCK,

    CATKEY_INSERT,
    CATKEY_DELETE,
    CATKEY_HOME,
    CATKEY_END,
    CATKEY_PAGEUP,
    CATKEY_PAGEDOWN,

    CATKEY_LSHIFT,
    CATKEY_RSHIFT,
    CATKEY_LALT,
    CATKEY_RALT,
    CATKEY_LCONTROL,
    CATKEY_RCONTROL,

    CATKEY_PAD_0,
    CATKEY_PAD_1,
    CATKEY_PAD_2,
    CATKEY_PAD_3,
    CATKEY_PAD_4,
    CATKEY_PAD_5,
    CATKEY_PAD_6,
    CATKEY_PAD_7,
    CATKEY_PAD_8,
    CATKEY_PAD_9,

    CATKEY_PAD_DIVIDE,
    CATKEY_PAD_MULTIPLY,
    CATKEY_PAD_MINUS,
    CATKEY_PAD_PLUS,
    CATKEY_PAD_ENTER,
    CATKEY_PAD_DECIMAL,

    CATKEY_UP,
    CATKEY_LEFT,
    CATKEY_DOWN,
    CATKEY_RIGHT,

    CATKEY_F1,
    CATKEY_F2,
    CATKEY_F3,
    CATKEY_F4,
    CATKEY_F5,
    CATKEY_F6,
    CATKEY_F7,
    CATKEY_F8,
    CATKEY_F9,
    CATKEY_F10,
    CATKEY_F11,
    CATKEY_F12,

    CATKEY_MOUSE_1,
    CATKEY_MOUSE_2,
    CATKEY_MOUSE_3,
    CATKEY_MOUSE_4,
    CATKEY_MOUSE_5,
    CATKEY_M_WHEEL_UP,
    CATKEY_M_WHEEL_DOWN,
    CATKEY_COUNT
};

#include <utility>

#include "functional.hpp"

namespace input {

// Forward defines, meant to be defined by you
bool GetKey(CatKey k);
std::pair<int, int> GetMouse();
std::pair<int, int> GetBounds();

// These are already defined, just use them like normal
extern cat::Event<std::pair<int, int>> bounds_event;
extern cat::Event<std::pair<int, int>> mouse_event;
extern cat::Event<CatKey, bool> key_event;

extern std::string_view key_names[static_cast<int>(CatKey::CATKEY_COUNT)];

// Call to refresh states
void RefreshInput();

} // namespace input
