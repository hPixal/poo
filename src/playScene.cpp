#include <SFML/Graphics.hpp>
#include "playScene.hpp"
#include "Scene.hpp"
#include "Game.hpp"

playScene::playScene(){
	initPlayer();
	initVariables();
}

void playScene::initVariables(){
	this->endGame = false;
	this->spawnTimerMax = 5.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxPlatforms = 20;
	this->points = 0;
}

void playScene::updateCollision(RenderWindow &win)
{
	//Collision with the bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > win.getSize().y)
	{
        //ADD GAME OVER SCENE CALL
	}
}

void playScene::Update(Game &game)
{
	this->updatePlayer();
	this->updateCollision(game.m_window);
}


void playScene::Draw(RenderWindow &win) const {

	win.clear();

	//Render game
	this->player->render(win);

	win.display();

}

playScene::~playScene(){

}

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