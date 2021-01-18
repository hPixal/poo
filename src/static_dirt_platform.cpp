#include <iostream>
#include <SFML/Graphics.hpp>
#include "static_dirt_platform.hpp"
#include "Platform.hpp"
#include "Game.hpp"
using namespace sf;
static_dirt_platform::static_dirt_platform(std::string filename) : Platform (filename) {

}

static_dirt_platform::~static_dirt_platform() {

}