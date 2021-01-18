#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Game.hpp"
using namespace sf;

class static_dirt_platform : public Platform{

public:
    static_dirt_platform(std::string filename);
    void static_dirt_platform::Draw(RenderTarget &tar) override;
    ~static_dirt_platform();
};