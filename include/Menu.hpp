#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "playScene.hpp"
using namespace sf;

class Menu : public Scene{
    RenderWindow* win;
    Texture background;
    Texture title;
    Sprite spr_bg;
    Sprite spr_title;
    std::vector<Texture>buttons;
    std::vector<Sprite>spr_buttons;
public:
    Menu(RenderWindow &win);
    Vector2f center(Sprite &spr,int y);
    bool MouseisInsideBox(Sprite spr);
    void Update(Game &game) override;
    void Draw() const override;
    ~Menu();
};