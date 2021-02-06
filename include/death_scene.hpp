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