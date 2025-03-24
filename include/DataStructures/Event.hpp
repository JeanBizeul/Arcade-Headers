/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** Event
*/

#pragma once
#include <any>
#include <Keys.hpp>

class Event
{
    public:
        Event(
            enum Key::KeyCode key,
            std::any value
        ): key(key), value(value) {};

        const enum Key::KeyCode key;
        const std::any value;
};
