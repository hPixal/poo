#include "Game.hpp"



Game::Game() {
    this->initWindow();
}


Game::~Game() {

}

void Game::initWindow(){
    RenderWindow window(sf::VideoMode(600,1000), "SFML works!", Style::Close | Style::Titlebar );
    _window.setFramerateLimit(60);
}

void Game::render(){
    this->_window.clear();
    this->_window.display();
}


void Game::update(){
    while (this->_window.pollEvent(this->_ev))
    {
        if (this->_ev.type == Event::Closed)
        {
            this->_window.close();
        }else if (_ev.type == Event::KeyPressed && _ev.key.code == Keyboard::Escape)
        {
            this->_window.close();
        }
        
        
    }
    
}