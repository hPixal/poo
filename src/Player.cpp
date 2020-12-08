#include "Player.h"
#include <SFML/Window/Keyboard.hpp>


Player::Player() : Entity("player.png") {
	_spr.setScale(0.5,0.5);
	_spr.setPosition(280,950); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
}


void Player::Update ( ) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) //para mover el jugador a la derecha
		_spr.move(+5,0);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) // para mover el jugador a la izquierda
		_spr.move(-5,0);
}

