#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
using namespace sf;

/*
Skyjump main game motor
*/
class Scene;

class Game {
public:
    //Functions
	Game();
	void Run();
	void ProcessEvents();
	void Update();
	void Draw();
	void SetScene(Scene *next_scene);
    Event getEvent();
    //Variables
    Event m_ev;
	RenderWindow m_window;
private:
	Scene *m_scene;
	Scene *m_next_scene = nullptr;
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