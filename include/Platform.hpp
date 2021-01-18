#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Game.hpp"

class Platform : public Entity {

public:
    Platform(std::string file_loc);

    //Functions
    void spawnPlatform(Vector2f pos,sf::RenderTarget &tar);
    virtual void Update(Game &game); 
    //virtual void Draw(sf::RenderTarget &tar) const = 0;

    //Override
    virtual void Update( );
    ~Platform();
};