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
        enum Key::KeyCode key;
        std::any value;
};
