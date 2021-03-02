#include <SFML/Graphics.hpp>
#include <fstream>
#include <cstring>
#include <string>
#include "death_scene.hpp"
#include "Game.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
#include "hsStruct.hpp"
using namespace std;
using namespace sf;

death_scene::death_scene(RenderWindow &win,int points){
    this->win = &win;
    this->score = points-1; 

    f.loadFromFile("fonts/asap.ttf");
    gameover.loadFromFile("models/game_over.png");
    scene_background.loadFromFile("models/death_scene.png");
    button.loadFromFile("models/home.png");
	button2.loadFromFile("models/back_to_menu.png");
    backToMenu.setTexture(button);
	playAgain.setTexture(button2);
    background.setTexture(scene_background);
    gameOver.setTexture(gameover);

    p_display.setFont(f);
    p_display.setString("Your score: "+std::to_string(this->score));

    p_display.setScale(1.25,1.25);
    backToMenu.setScale(0.25,0.25);
	playAgain.setScale(0.25,0.25);


    background.setPosition(0,0);
    gameOver.setPosition(center(gameOver.getGlobalBounds(),220));
	playAgain.setPosition(win.getDefaultView().getCenter().x-(playAgain.getGlobalBounds().width+2),520);
    backToMenu.setPosition(win.getDefaultView().getCenter().x+2,520);
    p_display.setPosition(center(p_display.getGlobalBounds(),420));
}

Vector2f death_scene::center(FloatRect bounds,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (bounds.width/2),y);
}

void death_scene::Update(Game &g){
    if (this->MouseisInsideBox(backToMenu) && m_ev.type == Event::EventType::MouseButtonPressed)
    {   
        //char caux[20] = "test";
        hsStruct add(g.aux._name,this->score);
        g.AddScore(add); 
        g.SetScene(new Menu(*this->win));
    }
	if (this->MouseisInsideBox(playAgain) && m_ev.type == Event::EventType::MouseButtonPressed)
	{   
		hsStruct add(g.aux._name,this->score);
		g.AddScore(add); 
		g.SetScene(new playScene(*this->win));
	}
    
}

void death_scene::Draw() const {
    this->win->clear();
    this->win->draw(this->background);
    this->win->draw(this->gameOver);
    this->win->draw(this->backToMenu);
	this->win->draw(this->playAgain);
    this->win->draw(this->p_display);
    this->win->display();
}



death_scene::~death_scene() {
	
}

	/*fstream scores("Scores.dat",ios::binary|ios::ate|ios::in|ios::out);
	if(!scores.is_open()){
		cerr << "Error al cargar highscores " << endl;
	}
	if(scores.tellp()/(sizeof(int)+15)<10){
		scores.write(reinterpret_cast<char*>(&_name),sizeof(_name));
	}else{
		scores.seekg(9*(sizeof(int)+15)+15);//para avanzar hasta el ultimo score
		int ultimo;
		scores.read(reinterpret_cast<char*>(&ultimo),sizeof(ultimo));
		if(_points>ultimo){
			//HACER UN VECTOR CON TODOS LOS DATOS DEL ARCHIVO< REEMPLAZAR EL ULTIMO Y ORDENAR
		}
	}*/
	
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




