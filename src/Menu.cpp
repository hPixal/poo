#include "Menu.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "highscores_menu.hpp"
#include "InputBox.hpp"
#include <string.h>
#include "instructions_scene.hpp"
#include "playScene.hpp"
using namespace sf;


Menu::Menu(RenderWindow &win) : in(font,30,Color(255,255,255)) {
    this->win = &win; 
    font.loadFromFile("fonts/asap.ttf");
    
    in.setMaxChars(20);
	in.setSingleWord(true);


    in.setPosition(200,570);
    buttons.resize(4);
    spr_buttons.resize(4);

    background.loadFromFile("models/menu_bg.png");
    title.loadFromFile("models/main_title.png");
    
    spr_title.setTexture(title);
    spr_title.setScale(1,1);

    spr_bg.setTexture(background);
    spr_bg.setScale(1,1);

    //Buttons Textures
    Texture aux;
    aux.loadFromFile("models/play_button.png");
    buttons[0] = aux;
    
    aux.loadFromFile("models/highscores.png");
    buttons[1] = aux;
	
	aux.loadFromFile("models/Instructions.png");
	buttons[2] = aux;
	
    Texture tusername;
	tusername.loadFromFile("models/Username.png");
	buttons[3] = tusername;
	
    //Buttons Sprites
    Sprite aux2;

    aux2.setTexture(buttons[0]);
    aux2.setScale(0.70,0.70);
    spr_buttons[0] = aux2;

    aux2.setTexture(buttons[1]);
    aux2.setScale(0.70,0.70);
    spr_buttons[1] = aux2;
	
	aux2.setTexture(buttons[2]);
	aux2.setScale(0.70,0.70);
	spr_buttons[2] = aux2;
	
    Sprite s_username;
	s_username.setTexture(buttons[3]);
	s_username.setScale(0.70,0.70);
	spr_buttons[3] = s_username;

}

Vector2f Menu::center(Sprite &spr,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (spr.getGlobalBounds().width/2),y);

}


void Menu::Update(Game &game){
    m_g = &game;

    spr_bg.setPosition(0.f,0.f);
    spr_title.setPosition(center(spr_title,50));
	for(int i=0;i<4;i++){
		spr_buttons[i].setPosition(center(spr_buttons[i],(200+(100*i))));
	}

    if (m_ev.type == Event::EventType::MouseButtonPressed && MouseisInsideBox(spr_buttons[0]))
    {
        game.SetScene(new playScene(game.m_window));
    }
    if (m_ev.type == Event::EventType::MouseButtonPressed && MouseisInsideBox(spr_buttons[1]))
    {
        game.SetScene(new highscores_menu(game.m_window));
    }
	if (m_ev.type == Event::EventType::MouseButtonPressed && MouseisInsideBox(spr_buttons[2]))
	{
		game.SetScene(new instructuins_scene(game.m_window));
    }
    in.update();
}

void Menu::Draw() const{
    win->clear();
    win->draw(this->spr_bg);
    win->draw(this->spr_title);
    win->draw(in);
    for (size_t i = 0; i < this->spr_buttons.size(); i++)
    {
        win->draw(this->spr_buttons[i]);
    }
    win->display();

}

void Menu::processEvent(Event &ev){
    this->in.processEvent(ev);
    this->m_ev = ev;
}


Menu::~Menu() {
    std::string str = in.getValue();
    if (str != "")
    {
        strcpy(m_g->aux._name,str.c_str());
    }
    /*
    std::cerr<< std::endl;
    std::cout << str << std::endl;
    std::cout << "ponele que funciona" << std::endl;
    */
    }
