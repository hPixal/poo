#pragma once
#include "Entity.hpp"
#include <iostream>
using namespace sf;

class Platform : public Entity {

public:
    Platform(int _y){
        
    }
    virtual void move();
    ~Platform();
};