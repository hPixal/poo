#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "playScene.hpp"
using namespace sf;

class Menu : public Scene{
    //Buttons
    Texture background;
    Texture title;
    Sprite spr_bg;
    Sprite spr_title;
    std::vector<Texture>buttons;
    std::vector<Sprite>spr_buttons;
public:
    Menu(RenderWindow &win);//Set &win to this->win
    Vector2f center(Sprite &spr,int y);//Returns the coordinates of where does spr needs to be in order to be in the exact center
    void Update(Game &game) override;//It mostly checks wether or not the mouse is clicking the buttons
    void Draw() const override;//Clears the screen and calls for win.draw(_spr) for each _spr in the screen
    ~Menu();
};