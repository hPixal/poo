#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
#include "Entity.hpp"

using namespace sf;

class moving_satellite_platform : public Platform{
    int m_speed; //speed of the platform
    Clock _clk;
    Time elap;
    bool first_lap;
public:
    moving_satellite_platform(std::string filename);
    moving_satellite_platform(std::string filename,int plusSpeed);
    void Update(Game &game) override; // This mostly updates the postion of the platform
    ~moving_satellite_platform();
};