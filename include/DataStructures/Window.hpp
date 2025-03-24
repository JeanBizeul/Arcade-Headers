/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** Window
*/

#pragma once
#include <tuple>
#include <string>

class Window
{
    public:
        Window(
        std::pair<int, int> size,
        std::string title,
        std::string iconPath
        ) : size(size), title(title), iconPath(iconPath) {};

        const std::pair<int, int> size;
        const std::string title;
        const std::string iconPath;
};
