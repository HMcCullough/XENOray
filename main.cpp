#include "Game/Game.h"

int main(int /*argc*/, char */*argv*/[])
{
	screen(screenWidth, screenHeight, 1, "EPITOME");

	Game game;
	game.RunGame("e1m1");

	return 0;
}
