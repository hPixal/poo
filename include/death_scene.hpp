#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include <string>
#include "Game.hpp"
#include "hsStruct.hpp"
using namespace std;
using namespace sf;

/*
Death Scene that pops out when yo lose
*/

class death_scene :public Scene{
    int score;
    //Fonts and Text
    Font f;
    Text p_display;
    Texture button;
    Texture scene_background;
    Texture gameover;
    Sprite gameOver;
    Sprite backToMenu;
    Sprite background;
public:
    death_scene(RenderWindow &win,int points/*,string name*/);//intializes all texts and sprites
    Vector2f center(FloatRect bounds,int y);//centers in the middle of the screen a given sprite
    void Update(Game &g)override; //Checks if the this->backToMenu button is clicked
    void Draw() const override;
    ~death_scene();
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