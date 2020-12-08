#pragma once
#include "Entity.hpp"
#include <iostream>
using namespace sf;
class Platform : public Entity {
	
public:
	Platform(int y);
	virtual void Moovment();
	void Update();
	
    ~Platform();
};
