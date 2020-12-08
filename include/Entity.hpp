#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
    Texture _tex;
protected:
    Sprite _spr;
public:
    Entity(std::string name);        //Recibes the name of the file to load the texture from
    void draw(RenderWindow &win);    //Defines a certain type of behaviour at the time of drawing

    ~Entity();
};
