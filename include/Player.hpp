#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
using namespace sf;


class Player : public Entity{
public:
	Player();
	void Update();										// Updates all physics and priv vars
	void initPhysics();									//
	void move(const float dir_x);	  					//
	void updatePhysics();								//
	void Draw(RenderTarget & target) override;
	void teleport(int x);
	void bounce();
	//Get Positions
	Vector2f getPosition();
	FloatRect getGlobalBounds();
	//Get States
	bool isFalling();
private:
 
	//Physics
	Vector2f velocity;
	float velocity_max;
	float velocity_min;
	float velocity_max_y;
	float aceleration;
	float drag;
	float gravity;
};

#endif
