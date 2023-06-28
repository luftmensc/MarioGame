#include "Common.h"
#include "Game.h"

int main()
{
	Game* game= new Game(SPEED);
	game->update();
	delete game;

	return 0;
}