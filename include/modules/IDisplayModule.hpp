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
#include <memory>

class IDisplayModule
{
    public:
        virtual void draw(IDrawable) = 0;
        virtual void display(void) = 0;
        virtual void clear(void) = 0;
        virtual Event getEvent(void) = 0;
        virtual void handleSound(Sound) = 0;
};                                                                             

std::unique_ptr<IDisplayModule> getDisplayModule();
