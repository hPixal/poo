#include "Scene.hpp"
#include "Game.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Scene::Scene(){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Scene::MouseisInsideBox(Sprite spr){
    tme = clk.getElapsedTime();
    Vector2f mouse_pos = static_cast<Vector2f>(Mouse::getPosition(*win));
    bool x;
    bool y;
    if (mouse_pos.y > spr.getPosition().y &&
        mouse_pos.y < (spr.getPosition().y+spr.getGlobalBounds().height))
    {
        y = true;
    }
    if (mouse_pos.x > spr.getPosition().x &&
        mouse_pos.x < (spr.getPosition().x + spr.getGlobalBounds().width))
    {
        x = true;
    }
    
    if (x&&y&&(tme.asSeconds() > 0.2 || fclick))
    {
        clk.restart();
        fclick = false;
        return true;
    }
    return false;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Clock Scene::clk;

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