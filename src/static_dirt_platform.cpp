#include <iostream>
#include <SFML/Graphics.hpp>
#include "static_dirt_platform.hpp"
#include "Platform.hpp"
#include "Game.hpp"
using namespace sf;
static_dirt_platform::static_dirt_platform(std::string filename) : Platform (filename) {
	_spr.setScale(3,3);
}

void static_dirt_platform::Update(Game &game) { 
	this->Draw(game.m_window); 
}

void static_dirt_platform::Draw(sf::RenderTarget &tar){
	tar.draw(this->_spr);
}

static_dirt_platform::~static_dirt_platform() {

}