#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "playScene.hpp"
#include "Platform.hpp"
using namespace sf;
class PlatformEngine {
    Platform *platformTypes[4];
    std::vector<Platform> current_platforms;
    //var
    int level;
    public:
    PlatformEngine();
    void Update(int level,int i);
    void initTextures();
    void initVector();
    void Draw(RenderWindow &win,int level);
    ~PlatformEngine();
};