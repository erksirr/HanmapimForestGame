#include "Game.h"
#include <time.h>
#include <iostream>
#include "Enemy.h"
int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	Game game; 
	game.run();
	return 0;
}
