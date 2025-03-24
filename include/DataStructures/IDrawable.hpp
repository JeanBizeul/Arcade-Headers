/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** IDrawable
*/

#pragma once
#include <tuple>

#include "CLI_Colors.hpp"

class IDrawable
{
    public:
        IDrawable(
            std::pair<float, float> scale,
            float rotation,
            std::pair<CLI_Color, CLI_Color> CLI_Color,
            std::tuple<int, int, int, int> GUI_Color,
            std::pair<int, int> position
        ) = delete;
};
