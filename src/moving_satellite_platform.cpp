#include "moving_satellite_platform.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

using namespace sf;

moving_satellite_platform::moving_satellite_platform(std::string filename) : Platform(filename) {
    points = 25;
    m_speed = 10;
    _clk.restart();
    this->_spr.setScale(0.40,0.40);
    m_speed = -m_speed;
    first_lap = true;
}

moving_satellite_platform::moving_satellite_platform(std::string filename,int plusSpeed) : Platform(filename) {
    points = 25;
    m_speed = 5;
    this->m_speed+=plusSpeed; 
    _clk.restart();
    this->_spr.setScale(0.40,0.40);
    m_speed = -m_speed;
    first_lap = true;
}

void moving_satellite_platform::Update(Game &game){
    elap = this->_clk.getElapsedTime();
    if(elap.asSeconds()>1.5 or this->first_lap){
        this->_spr.move(m_speed,0);
        this->first_lap = false;
    }
    if (this->_spr.getPosition().x+this->_spr.getGlobalBounds().width < 0)
    {
        this->_spr.setPosition(Vector2f(game.m_window.getSize().x+
        this->_spr.getGlobalBounds().width,_spr.getPosition().y));
        _clk.restart();
    }
    
    //std::cerr << "SE USA UPDATE" << std::endl;
}

moving_satellite_platform::~moving_satellite_platform(){

}