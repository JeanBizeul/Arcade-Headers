/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** keys
*/

#pragma once

namespace Key
{
    enum KeyStatus {
        KEY_PRESSED,
        KEY_RELEASED
    };
    struct MousePos {
        int x;
        int y;
    };
    enum KeyCode {
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,

        KEY_0,
        KEY_1,
        KEY_2,
        KEY_3,
        KEY_4,
        KEY_5,
        KEY_6,
        KEY_7,
        KEY_8,
        KEY_9,

        KEY_MOUSE_LEFT,
        KEY_MOUSE_MIDDLE,
        KEY_MOUSE_RIGHT,
        KEY_MOUSE_BUTTON_4,
        KEY_MOUSE_BUTTON_5,
        KEY_MOUSE_SCROLL,

        KEY_SPACE,
        KEY_ENTER,
        KEY_TAB,
        KEY_ECHAP,
        KEY_SUPPR,

        KEY_FUNCTION_1,
        KEY_FUNCTION_2,
        KEY_FUNCTION_3,
        KEY_FUNCTION_4,
        KEY_FUNCTION_5,
        KEY_FUNCTION_6,
        KEY_FUNCTION_7,
        KEY_FUNCTION_8,
        KEY_FUNCTION_9,
        KEY_FUNCTION_10,
        KEY_FUNCTION_11,
        KEY_FUNCTION_12,

        KEY_LEFT,
        KEY_UP,
        KEY_RIGHT,
        KEY_DOWN,

        KEY_L_SHIFT,
        KEY_R_SHIFT,
        KEY_L_CONTROL,
        KEY_R_CONTROL,
        KEY_ALT,
        KEY_ALTGR,
    };
}
