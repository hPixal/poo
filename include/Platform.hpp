#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

class Platform : public Entity {

public:
    Platform(std::string file_loc);

    //Functions
    void spawnPlatform(Vector2f pos);
    virtual void Update(Game &game); 
    void Draw(sf::RenderTarget &tar);

    //Override
    virtual void Update( );
    ~Platform();
};