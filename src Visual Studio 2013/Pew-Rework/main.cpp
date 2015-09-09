//main.cpp

#include "Game.h"

int main(){
	Game pew;
	pew.ChangeState(Game::gameStates::MAINMENU); 

	pew.Run();

	return 0;
}