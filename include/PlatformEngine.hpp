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
    int plat_distance;
    size_t max_plat;
    int level;
    public:
    PlatformEngine(int platmax); //<-- constructor
    void Update(Game &g,int level,int i);
    void initTextures();
    void initVector();
    void givePos(Vector2f bounds,int prevPlat);
    void Draw(RenderWindow &win,int i);
    Platform* getNewPlatform(int level);
    ~PlatformEngine();
};