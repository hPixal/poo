#include "Platform.hpp"

Platform::Platform(std::string file_loc) : Entity(file_loc) {
	_spr.setScale(0.25,0.25);
	_spr.setPosition(280,500); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
}

void Platform::spawnPlatform(Vector2f pos){
	_spr.setPosition(pos);
	//this->Update();
}

void Platform::Update(Game &game) { 
	this->Draw(game.m_window); 
}

void Platform::Draw(sf::RenderTarget &tar){
	tar.draw(this->_spr);
}

Platform::~Platform() {

}