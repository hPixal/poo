#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
#include "playScene.hpp"
#include "hsStruct.hpp"
#include <fstream>
using namespace std;
using namespace sf;

Game::Game() 
	: m_window(VideoMode(640,1024),"Skyjump")
{
	char fname[20] = "anonimo";
	for (int i = 0; i < 20; i++)
	{
		aux._name[i]=fname[i];
	}
	aux._points = 0;
	m_window.setFramerateLimit(60);
    //FILL WITH FIRST SCENE AS menuScene 
	this->m_scene = new Menu(m_window);
	this->InitHighScore();
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
	m_scene->Draw();
}

void Game::ProcessEvents ( ) {
	//Polling m_window events
	while (this->m_window.pollEvent(this->m_ev))
	{
		if (this->m_ev.type == sf::Event::Closed){
			this->saveScores();
			this->m_window.close();
		}
		else if (this->m_ev.type == sf::Event::KeyPressed && this->m_ev.key.code == sf::Keyboard::Escape){
			this->saveScores();
			this->m_window.close();
		}
		else{
			this->m_scene->processEvent(this->m_ev);
		}
	} 
}

void Game::SetScene (Scene * next_scene) {
	m_next_scene = next_scene;
}

void Game::InitHighScore ( ) {
	ifstream file("bin/HighScores.bin",ios::binary|ios::in|ios::ate);
	if(!file){
		cerr << "/n The file could not be opened n/" ;
		ofstream newFile("bin/HighScores.bin", ios::trunc | ios::binary);
		newFile.close();
		for (int i = 0; i < 10; i++)
		{
			char caux[20] = "___";
			hsStruct aux(caux,0);
			Scores.push_back(aux);
		}
		this->saveScores();
	}
	int can = file.tellg()/sizeof(hsStruct);
	file.seekg(0);

	hsStruct p;
	for(int i=0; i<can;++i){
		file.read(reinterpret_cast<char*>(&p),sizeof(hsStruct));
		Scores.push_back(p);
			if(Scores.size()>10){
				cerr << "/n error initializing vector n/";
		}
	}
	
	file.close();
}

void Game::AddScore (hsStruct score) {

	if(Scores[0]._points<score._points){
		Scores[0] = score;
		sort(Scores.begin(),Scores.end());
	}
	saveScores();
}

vector<hsStruct> Game::getHighscore(){
	this->saveScores();
	return this->Scores;
}

void Game::saveScores(){
	ofstream file("bin/HighScores.bin",ios::ate|ios::binary|ios::out|ios::trunc);
	
	for(size_t i=0; i<Scores.size();++i){
		hsStruct aux = Scores[i];
		file.write(reinterpret_cast<char*>(&aux),sizeof(hsStruct));
	}
	
	file.close();
}

Game::~Game ( ) {
	
 
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


