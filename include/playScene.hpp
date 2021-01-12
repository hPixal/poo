#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Scene.hpp"
#include "Player.hpp"
class Game;
class Player;
class Scene;

class playScene : public Scene {
private:

	//Variables
	Player* player;
	//std::vector<Platform> current_platforms;
	float spawnTimerMax;
	float spawnTimer;
	int maxPlatforms;
	bool endGame;
	int points;

	//Initializers
	void initVariables();
	void initPlayer();

public:

	//Functions
	playScene();
	void updatePlayer();
	void updateCollision(sf::RenderWindow &win);
	void Update(Game &game) override;
	void Draw(sf::RenderWindow &win) const override;
	const sf::RenderWindow& getWindow() const; 
	~playScene();

};