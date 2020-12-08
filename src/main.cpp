 
#include <iostream>
#include "Game.hpp"

int main()
{
	srand(static_cast<unsigned>(time(0)));

	Game game;

	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}

	//End of application
	return 0;
}