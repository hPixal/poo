#include "PlatformEngine.hpp"
#include "playScene.hpp"
#include "Platform.hpp"
#include "static_dirt_platform.hpp"
PlatformEngine::PlatformEngine() {
    initTextures();
    initVector();
}

void PlatformEngine::initTextures() {
    platformTypes[0] = new static_dirt_platform("models/platform_dirt.png");
    //ADD MORE PLAT TYPES AND TEXTURES
}

void PlatformEngine::initVector(){
    Vector2f initial_platform;
    initial_platform.x = 280;
    initial_platform.y = 100;
    current_platforms.push_back(*platformTypes[0]);
    current_platforms[0].spawnPlatform(initial_platform,)
}

void PlatformEngine::Update(RenderWindow &win,int level,int i){
    current_platforms[i].Update();
    if (current_platforms[0]._spr.getPosition().y )
    {
        /* code */
    }
    
}

void PlatformEngine::Draw(RenderWindow &win,int level){
    for (int i = 0; i < 40; i++)
    {
        /* code */
    }
    
}

PlatformEngine::~PlatformEngine() {

}