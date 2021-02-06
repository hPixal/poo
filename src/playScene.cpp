#include <SFML/Graphics.hpp>
#include "playScene.hpp"
#include "Scene.hpp"
#include "PlatformEngine.hpp"
#include "Game.hpp"
#include "death_scene.hpp"

playScene::playScene(RenderWindow &win) {
	this->pl_view = new View(win.getDefaultView().getCenter(),
							 static_cast<Vector2f>(win.getSize()));
	this->win = &win;
	this->win->setView(*pl_view);
	initVariables();
	initBackgrounds();



	m_font.loadFromFile("fonts/asap.ttf");
	p_disp.setFont(m_font);
	p_disp.setPosition(win.mapPixelToCoords(Vector2i(0,0),*pl_view));
	p_disp.setColor(Color(255,255,255));
	p_disp.setScale(1,1);
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
	if (points/100>1 && level<2)
	{
		level = 2;
	}
	if (points/300>1 && level<3)
	{
		level = 3;
	}
	if (points/600>1 && level<4){
		level = 4;
	}
	if (points/800>1 && level<5)
	{
		level = 5;
	}
	
}

/***************DRAW AND UPDATE***********/

void playScene::draw_background(sf::RenderTarget &tar) const {
	tar.draw(this->level_background);
}


void playScene::updateCollision(Game &game)
{
	//Collision with the bottom of screen
	if (this->player->getPosition().y > 
		win->mapPixelToCoords(Vector2i(0,win->getSize().y + 3*(this->player->_spr.getGlobalBounds().height)),*pl_view).y)
	{
		this->pl_view->setCenter(win->getDefaultView().getCenter());
        game.SetScene(new death_scene(game.m_window,this->points));
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
	
	//Collision with platforms

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
	this->updateCollision(game);
	this->updateView();
	this->updateBackgound();
	game.m_window.setView(*pl_view);
	p_disp.setPosition(game.m_window.mapPixelToCoords(Vector2i(0,0),*pl_view));
	p_disp.setString("Points: "+std::to_string(points-1));
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

	win->draw(p_disp);

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