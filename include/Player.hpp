#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
using namespace sf;


class Player : public Entity{
public:
	Player();
	void Update();
	void initPhysics();
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	
private:
	//Physics
	Vector2f velocity;
	float velocity_max;
	float velocity_min;
	float aceleration;
	float drag;
	float gravity;
};

#endif
