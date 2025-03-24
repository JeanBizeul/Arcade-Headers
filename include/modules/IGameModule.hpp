/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** IGameModule
*/

#pragma once
#include <vector>
#include "Window.hpp"
#include "IDrawable.hpp"
#include "Sound.hpp"
#include "Event.hpp"

class IGameModule {
    public:
        virtual void start(void) = 0;
        virtual void end(void) = 0;
        virtual void update(float deltaTime) = 0;
        virtual Window getWindow(void) = 0;
        virtual std::vector<IDrawable> getDrawables(void) = 0;
        virtual std::vector<Sound> getSound(void) = 0;
        virtual void event(Event) = 0;
};
