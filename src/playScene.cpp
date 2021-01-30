#include <SFML/Graphics.hpp>
#include "playScene.hpp"
#include "Scene.hpp"
#include "PlatformEngine.hpp"
#include "Game.hpp"

playScene::playScene(RenderWindow &win) {
	this->pl_view = new View(win.getDefaultView().getCenter(),
							 static_cast<Vector2f>(win.getSize()));
	this->win = &win;
	this->win->setView(*pl_view);
	initVariables();
	initBackgrounds();
}

/******************INIT*******************/

void playScene::initVariables(){
	this->points = 1;
	this->plat = new PlatformEngine(10,points);
	this->player = new Player();
}

void playScene::initBackgrounds(){
	backgrounds.resize(3);
	backgrounds[0].loadFromFile("models/cloud_background.png");
	level_background.setTexture(backgrounds[0]);
	//Vector2u aux = backgrounds[0].getSize();
	level_background.setScale(1,1);
	level_background.setOrigin(win->mapPixelToCoords(Vector2i(0,0),*pl_view));
}

/****************LEVEL CHECKER*************/

void playScene::check_level(){
	if (points/100>1)
	{
		level = 2;
	}
	if (points/300>1)
	{
		level = 3;
	}
	if (points/600>1){
		level = 4;
	}
}

/***************DRAW AND UPDATE***********/

void playScene::draw_background(sf::RenderTarget &tar) const {
	tar.draw(this->level_background);
}


void playScene::updateCollision()
{
	//Collision with the bottom of screen
	if (this->player->getPosition().y > win->mapPixelToCoords(Vector2i(0.f,win->getSize().y),*pl_view).y)
	{
        std::cerr << "Muertisimo pa" << std::endl;
		//ADD GAME OVER CALL
	}

	//Collision with borders

	if (player->getPosition().x > win->getSize().x && player->getMovement())
	{
		player->teleport(0-(player->_spr.getGlobalBounds().width));
	}
	if ((player->getPosition().x) < (0  - player->getGlobalBounds().width) && !player->getMovement())
	{
		player->teleport(win->getSize().x);
	}
	
	

	//std::cerr << plat->getCollision(*player) << this->player->isFalling() << std::endl;
	//std::cerr << level << std::endl;

	if (this->player->isFalling() && plat->getCollision(*player))
	{
		
		this->player->bounce();
	}

}

void playScene::updateView(){
	if (player->_spr.getPosition().y < 
	   win->mapPixelToCoords(Vector2i(0,1024/2),*pl_view).y)
	{
		pl_view->setCenter(Vector2f(pl_view->getCenter().x,pl_view->getCenter().y-10.f));
	}
}

void playScene::Update(Game &game)
{
	this->plat->Update(game,*pl_view,this->level);
	this->updatePlayer();
	this->updateCollision();
	this->updateView();
	this->updateBackgound();
	game.m_window.setView(*pl_view);
}


void playScene::updatePlayer(){
	this->player->Update();
	check_level();
}

void playScene::updateBackgound(){
	level_background.setPosition(win->mapPixelToCoords(Vector2i(0,0),*pl_view));
}


void playScene::Draw() const {

	win->clear();
	//Draw background
	draw_background(*win);

	//Render game
	this->plat->Draw(*win);


	this->player->Draw(*win);


	win->display();

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