/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** IDisplayModule
*/

#pragma once
#include <memory>

#include "../DataStructures/IDrawable.hpp"
#include "../DataStructures/Event.hpp"
#include "../DataStructures/Sound.hpp"
#include "../DataStructures/Window.hpp"

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
