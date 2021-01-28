#include <SFML/Graphics.hpp>
#include "playScene.hpp"
#include "Scene.hpp"
#include "PlatformEngine.hpp"
#include "Game.hpp"

playScene::playScene(RenderWindow &win) {
	this->pl_view = new View(Vector2f(0.f,0.f),static_cast<Vector2f>(win.getSize()));
	this->pl_view->setCenter(win.getDefaultView().getCenter());
	win.setView(*pl_view);
	initVariables();
	initBackgrounds(win);
}

/******************INIT*******************/

void playScene::initVariables(){
	this->points = 1;
	this->plat = new PlatformEngine(10);
	this->player = new Player();
}

void playScene::initBackgrounds(RenderWindow &win){
	backgrounds.resize(3);
	backgrounds[0].loadFromFile("models/cloud_background.png");
	level_background.setTexture(backgrounds[0]);
	//Vector2u aux = backgrounds[0].getSize();
	level_background.setScale(1,1);
	level_background.setOrigin(win.mapPixelToCoords(Vector2i(0,0),*pl_view));
}

/****************LEVEL CHECKER*************/

void playScene::check_level(){
	if (points%100==0)
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
	if (pos.y > win.mapPixelToCoords
	   (Vector2i(0,win.getSize().y),*pl_view).y)
	{
        std::cerr << "Muertisimo pa" << std::endl;
		//ADD GAME OVER CALL
	}

	//Collision with borders

	if (pos.x > win.getSize().y -11)
	{
		player->teleport(-player->getGlobalBounds().width+10);
	}
	if (pos.x+player->getGlobalBounds().width < 11)
	{
		player->teleport(win.getSize().y-10);
	}

	std::cerr << plat->getCollision(*player) << this->player->isFalling() << std::endl;

	if (this->player->isFalling() && plat->getCollision(*player))
	{
		
		this->player->bounce();
	}

}

void playScene::updateView(sf::RenderWindow &win){
	if (player->_spr.getPosition().y < 
	   win.mapPixelToCoords(Vector2i(0,1024/2),*pl_view).y)
	{
		pl_view->setCenter(Vector2f(pl_view->getCenter().x,pl_view->getCenter().y-10.f));
	}
}

void playScene::Update(Game &game)
{
	this->plat->Update(game,*pl_view,this->level);
	this->updatePlayer();
	this->updateCollision(game.m_window);
	this->updateView(game.m_window);
	this->updateBackgound(game.m_window);
	game.m_window.setView(*pl_view);
}


void playScene::updatePlayer(){
	this->player->Update();
	check_level();
}

void playScene::updateBackgound(sf::RenderWindow &win){
	level_background.setPosition(win.mapPixelToCoords(Vector2i(0,0),*pl_view));
}


void playScene::Draw(RenderWindow &win) const {

	win.clear();
	//Draw background
	draw_background(win);

	//Render game
	this->plat->Draw(win);


	this->player->Draw(win);


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