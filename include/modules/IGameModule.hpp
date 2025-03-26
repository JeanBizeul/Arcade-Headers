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
#include <memory>

class IGameModule {
    public:
        virtual void start(void) = 0;
        virtual void end(void) = 0;
        virtual void update(float deltaTime) = 0;
        virtual const Window &getWindow(void) = 0;
        virtual const std::vector<IDrawable> &getDrawables(void) = 0;
        virtual const std::vector<Sound> &getSound(void) = 0;
        virtual void event(const Event &events) = 0;
};

std::unique_ptr<IGameModule> getGameModule();