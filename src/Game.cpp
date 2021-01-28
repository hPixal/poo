#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scene.hpp"
#include "playScene.hpp"
using namespace sf;

Game::Game() 
	: m_window(VideoMode(640,1024),"Skyjump")
{
	m_window.setFramerateLimit(60);
    //FILL WITH FIRST SCENE AS menuScene 
	this->m_scene = new playScene(m_window);
}

void Game::Run ( ) {
	while(m_window.isOpen()) {
		ProcessEvents();
		Update();
		Draw();
		if (m_next_scene) {
			delete m_scene;
			m_scene = m_next_scene;
			m_next_scene = nullptr;
		}
	}
}

void Game::Update ( ) {
	m_scene->Update(*this);
}

void Game::Draw ( ) {
	m_scene->Draw(m_window);
}

void Game::ProcessEvents ( ) {
	//Polling m_window events
	while (this->m_window.pollEvent(this->m_ev))
	{
		if (this->m_ev.type == sf::Event::Closed)
			this->m_window.close();
		else if (this->m_ev.type == sf::Event::KeyPressed && this->m_ev.key.code == sf::Keyboard::Escape)
			this->m_window.close();

		if (
			this->m_ev.type == sf::Event::KeyReleased &&
			(
				this->m_ev.key.code == sf::Keyboard::A ||
				this->m_ev.key.code == sf::Keyboard::D 
				)
			)
		{
		}
	} 
}

Event Game::getEvent(){
	return m_ev;
}

void Game::SetScene (Scene * next_scene) {
	m_next_scene = next_scene;
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