#pragma once
#define INSTRUCTUINS_SCENE_H
#include "Scene.hpp"

class instructuins_scene : public Scene {
	//buttons
	Texture button;
	Sprite backToMenu;
	
	//background
	Texture scene_background;
	Sprite background;
	
public:
	instructuins_scene(RenderWindow &win);
	void Update (Game & game);
	void Draw ( ) const;
private:
};


