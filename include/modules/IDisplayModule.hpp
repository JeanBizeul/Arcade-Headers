/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** IDisplayModule
*/

#pragma once
#include "IDrawable.hpp"
#include "Event.hpp"
#include "Sound.hpp"
#include "Window.hpp"
#include <memory>

class IDisplayModule
{
    public:
        virtual void createWindow(const Window &window) = 0;
        virtual void draw(const IDrawable &to_draw) = 0;
        virtual void display(void) = 0;
        virtual void clear(void) = 0;
        virtual Event getEvent(void) = 0;
        virtual void handleSound(const Sound &sound) = 0;
};                                                                             

std::unique_ptr<IDisplayModule> getDisplayModule();
