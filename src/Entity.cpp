#include "Entity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

Entity::Entity(std::string name){
    _tex.loadFromFile(name);
    _spr.setTexture(_tex);
}

void Entity::draw(RenderWindow &win){
    win.draw(_spr);
}

Entity::~Entity() {

}