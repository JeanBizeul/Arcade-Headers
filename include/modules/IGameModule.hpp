/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** IGameModule
*/

#pragma once
#include <vector>
#include <memory>

#include "Window.hpp"
#include "IDrawable.hpp"
#include "Sound.hpp"
#include "Event.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual bool update(float deltaTime) = 0;
        virtual const Window &getWindow(void) = 0;
        virtual const std::vector<std::unique_ptr<IDrawable>> &getDrawables(void) = 0;
        virtual const std::vector<Sound> &getSound(void) = 0;
        virtual bool event(const Event &events) = 0;
        virtual std::vector<std::pair<std::string, int>> getScores(void) = 0;
};

// extern "C" std::unique_ptr<IGameModule> getGameModule();
