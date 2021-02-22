#include "Platform.hpp"
#include "static_dirt_platform.hpp"
#include "moving_dirt_platform.hpp"
Platform::Platform(std::string file_loc) : Entity(file_loc) {
	_spr.setScale(0.10,0.10);
	_spr.setPosition(280,500);
}

int Platform::getpoints(){
	if (canGetPoints)
	{
		canGetPoints = false;
		return points;
	}
	return 0;
}

void Platform::spawnPlatform(Vector2f pos){
	this->_spr.setPosition(pos);
}

bool Platform::collideWith(const Entity & ent2){
	auto r1 = this->_spr.getGlobalBounds();
	auto r2 = ent2._spr.getGlobalBounds();
	r1.height = 10.f;
	
	r2.top = r2.top + r2.height;
	r2.height = 10.f;
	return r2.intersects(r1);
}
/*
void Platform::Draw(sf::RenderTarget &tar)const{
	tar.draw(this->_spr);
}
*/