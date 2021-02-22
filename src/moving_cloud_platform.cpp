#include "moving_cloud_platform.hpp"

moving_cloud_platform::moving_cloud_platform(std::string filename) : Platform(filename) {
    this->_spr.setScale(0.60,0.60);
    points = 15;
    m_speed = 5;
}


moving_cloud_platform::moving_cloud_platform(std::string filename,int plusSpeed) : Platform(filename) {
    this->_spr.setScale(0.60,0.60);
    points = 15;
    m_speed = 5;
    this->m_speed+=plusSpeed;
}

void moving_cloud_platform::Update(Game &game){
    
    this->_spr.move(m_speed,0);
    if (this->_spr.getPosition().x < 0 or
        this->_spr.getPosition().x + _spr.getGlobalBounds().width > game.m_window.getSize().x)
    {
        m_speed = -m_speed;
    }

    if (!canBounce && transp>5)
    {
        transp-=10;
        _spr.setColor(Color(255,255,255,transp));
    }
    if (transp<5)
    {
        _spr.setColor(Color(255,255,255,0));
    }
    
}

bool moving_cloud_platform::collideWith(const Entity & ent2) {
    auto r1 = this->_spr.getGlobalBounds();
	auto r2 = ent2._spr.getGlobalBounds();
	r1.height = 10.f;
	
	r2.top = r2.top + r2.height;
	r2.height = 10.f;
	if (r2.intersects(r1) && this->canBounce)
    {
        this->canBounce=false;
        return true;
    }
    return false;
}

moving_cloud_platform::~moving_cloud_platform(){

}