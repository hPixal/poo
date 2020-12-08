#include "Player.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>


Player::Player() : Entity("models/player.png") {
	_spr.setScale(0.25,0.25);
	_spr.setPosition(280,500); //esta es una posicion cualquiera por ahora xq no se el tamano del jugador
	initPhysics();
	
	
}

Vector2f Player::getPosition(){
	Vector2f pos = _spr.getPosition(); //Retorna las direcciones x e y del jugador
	return pos;
}

FloatRect Player::getGlobalBounds(){
	FloatRect bounds = _spr.getGlobalBounds();
	return bounds;
}


void Player::Update ( ) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) //para mover el jugador a la derecha
		move(+5,0);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) // para mover el jugador a la izquierda
		move(-5,0);
	updatePhysics();
}

void Player::initPhysics ( ) {
	velocity = {1,1};//no se bien con que valores inicializar esto
	velocity_max = 10.f;
	velocity_min = 1.f;
	velocity_max_y = 15.f;
	aceleration = 1.f;
	drag = 0.96;
	gravity = 2.f;
}


void Player::move (const float dir_x, const float dir_y) { //WIP
	//aceleracion
	velocity.x += dir_x*aceleration;
	if(std::abs(velocity.y)>velocity_max_y){
		velocity.x = velocity_max_y*((velocity.y<0.f)? -1.f:1.f);
	}
	//limitar la aceleracion
	if(std::abs(velocity.x)>velocity_max){
		velocity.x = velocity_max*((velocity.x<0.f)? -1.f:1.f);
	}
}

void Player::updatePhysics ( ) {
	//gravedad
	velocity.y += 1.f * gravity;

	//desaceleracion
	velocity *= drag; // multiplico ambos valores de velocity por la desaceleracion con una sobrecarga que posee la clase vector2f
	
	//limitar la desaceleracion
	if(std::abs(velocity.x)<velocity_min)
		velocity.x=0.f;
	if(std::abs(velocity.y)<velocity_min)
		velocity.y=0.f;
	_spr.move(velocity);
}


void Player::render(RenderTarget & target){
	target.draw(this->_spr);
}

