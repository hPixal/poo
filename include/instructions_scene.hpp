#pragma once
#include "Scene.hpp"
#include "Platform.hpp"
#include "moving_dirt_platform.hpp"

class instructuins_scene : public Scene {


	//buttons
	Texture button;
	Sprite backToMenu;

	Texture button2;
	Sprite next;
	bool nextpage;

	//Tutorial Img

	Texture tut;
	Sprite tutorial;
	
	//background
	Texture scene_background;
	Sprite background;

	//Plaforms

	Texture dirt;
	Sprite dirt_plat;

	Texture cloud;
	Sprite cloud_plat;

	Texture satellite;
	Sprite satellite_plat;

	moving_dirt_platform moving;

	//Texts

	Font cs;
	Text tdir;
	Text tcloud;
	Text tsatellite;
	Text tmoving;

	//Clock
	Clock clk;

public:
	instructuins_scene(RenderWindow &win);
	void Update (Game & game);
	Vector2f center(Sprite &spr,int y);
	Vector2f center(Text &spr,int y);
	void Draw ( ) const;
private:
};


