#include "Platform.hpp"

Platform::Platform(std::string file_loc) : Entity(file_loc) {
	_spr.setScale(0.25,0.25);
	_spr.setPosition(280,500); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
}

void Platform::spawnPlatform(Vector2f pos,sf::RenderTarget &tar){
	_spr.setPosition(pos);
	this->Update();
	this->Draw(tar);
}

void Platform::Update(Game &game) { 
	this->Draw(game.m_window); 
}

Platform::~Platform() {

}