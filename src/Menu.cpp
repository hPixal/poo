#include "Menu.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "highscores_menu.hpp"
using namespace sf;


Menu::Menu(RenderWindow &win) {
    this->win = &win;

    buttons.resize(3);
    spr_buttons.resize(3);

    background.loadFromFile("models/menu_bg.jpg");
    title.loadFromFile("models/main_title.png");
    
    spr_title.setTexture(title);
    spr_title.setScale(1,1);

    spr_bg.setTexture(background);
    spr_bg.setScale(0.35,0.35);

    //Buttons Textures
    Texture aux;
    aux.loadFromFile("models/play_button.png");
    buttons[0] = aux;
    
    aux.loadFromFile("models/highscores.png");
    buttons[1] = aux;


    //Buttons Sprites
    Sprite aux2;

    aux2.setTexture(buttons[0]);
    aux2.setScale(0.70,0.70);
    spr_buttons[0] = aux2;

    aux2.setTexture(buttons[1]);
    aux2.setScale(0.70,0.70);
    spr_buttons[1] = aux2;


}

Vector2f Menu::center(Sprite &spr,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (spr.getGlobalBounds().width/2),y);

}


void Menu::Update(Game &game){
    spr_bg.setPosition(0.f,0.f);
    spr_title.setPosition(center(spr_title,230));
    spr_buttons[0].setPosition(center(spr_buttons[0],400));
    spr_buttons[1].setPosition(center(spr_buttons[1],600));
    if (sf::Mouse::isButtonPressed(Mouse::Left)&& MouseisInsideBox(spr_buttons[0]))
    {
        game.SetScene(new playScene(game.m_window));
    }
    if (sf::Mouse::isButtonPressed(Mouse::Left)&& MouseisInsideBox(spr_buttons[1]))
    {
        game.SetScene(new highscores_menu(game.m_window));
    }
    
}

void Menu::Draw() const{
    win->clear();
    win->draw(this->spr_bg);
    win->draw(this->spr_title);
    //for(auto x: spr_buttons)
    //    win->draw(x);
    for (size_t i = 0; i < 2/*this->spr_buttons.size()*/; i++)
    {
        win->draw(this->spr_buttons[i]);
    }
    
    win->display();

}

Menu::~Menu() {

}