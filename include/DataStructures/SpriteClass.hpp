/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** SpriteClass
*/

#pragma once
#include "IDrawable.hpp"
#include <vector> 
#include <iostream> 

class SpriteClass : public IDrawable
{
    public:
        SpriteClass() {};

        std::vector<std::string> GUI_Textures;
        std::vector<char[2]>  CLI_Textures;
        float animationTime;

        std::pair<float, float> getScale() const override;
        float getRotation() const override;
        std::pair<CLI_Color, CLI_Color> getCLI_Color() const override;
        std::tuple<int, int, int, int> getGUI_Color() const override;
        std::pair<int, int> getPosition() const override;
        void setScale(std::pair<float, float> scale) override;
        void setRotation(float rotation) override;
        void setCLI_Color(std::pair<CLI_Color, CLI_Color> CLI_Color) override;
        void setGUI_Color(std::tuple<int, int, int, int> GUI_Color) override;
        void setPosition(std::pair<int, int> position) override;

        std::vector<std::string> getGUI_Textures() const;
        std::vector<char[2]> getCLI_Textures() const;
        float getAnimationTime() const;
        void setGUI_Textures(std::vector<std::string> GUI_Textures);
        void setCLI_Textures(std::vector<char[2]> CLI_Textures);
        void setAnimationTime(float animationTime);

};
