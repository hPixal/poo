#include "Scene.hpp"
#include "Game.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Scene::Scene(){

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Scene::MouseisInsideBox(Sprite spr){
    Vector2f mouse_pos = static_cast<Vector2f>(Mouse::getPosition(*win));
    bool x=false;
    bool y=false;
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
    
    if (x&&y)
    {
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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