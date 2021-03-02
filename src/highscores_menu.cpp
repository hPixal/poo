#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"
#include "highscores_menu.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
using namespace sf;


highscores_menu::highscores_menu(RenderWindow &win) {
    this->win = &win; 
	//medals
	t.loadFromFile("models/medalla1.png");
	s.setTexture(t);
	medals.push_back(s);
	
	t2.loadFromFile("models/medalla2.png");
	s.setTexture(t2);
	medals.push_back(s);
	
	t3.loadFromFile("models/medalla3.png");
	s.setTexture(t3);
	medals.push_back(s);
	

    f.loadFromFile("fonts/asap.ttf");
    scene_background.loadFromFile("models/menu_bg.png");
    button.loadFromFile("models/home.png");
    t_title.loadFromFile("models/highscore_title.png");
    scores.setFont(f);

    background.setTexture(scene_background);
    backToMenu.setTexture(button);
    s_title.setTexture(t_title);

    scores.setString("Top 10 Highscores:");

    background.setScale(1,1);
    backToMenu.setScale(0.25,0.25);
    scores.setScale(1,1);

    scores.setPosition(center(scores.getGlobalBounds(),320));
    backToMenu.setPosition(center(backToMenu.getGlobalBounds(),900));
    background.setPosition(0,0);
    s_title.setPosition(center(s_title.getGlobalBounds(),60));   

    _names.resize(10);
    _scores.resize(10);
    for (int i = 0; i < 10; i++)
    {
        _names[i].setFont(f);
        _scores[i].setFont(f);
    }
    


}

Vector2f highscores_menu::center(FloatRect bounds,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (bounds.width/2),y);
}
void highscores_menu::Update(Game &g){
    int pos = 400;
    if (m_ev.type == Event::EventType::MouseButtonPressed && this->MouseisInsideBox(backToMenu))
    {
        g.SetScene(new Menu(*win));
    }
    std::vector<hsStruct> highscore = g.getHighscore();
    sort(highscore.begin(),highscore.end(),reverse_sort);
	
	for(int i=0;i<3;++i){
		medals[i].setScale(0.2,0.2);
		medals[i].setPosition(Vector2f(20,pos+40*(i+1)));
	}

    for (size_t i = 0; i < highscore.size() ; i++)
    {
        _names[i].setString(highscore[i]._name);
        _scores[i].setString(std::to_string(highscore[i]._points));
        _names[i].setScale(1,1);
        _names[i].setPosition(Vector2f(60,pos+40*(i+1)));
        _scores[i].setScale(1,1);
        _scores[i].setPosition(Vector2f(640-(_scores[i].getGlobalBounds().width+20),pos+40*(i+1)));
    }
        

}
void highscores_menu::Draw() const{
    this->win->clear();
    this->win->draw(background);
    this->win->draw(s_title);
    this->win->draw(scores);
	for(size_t i=0;i<medals.size();++i){
		this->win->draw(medals[i]);
	}
    for (size_t i = 0; i < _names.size(); i++)
    {
        this->win->draw(_names[i]);
        this->win->draw(_scores[i]);
    }
    
    this->win->draw(backToMenu);
    this->win->display();
}

bool highscores_menu::reverse_sort(hsStruct a1,hsStruct a2){
   return a2._points<a1._points;
}

highscores_menu::~highscores_menu() {

}
