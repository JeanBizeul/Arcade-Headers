/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Text
*/

#pragma once
#include "IDrawable.hpp"
#include <vector>
#include <string>
#include <tuple>

class Text : public IDrawable
{
public:
    std::string getFontPath(void) const;
    std::string getStr(void) const ;
    void setFontPath(std::string fontPath) ;
    void setStr(std::string str);
    
    std::pair<float, float> getScale(void) const override;
    float getRotation(void) const override;
    std::pair<CLI_Color, CLI_Color> getCLI_Color(void) const override;
    std::tuple<int, int, int, int> getGUI_Color(void) const override;
    std::pair<int, int> getPosition(void) const override;
    void setScale(std::pair<float, float> scale) override;
    void setRotation(float rotation) override;
    void setCLI_Color(std::pair<CLI_Color, CLI_Color> CLI_Color) override;
    void setGUI_Color(std::tuple<int, int, int, int> GUI_Color) override;
    void setPosition(std::pair<int, int> position) override;
private:
    std::string fontPath;
	std::string str;

    std::pair<float, float> scale;
	float rotation;
	std::pair<CLI_Color, CLI_Color> CLI_color;
	std::tuple<int, int, int, int> GUI_color;
	std::pair<int, int> position;
};
