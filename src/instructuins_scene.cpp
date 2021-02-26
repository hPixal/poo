#include "instructuins_scene.hpp"
#include "Menu.hpp"

instructuins_scene::instructuins_scene(RenderWindow &win) {
	this->win = &win; 
	
	scene_background.loadFromFile("models/menu_bg.png");
	background.setTexture(scene_background);
	background.setScale(1,1);
	background.setPosition(0,0);
	
	button.loadFromFile("models/back_to_menu.png");
	backToMenu.setTexture(button);
	backToMenu.setScale(0.10,0.10);
	backToMenu.setPosition(300,100);

	
	
}

void instructuins_scene::Update (Game & game) {
	if (Mouse::isButtonPressed(Mouse::Left) && this->MouseisInsideBox(backToMenu))
	{
		game.SetScene(new Menu(*win));
	}
}

void instructuins_scene::Draw ( ) const {
	this->win->clear();
	this->win->draw(background);
	this->win->draw(backToMenu);
	this->win->display();
}

