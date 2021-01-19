#include <iostream>
#include <SFML/Graphics.hpp>
#include "static_dirt_platform.hpp"
#include "Platform.hpp"
#include "Game.hpp"
using namespace sf;
static_dirt_platform::static_dirt_platform(std::string filename) : Platform (filename) {

}

void static_dirt_platform::Update(Game &game) { 
	this->Draw(game.m_window); 
}


static_dirt_platform::~static_dirt_platform() {

}