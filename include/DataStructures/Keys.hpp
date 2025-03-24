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

        MOUSE_LEFT,
        MOUSE_MIDDLE,
        MOUSE_RIGHT,
        MOUSE_BUTTON_4,
        MOUSE_BUTTON_5,
        MOUSE_SCROLL,

        SPACE,
        ENTER,
        TAB,
        ECHAP,
        SUPPR,

        FUNCTION_1,
        FUNCTION_2,
        FUNCTION_3,
        FUNCTION_4,
        FUNCTION_5,
        FUNCTION_6,
        FUNCTION_7,
        FUNCTION_8,
        FUNCTION_9,
        FUNCTION_10,
        FUNCTION_11,
        FUNCTION_12,

        LEFT,
        UP,
        RIGHT,
        DOWN,

        L_SHIFT,
        R_SHIFT,
        L_CONTROL,
        R_CONTROL,
        ALT,
        ALTGR,
    };
}
