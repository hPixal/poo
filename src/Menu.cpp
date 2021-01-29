#include "Menu.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
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


    //Buttons Sprites
    Sprite aux2;
    aux2.setScale(0.70,0.70);
    aux2.setTexture(buttons[0]);
    spr_buttons[0] = aux2;

}

Vector2f Menu::center(Sprite &spr,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (spr.getGlobalBounds().width/2),y);

}

bool Menu::MouseisInsideBox(Sprite spr){
    Vector2f mouse_pos = static_cast<Vector2f>(Mouse::getPosition());
    bool x;
    bool y;
    if (mouse_pos.y > spr.getGlobalBounds().top &&
        mouse_pos.y < (spr.getGlobalBounds().top+spr.getGlobalBounds().height))
    {
        y = true;
    }
    if (mouse_pos.x > spr.getGlobalBounds().left &&
        mouse_pos.x < (spr.getGlobalBounds().left + spr.getGlobalBounds().width))
    {
        x = true;
    }
    
    return true;
    
}


void Menu::Update(Game &game){
    spr_bg.setPosition(0.f,0.f);
    spr_title.setPosition(center(spr_title,230));
    spr_buttons[0].setPosition(center(spr_buttons[0],400));
    if (sf::Mouse::isButtonPressed(Mouse::Left)&& MouseisInsideBox(spr_buttons[0]))
    {
        game.SetScene(new playScene(game.m_window));
        std::cerr << "FUNCA";
    }
    
}

void Menu::Draw() const{
    win->clear();
    win->draw(this->spr_bg);
    win->draw(this->spr_title);
    //for(auto x: spr_buttons)
    //    win->draw(x);
    win->draw(spr_buttons[0]);
    win->display();

}

Menu::~Menu() {

}