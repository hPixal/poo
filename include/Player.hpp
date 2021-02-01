#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
using namespace sf;


class Player : public Entity{
public:
	Player();
	void Update();										// 
	void initPhysics();									//  Updates all physics and priv vars
	void move(const float dir_x);	  					//
	void updatePhysics();								//
	bool collideWith(const Entity & ent2) override;
	void Draw(RenderTarget & target) const override;
	void teleport(int x); // Teleports the play to given x value
	bool getMovement(); // Returns true if moving right, false if moving left
	void bounce(); //Makes the player bounce
	//Get Positions
	Vector2f getPosition(); //Returns the current player position
	FloatRect getGlobalBounds(); //Rerturns this->_spr.getGlobalBounds()
	//Get States
	bool isFalling(); //Returns true if the player is falling
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
