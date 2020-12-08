#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>


Player::Player() : Entity("player.png") {
	_spr.setScale(0.5,0.5);
	_spr.setPosition(280,950); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
	initPhysics();
	
	
}


void Player::Update ( ) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) //para mover el jugador a la derecha
		move(+5,0);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) // para mover el jugador a la izquierda
		move(-5,0);
	
	
}
void Player::initPhysics ( ) {
	velocity = {1,1};//no se bien con que valores inicializar esto
	velocity_max = 10.f;
	velocity_min = 1.f;
	aceleration = 1.f;
	drag = 0.96;
}


void Player::move (const float dir_x, const float dir_y) {
	//aceleracion
	velocity.x += dir_x*aceleration;
	//limitar la aceleracion
	if(std::abs(velocity.x)>velocity_max){
		velocity.x = velocity_max*((velocity.x<0.f)? -1.f:1.f);
	}
}

void Player::updatePhysics ( ) {
	//desaceleracion
	velocity *= drag; // multiplico ambos valores de velocity por la desaceleracion con una sobrecarga que posee la clase vector2f
	//limitar la desaceleracion
	if(std::abs(velocity.x)<velocity_min)
		velocity.x=0.f;
	if(std::abs(velocity.y)<velocity_min)
		velocity.y=0.f;
	_spr.move(velocity);
}
