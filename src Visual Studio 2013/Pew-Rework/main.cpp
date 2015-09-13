//main.cpp

#include "Game.h"

int main(){
	Game pew;
	pew.ChangeState(Game::gameStates::SPLASHSTATE); 

	pew.Run();

	return 0;
}