#include "Menu.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "highscores_menu.hpp"
#include "InputBox.hpp"
#include <string.h>
#include "instructuins_scene.hpp"
#include "playScene.hpp"
using namespace sf;


Menu::Menu(RenderWindow &win) : in(font,20,Color(255,255,255)) {
    this->win = &win; 
    font.loadFromFile("fonts/asap.ttf");
    
    in.setMaxChars(20);
	in.setSingleWord(true);


    in.setPosition(200,800);
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
	
	aux.loadFromFile("models/Username.png");
	buttons[3] = aux;
	
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
	
	aux2.setTexture(buttons[3]);
	aux2.setScale(0.70,0.70);
	spr_buttons[3] = aux2;

}

Vector2f Menu::center(Sprite &spr,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (spr.getGlobalBounds().width/2),y);

}


void Menu::Update(Game &game){
    spr_bg.setPosition(0.f,0.f);
    spr_title.setPosition(center(spr_title,100));
	for(int i=0;i<4;i++){
		spr_buttons[i].setPosition(center(spr_buttons[i],(200+(100*i))));
	}
    this->win->pollEvent(game.m_ev);
    if (game.m_ev.type == sf::Event::KeyPressed && game.m_ev.key.code==sf::Keyboard::Return) {
				std::string str = in.getValue();
				char caux[20];
                strcpy(caux,str.c_str());
                for (int i = 0; i < 20; i++)
                {
                    game.aux._name[i] = caux[i];
                }
                std::cerr << "Funca" << std::endl;
				in.reset(); // reiniciar la entrada para tomar otra palabra
			} else in.processEvent(game.m_ev);

    if (sf::Mouse::isButtonPressed(Mouse::Left) && MouseisInsideBox(spr_buttons[0]))
    {
        game.SetScene(new playScene(game.m_window));
    }
    if (sf::Mouse::isButtonPressed(Mouse::Left) && MouseisInsideBox(spr_buttons[1]))
    {
        game.SetScene(new highscores_menu(game.m_window));
    }
	if (sf::Mouse::isButtonPressed(Mouse::Left) && MouseisInsideBox(spr_buttons[2]))
	{
		game.SetScene(new instructuins_scene(game.m_window));
	}
	

    in.update();


}

void Menu::inUpdate(){
    this->in.update();
}

void Menu::Draw() const{
    win->clear();
    win->draw(this->spr_bg);
    win->draw(this->spr_title);
    //for(auto x: spr_buttons)
    //    win->draw(x);
    for (size_t i = 0; i < 4/*this->spr_buttons.size()*/; i++)
    {
        win->draw(this->spr_buttons[i]);
    }
    win->draw(in);

    win->display();

}

Menu::~Menu() {

}
