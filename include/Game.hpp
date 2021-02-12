#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Scene.hpp"
#include "hsStruct.hpp"
using namespace sf;
class Scene;

/*
Skyjump main game motor
*/

class Game {
public:
    //Functions
	Game();
	void Run();//Starts the game loop
	void ProcessEvents();//Pulls system events
	void Update();//Updates all sub-classes
	void Draw();//Calls for win.draw() to all sub-classes
	void SetScene(Scene *next_scene);//Deletes old scene and switches to the next
	// Para el sistema de puntajes
	void InitHighScore();//passes the data from the Tanto file to a vector of scores
	void AddScore(hsStruct score);//if the score is higher than the last score saved, it add the score to the scores vector
	std::vector<hsStruct> getHighscore();
	void saveScores();
	~Game();
	
    //Variables
	RenderWindow m_window;
	hsStruct aux;
    Event m_ev;
private:
	std::vector<hsStruct> Scores; 
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
