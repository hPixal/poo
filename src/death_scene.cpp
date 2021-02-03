#include <SFML/Graphics.hpp>
#include <fstream>
#include "death_scene.hpp"
#include "Game.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
using namespace sf;

death_scene::death_scene(RenderWindow &win,int points){
    this->win = &win;
    this->points = points;

    f.loadFromFile("fonts/asap.ttf");
    gameover.loadFromFile("models/game_over.png"    );
    scene_background.loadFromFile("models/death_scene.png");
    button.loadFromFile("models/back_to_menu.png");
    backToMenu.setTexture(button);
    background.setTexture(scene_background);
    gameOver.setTexture(gameover);

    p_display.setFont(f);
    p_display.setString("Your score: "+std::to_string(this->points));

    p_display.setScale(1.25,1.25);
    backToMenu.setScale(0.25,0.25);


    background.setPosition(0,0);
    gameOver.setPosition(center(gameOver.getGlobalBounds(),220));
    backToMenu.setPosition(center(backToMenu.getGlobalBounds(),520));
    p_display.setPosition(center(p_display.getGlobalBounds(),420));
}

Vector2f death_scene::center(FloatRect bounds,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (bounds.width/2),y);
}

void death_scene::Update(Game &g){
    if (this->MouseisInsideBox(backToMenu) && sf::Mouse::isButtonPressed(Mouse::Left))
    {   
        g.SetScene(new Menu(*this->win));
    }
    
}

void death_scene::Draw() const {
    this->win->clear();
    this->win->draw(this->background);
    this->win->draw(this->gameOver);
    this->win->draw(this->backToMenu);
    this->win->draw(this->p_display);
    this->win->display();
}

death_scene::~death_scene() {

}