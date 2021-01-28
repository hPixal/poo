#include "PlatformEngine.hpp"
#include "playScene.hpp"
#include "Platform.hpp"
#include "static_dirt_platform.hpp"
#include "time.h"


PlatformEngine::PlatformEngine(int platmax) {
    srand(time(NULL));
    this->max_plat=static_cast<size_t>(platmax);
    this->plat_distance = 200;
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
    initial_platform.y = 1024-50;
    current_platforms.push_back(*platformTypes[0]);
    current_platforms[0].spawnPlatform(initial_platform);
}

bool PlatformEngine::getCollision(const Entity &player){
    for (size_t i = 0; i < this->current_platforms.size(); i++)
    {
        if (player.collideWith(current_platforms[i]))
        {
            return true;
        }
    }
    return false;
}

void PlatformEngine::Update(Game &g,View &pl_view,int level){
    for (size_t i = 0; i < current_platforms.size(); i++)
    {
        current_platforms[i].Update(g);

        if (current_platforms[0]._spr.getPosition().y > g.m_window.
            mapPixelToCoords(Vector2i(640,1024),pl_view).y)
        {
            current_platforms.erase(current_platforms.begin());
        }

        if (current_platforms.size() < max_plat)
        {
            current_platforms.push_back(*getNewPlatform(level));
            
            givePos(static_cast<Vector2f>(g.m_window.getSize()),
            current_platforms.size()-2);
        }     
    }
    
    
}

void PlatformEngine::givePos(Vector2f bounds,int prevPlat){
    int aux = rand() % 6 ;
    float spawnPos = (bounds.x / 6) - current_platforms[0]._spr.getScale().x; 
    Vector2f pos;
    float prueba = static_cast<float>(this->current_platforms[prevPlat]._spr.getPosition().y);
    pos.y = prueba - plat_distance;
    pos.x = aux*spawnPos;
    current_platforms[prevPlat+1].spawnPlatform(pos);
}

void PlatformEngine::Draw(RenderWindow &win){
    for (size_t i = 0; i < current_platforms.size(); i++)
    {
        current_platforms[i].Draw(win);
    }
    
    //std::cout << current_platforms[i]._spr.getPosition().y << current_platforms[i]._spr.getPosition().x << std::endl;
}

Platform* PlatformEngine::getNewPlatform(int level){
    int aux;
    
    switch (level)
    {
    case 1:
        return platformTypes[0];
        break;
    case 2:
        aux = rand()%4;
        if (aux == 1)
        {
            return platformTypes[1];
        }else
        {
            return platformTypes[0];
        }
        
    default:
        std::cerr << "ERROR WITH AUX IN GETNEWPLATFOM()" << std::endl;
        break;
    }
    return NULL;
}

PlatformEngine::~PlatformEngine() {

}
