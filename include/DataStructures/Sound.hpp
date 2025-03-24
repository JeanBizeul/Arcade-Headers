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
        );
};
