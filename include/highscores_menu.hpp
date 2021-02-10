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
    Sprite s_title;
    Sprite backToMenu;
    Sprite background;
    vector<Text> _names;
    vector<Text> _scores;
public:
    highscores_menu(RenderWindow &win);
    Vector2f center(FloatRect bounds,int y);
    void Update(Game &g) override;
    void Draw() const override;
    static bool reverse_sort(hsStruct a1,hsStruct a2);
    ~highscores_menu();
};