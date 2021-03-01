#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
using namespace sf;
class Game;

/*
This is the mother class of all scenes of the game. It dictates the way that all scenes must be
composed just so Game class can accept and display them.
*/

class Scene {
protected:
    Event m_ev;
    RenderWindow* win;
public:
    Scene();
    virtual void Update(Game &game) = 0; //All scenes must have it's own overrided update functi
                                         //and a game to output data
    virtual void Draw() const = 0; //All scenes must have an overrided draw
                                                        //function and get window to display itself
    bool MouseisInsideBox(Sprite spr); //checks if mouse is inside spr 
    virtual void processEvent(sf::Event &ev){ m_ev = ev; }
    virtual ~Scene(){};
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