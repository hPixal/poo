#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "playScene.hpp"
#include "InputBox.hpp"
using namespace sf;

class Menu : public Scene{
    InputText in;;
    //Buttons

    char user[20];
    Font font;
    Texture background;
    Texture title;
    Sprite spr_bg;
    Sprite spr_title;
    std::vector<Texture>buttons;
    std::vector<Sprite>spr_buttons;
    Game* m_g;

public:

    Menu(RenderWindow &win);//Set &win to this->win
    Vector2f center(Sprite &spr,int y);//Returns the coordinates of where does spr needs to be in order to be in the exact center
    void Update(Game &game) override;//It mostly checks wether or not the mouse is clicking the buttons
    void Draw() const override;//Clears the screen and calls for win.draw(_spr) for each _spr in the screen
    void processEvent(Event &ev) override;
    ~Menu();
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