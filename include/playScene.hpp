#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scene.hpp"
#include "Player.hpp"
#include "PlatformEngine.hpp"
#include "Platform.hpp"
class Game;
class Player;
class Scene;
class PlatformEngine;


class playScene : public Scene {
private:
	//Variables
	PlatformEngine* plat;
	Player* player;
	View* pl_view;
	Font m_font;
	Text p_disp,l_disp;
	std::vector<Texture> backgrounds;
	Sprite level_background;
	Sprite change_background;
	Clock clk;
	Time gtme;
	int max_platforms = 10;
	int points=1;
	int transp=255;
	bool level_change = false;
	//Initializers
	void initVariables();
	void initBackgrounds();

	//Private Functions
	void draw_background(RenderTarget &win) const;
	int level = 1;
public:
	//Functions
	playScene(sf::RenderWindow &win);
	void check_level(); //Increases the level regarding the points got
	void updatePlayer(); //Updates the player's position
	void updateCollision(Game &game); //Updates all collisions
	void updateView(); //Updates the views's center
	void updateBackgound(); //Sets the background regarding the actual level value (WIP)
	void Update(Game &game) override; //<-this
	void Draw() const override; //<-this
	~playScene() override;

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