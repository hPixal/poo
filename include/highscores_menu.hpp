#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Menu.hpp"
using namespace sf;

/*
    Highscores menu
*/

class highscores_menu : public Scene{
    //Buttons
    Font f;
    Text scores;
    Texture button;
    Texture scene_background;
    Texture t_title;
	Texture t;
	Texture t2;
	Texture t3;
    Sprite s_title;
    Sprite backToMenu;
    Sprite background;
	Sprite s;
    std::vector<Text> _names;
    std::vector<Text> _scores;
	std::vector<Sprite> medals;
public:
    highscores_menu(RenderWindow &win);
    Vector2f center(FloatRect bounds,int y);
    void Update(Game &g) override;
    void Draw() const override;
    static bool reverse_sort(hsStruct a1,hsStruct a2);
    ~highscores_menu();
};

/*
This file is part of Skyjump.

    Skyjump is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Skyjump is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Skyjump.  If not, see <https://www.gnu.org/licenses/>.
*/
