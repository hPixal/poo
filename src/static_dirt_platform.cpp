#include <iostream>
#include <SFML/Graphics.hpp>
#include "static_dirt_platform.hpp"
#include "Platform.hpp"
#include "Game.hpp"
using namespace sf;
static_dirt_platform::static_dirt_platform(std::string filename) : Platform (filename) {
	_spr.setScale(1,1);
}

void static_dirt_platform::Update(Game &game) { 
	this->Draw(game.m_window); 
}

void static_dirt_platform::Draw(sf::RenderTarget &tar){
	tar.draw(this->_spr);
}

bool static_dirt_platform::collideWith(const Entity & ent2) const{
	FloatRect aux = this->_spr.getGlobalBounds();
	aux.height=1;
	FloatRect aux2 = ent2._spr.getGlobalBounds();
	aux2.top+=aux2.height-1;
	aux2.height=1;
	if (aux.intersects(aux2))
	{
		return true;
	}
	return false;
}


static_dirt_platform::~static_dirt_platform() {

}