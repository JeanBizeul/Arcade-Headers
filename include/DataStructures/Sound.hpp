/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** Sound
*/

#pragma once
#include <string>

class Sound
{
    public:
        enum State {
            PLAY,
            STOP,
            LOOP
        };
        Sound(
            std::string filePath,
            Sound::State state,
            std::string id,
            bool unique = true
        ) : filePath(filePath), state(state), id(id), unique(unique) {};

        const std::string filePath;
        const Sound::State state;
        const std::string id;
        const bool unique = true;
};
