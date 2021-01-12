#include "Platform.hpp"

Platform::Platform() : Entity("models/platform_dirt.png") {
	_spr.setScale(0.25,0.25);
	_spr.setPosition(280,500); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
}

Platform::~Platform() {

}