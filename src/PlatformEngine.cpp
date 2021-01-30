#include "PlatformEngine.hpp"
#include "playScene.hpp"
#include "Platform.hpp"
#include "static_dirt_platform.hpp"
#include "moving_dirt_platform.hpp"
#include "static_cloud_platform.hpp"
#include "moving_cloud_platform.hpp"
#include "time.h"


PlatformEngine::PlatformEngine(int platmax, int &points) {
    srand(time(NULL));
    this->getpoits=&points;
    this->max_plat=static_cast<size_t>(platmax);
    this->plat_distance = 200;
    initVector();
}


void PlatformEngine::initVector(){
    Vector2f initial_platform;
    initial_platform.x = 280;
    initial_platform.y = 1024-50;
    current_platforms.push_back(new static_dirt_platform("models/platform_dirt.png"));
    current_platforms[0]->spawnPlatform(initial_platform);
}

bool PlatformEngine::getCollision(const Entity &player){
    for (size_t i = 0; i < this->current_platforms.size(); i++)
    {
        if (current_platforms[i]->collideWith(player))
        {
            *getpoits+=current_platforms[i]->getpoints();
            return true;
        }
    }
    return false;
}

void PlatformEngine::Update(Game &g,View &pl_view,int level){
    for (size_t i = 0; i < current_platforms.size(); i++)
    {

        if (current_platforms[0]->_spr.getPosition().y > g.m_window.
            mapPixelToCoords(Vector2i(640,1024),pl_view).y)
        {
            current_platforms.erase(current_platforms.begin());
        }

        if (current_platforms.size() < max_plat)
        {
            current_platforms.push_back(getNewPlatform(level));
            
            givePos(static_cast<Vector2f>(g.m_window.getSize()),
            current_platforms.size()-2);
        }

        current_platforms[i]->Update(g);
    }
    
    
}

void PlatformEngine::givePos(Vector2f bounds,int prevPlat){
    int aux = rand() % 6 ;
    float spawnPos = (bounds.x - current_platforms[0]->_spr.getGlobalBounds().width)/6; 
    Vector2f pos;
    float prueba = static_cast<float>(current_platforms[prevPlat]->_spr.getPosition().y);
    pos.y = prueba - plat_distance;
    pos.x = aux*spawnPos;
    current_platforms[prevPlat+1]->spawnPlatform(pos);
}

void PlatformEngine::Draw(RenderWindow &win){
    for (size_t i = 0; i < current_platforms.size(); i++)
    {
        current_platforms[i]->Draw(win);
    }
}

Platform* PlatformEngine::getNewPlatform(int level){
    int aux;
    
    switch (level)
    {
    case 1:
        return new static_dirt_platform("models/platform_dirt.png");
        break;
    case 2:
        aux = rand()%6;
        if(aux == 1)
        {
            return new moving_dirt_platform("models/platform_dirt.png");
        }else
        {
            return new static_dirt_platform("models/platform_dirt.png");
        }
    case 3:
        aux = rand()%6;
        if(aux == 1)
        {
            return new moving_dirt_platform("models/platform_dirt.png");
        }else if (aux==2 || aux == 3)
        {
            return new static_cloud_platform("models/platform_cloud.png");
        }else
        {
            return new static_dirt_platform("models/platform_dirt.png");
        }
    case 4:
        aux= rand()%6;
        if(aux == 1)
        {
            return new moving_cloud_platform("models/platform_cloud.png");
        }else if (aux==2 || aux == 3)
        {
            return new static_cloud_platform("models/platform_cloud.png");
        }else if (aux==4)
        {
            return new moving_dirt_platform("models/platform_dirt.png");
        }else
        {
            return new static_dirt_platform("models/platform_dirt.png");
        }
        
        
            
    default:
        std::cerr << "ERROR WITH AUX IN GETNEWPLATFOM()" << std::endl;
        break;
    }
    return NULL;
}

PlatformEngine::~PlatformEngine() {

}
