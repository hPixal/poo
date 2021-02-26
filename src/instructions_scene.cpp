#include "instructions_scene.hpp"
#include "Menu.hpp"

instructuins_scene::instructuins_scene(RenderWindow &win) : moving("models/platform_dirt.png") {
	this->win = &win; 
	this->nextpage = false;

	//Texts

	cs.loadFromFile("fonts/cs.ttf");
	
	tdir.setFont(cs);
	tcloud.setFont(cs);
	tcloud.setFont(cs);
	tsatellite.setFont(cs);
	tmoving.setFont(cs);
	

	tdir.setString("These are dirt platforms,\n they don't have any special effects");
	tcloud.setString("These are cloud platforms, \n they disappear after you jump once");
	tsatellite.setString("These are satellite platforms, \n they orbit in only 1 direction \n and move fast");
	tmoving.setString("Be careful! certain platforms can move");

	//Sizes for text

	tdir.setScale(0.75,0.75);
	tcloud.setScale(0.75,0.75);
	tsatellite.setScale(0.75,0.75);
	tmoving.setScale(0.75,0.75);

	//Set Textures

	scene_background.loadFromFile("models/menu_bg.png");//
	background.setTexture(scene_background);			// Background
	background.setScale(1,1); 							//

	// For buttons

	button.loadFromFile("models/back_to_menu.png");     //
	backToMenu.setTexture(button);						// Back button
	backToMenu.setScale(0.10,0.10);						//

	button2.loadFromFile("models/next.png");			//
	next.setTexture(button2);							// Next button
	next.setScale(0.30,0.30); 							//

	tut.loadFromFile("models/screenshots/tutorial.png");//
	tutorial.setTexture(tut);							// Tutorial image
	tutorial.setScale(0.70,0.70);						//
	
	// For platforms

	dirt.loadFromFile("models/platform_dirt.png");		//
	dirt_plat.setTexture(dirt);							// Dirt plat
	dirt_plat.setScale(0.85,0.85);						//

	cloud.loadFromFile("models/platform_cloud.png");
	cloud_plat.setTexture(cloud);
	cloud_plat.setScale(0.65,0.65);

	satellite.loadFromFile("models/platform_satellite.png");
	satellite_plat.setTexture(satellite);
	satellite_plat.setScale(0.25,0.25);


	//Positions

	background.setPosition(0,0);
	backToMenu.setPosition(center(backToMenu,100));
	tutorial.setPosition(center(tutorial,backToMenu.getPosition().y+75));
	next.setPosition(center(next,900));

	//Positions for platforms

	dirt_plat.setPosition(30,this->backToMenu.getPosition().y+100);
	cloud_plat.setPosition(30,this->dirt_plat.getPosition().y+200);
	satellite_plat.setPosition(30,this->cloud_plat.getPosition().y+200);
	moving.spawnPlatform(Vector2f(30,this->satellite_plat.getPosition().y+200));

	//Positions for Text

	tdir.setPosition(dirt_plat.getPosition().x+155,dirt_plat.getPosition().y);
	tcloud.setPosition(cloud_plat.getPosition().x+155,cloud_plat.getPosition().y);;
	tsatellite.setPosition(satellite_plat.getPosition().x+155,satellite_plat.getPosition().y);;
	tmoving.setPosition(center(tmoving,moving._spr.getPosition().y+40));


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void instructuins_scene::Update (Game & game) {

	if (Mouse::isButtonPressed(Mouse::Left) && this->MouseisInsideBox(backToMenu))
	{
		game.SetScene(new Menu(*win));
	}else if(Mouse::isButtonPressed(Mouse::Left) && this->MouseisInsideBox(next)){
		this->nextpage = !nextpage;
	}

	moving.Update(game);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vector2f instructuins_scene::center(Sprite &spr,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (spr.getGlobalBounds().width/2),y);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Vector2f instructuins_scene::center(Text &txt,int y){
    return Vector2f(win->getDefaultView().getCenter().x - (txt.getGlobalBounds().width/2),y);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void instructuins_scene::Draw ( ) const {
	//Must draw
	this->win->clear();
	this->win->draw(background);
	this->win->draw(backToMenu);
	this->win->draw(next);
	// Page sections
	if (nextpage)
	{
		this->win->draw(dirt_plat);
		this->win->draw(tdir);
		this->win->draw(cloud_plat);
		this->win->draw(tcloud);
		this->win->draw(satellite_plat);
		this->win->draw(tsatellite);
		moving.Draw(*win);
		this->win->draw(tmoving);
	}else{
		this->win->draw(tutorial);
	}
	
	this->win->display();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////