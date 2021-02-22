#include "moving_dirt_platform.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

using namespace sf;

moving_dirt_platform::moving_dirt_platform(std::string filename) : Platform(filename) {
    this->_spr.setScale(1,1);
    points = 15;
    m_speed = 5;
}

moving_dirt_platform::moving_dirt_platform(std::string filename,int plusSpeed) : Platform(filename) {
    this->_spr.setScale(1,1);
    points = 15;
    m_speed = 5;
    this->m_speed+=plusSpeed; 
}

void moving_dirt_platform::Update(Game &game){
    this->_spr.move(m_speed,0);
    if (this->_spr.getPosition().x < 0 or
        this->_spr.getPosition().x + _spr.getGlobalBounds().width > game.m_window.getSize().x)
    {
        m_speed = -m_speed;
    }
    //std::cerr << "SE USA UPDATE" << std::endl;
}
