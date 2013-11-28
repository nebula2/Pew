#include <SFML\Graphics.hpp>
#include "WindowState.h"
#include "WindowStateManager.h"

int main()
{
	//Window State IDs
	std::vector<WindowState*> States;
	int screenState = 0;

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Pew");
	window.setFramerateLimit(60);
	
	//States 
	Menu state0;
	States.push_back (&state0);
	Game state1;
	States.push_back (&state1);
	Settings state2;
	States.push_back (&state2);
	Intro state3;
	States.push_back (&state3);
	Settings_tmp state4;
	States.push_back (&state4);
	Highscore state5;	
	States.push_back(&state5);

	while (screenState >= 0)
	{
		if(screenState == 5)
		{
			state5.setHighscoreManager(state1.getHighScore());
		}
		screenState = States[screenState]->Run(window);	
	}

	return 0;
}
