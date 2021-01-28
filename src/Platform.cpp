#include "Platform.hpp"

int Platform::getpoints(){
	if (canGetPoints)
	{
		canGetPoints = false;
		return 10;
	}
	return 0;
}

Platform::Platform(std::string file_loc) : Entity(file_loc) {
	_spr.setScale(0.20,0.20);
	_spr.setPosition(280,500); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
}

void Platform::spawnPlatform(Vector2f pos){
	_spr.setPosition(pos);
	//this->Update();
}

void Platform::Update(Game &game) { 
	this->Draw(game.m_window); 
}

bool Platform::collideWith(const Entity & ent2) const{
	auto r1 = this->_spr.getGlobalBounds();
	auto r2 = ent2._spr.getGlobalBounds();
	r1.height = 2.f;
	
	r2.height=1.f;
	return r1.intersects(r2);
}

void Platform::Draw(sf::RenderTarget &tar){
	tar.draw(this->_spr);
}
