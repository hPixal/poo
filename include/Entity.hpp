#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Entity {
protected:
    Texture _tex;
public:
    Sprite _spr;
    Entity(std::string name);        //Recibes the name of the file to load the texture from
    virtual void Draw(RenderTarget &tar);    //Defines a certain type of behaviour at the time of drawing
    bool collideWith(const Entity & ent2) const ; //Returns bool for wether 2 objects collide or not
    ~Entity();
};
