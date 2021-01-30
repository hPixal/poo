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
    virtual void Draw(RenderTarget &tar) const;    //Defines a certain type of behaviour at the time of drawing
    virtual bool collideWith(const Entity & ent2) = 0; //Returns bool for wether 2 objects collide or not
    virtual ~Entity() { }
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
