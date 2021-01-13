#include <SFML/Graphics.hpp>
#include "playScene.hpp"
#include "Scene.hpp"
#include "Game.hpp"

playScene::playScene(){
	initVariables();
	initPlayer();
	initBackgrounds();
}

/******************INIT*******************/

void playScene::initVariables(){
	this->endGame = false;
	this->spawnTimerMax = 5.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxPlatforms = 20;
	this->points = 1;
}


void playScene::initPlayer()
{
	this->player = new Player();
}

void playScene::initBackgrounds(){
	backgrounds.resize(3);
	backgrounds[0].loadFromFile("models/cloud_background.png");
	level_background.setTexture(backgrounds[0]);
	//Vector2u aux = backgrounds[0].getSize();
	level_background.setScale(1,1);
	level_background.setOrigin(0,0);
}

/****************LEVEL CHECKER*************/

void playScene::check_level(){
	if (points%100!=0)
	{
		level++;
	}
}

/***************DRAW AND UPDATE***********/

void playScene::draw_background(sf::RenderTarget &tar) const {
	tar.draw(this->level_background);
}


void playScene::updateCollision(RenderWindow &win)
{
	Vector2f pos = this->player->getPosition();
	//Collision with the bottom of screen
	if (pos.y + this->player->getGlobalBounds().height > win.getSize().y)
	{
        //ADD GAME OVER SCENE CALL
	}
	if (pos.x > win.getSize().y -11)
	{
		player->teleport(-player->getGlobalBounds().width+10);
	}
	if (pos.x+player->getGlobalBounds().width < 11)
	{
		player->teleport(win.getSize().y-10);
	}
	//std::cout << pos.x << std::endl;
}


void playScene::Update(Game &game)
{
	this->updatePlayer();
	this->updateCollision(game.m_window);
}


void playScene::updatePlayer(){
	this->player->Update();
	check_level();
}




void playScene::Draw(RenderWindow &win) const {
	win.clear();
	
	//Draw background
	draw_background(win);

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