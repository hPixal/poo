#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scene.hpp"
#include "Player.hpp"
#include "PlatformEngine.hpp"
class Game;
class Player;
class Scene;

class playScene : public Scene {
private:
	//Variables
	PlatformEngine plat;
	Player* player;
	std::vector<Texture> backgrounds;
	Sprite level_background;
	int points;

	//Initializers
	void initVariables();
	void initPlayer();
	void initBackgrounds();

	//Private Functions
	void draw_background(RenderTarget &win) const;
	int level;
public:
	//Functions
	playScene();
	void check_level();
	void updatePlayer();
	void updateCollision(sf::RenderWindow &win);
	void Update(Game &game) override;
	void Draw(sf::RenderWindow &win) const override;
	const sf::RenderWindow& getWindow() const; 
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