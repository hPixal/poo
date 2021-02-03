#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "highscores_menu.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
using namespace sf;


highscores_menu::highscores_menu(RenderWindow &win) {
    this->win = &win; 

    f.loadFromFile("fonts/asap.ttf");
    scene_background.loadFromFile("models/menu_bg.jpg");
    button.loadFromFile("models/back_to_menu.png");
    t_title.loadFromFile("models/highscore_title.png");
    scores.setFont(f);

    background.setTexture(scene_background);
    backToMenu.setTexture(button);
    s_title.setTexture(t_title);

    scores.setString("Una prueba nomas");

    background.setScale(0.35,0.35);
    backToMenu.setScale(0.25,0.25);
    scores.setScale(1,1);

    scores.setPosition(center(scores.getGlobalBounds(),320));
    backToMenu.setPosition(center(backToMenu.getGlobalBounds(),760));
    background.setPosition(0,0);
    s_title.setPosition(center(s_title.getGlobalBounds(),60));



}

Vector2f highscores_menu::center(FloatRect bounds,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (bounds.width/2),y);
}
void highscores_menu::Update(Game &g){
    if (Mouse::isButtonPressed(Mouse::Left) && this->MouseisInsideBox(backToMenu))
    {
        g.SetScene(new Menu(*win));
    }
}
void highscores_menu::Draw() const{
    this->win->clear();
    this->win->draw(background);
    this->win->draw(s_title);
    this->win->draw(scores);
    this->win->draw(backToMenu);
    this->win->display();
}

highscores_menu::~highscores_menu() {

}