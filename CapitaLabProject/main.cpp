#include <iostream>
#include <vector>
#include "Game.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	
	Game game;
	game.InitializePlayers();
	game.SetNumberOfPacks();
	game.SetMatchMode();
	game.ShufflingCards();

	game.GameSimulation();
	game.CheckWinner();

	return 0;
}