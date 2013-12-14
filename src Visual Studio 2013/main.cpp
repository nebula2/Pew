//main.cpp

#include <vector>
#include "StateManager.h"
#include "WindowStates.h"

int main()
{
	//StateManager IDs
	std::vector<StateManager*> states;
	int screenState = 0;

	sf::RenderWindow window(sf::VideoMode( 800, 600, 32 ), "Pew");
	window.setFramerateLimit(60);

	//states
	Menu state0;
	states.push_back(&state0);
	Intro state1;
	states.push_back(&state1);
	Settings state2;
	states.push_back(&state2);
	Game state3;
	states.push_back(&state3);
	Settings_tmp state4;
	states.push_back(&state4);
	Highscore state5;
	states.push_back(&state5);
	SoundSet state6;
	states.push_back(&state6);

	

	//runs states & switches between them
	while (screenState >= 0)
	{
		if (screenState == 5)
		{
			state5.setHighscoreManager(state3.getHighScore());
		}
		screenState = states[screenState]->Run(window);
	}
	return 0;
}