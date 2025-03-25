/*
** EPITECH PROJECT, 2025
** Arcade-Headers
** File description:
** TextClass
*/

#pragma once
#include "IDrawable.hpp"
#include <vector> 
#include <iostream> 

class TextClass : public IDrawable
{
    public:
        TextClass() {};

        std::string fontPath;
        std::string str;

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

        std::string getFontPath() const;
        std::string getStr() const;
        void setFontPath(std::string fontPath);
        void setStr(std::string str);
};
