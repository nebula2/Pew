//main.cpp

#include <vector>
#include <iostream>
#include "StateManager.h"
#include "WindowStates.h"
#include "IOscreen.h"

int main()
{
	bool m_running = true;

	//StateManager IDs
	std::vector<StateManager*> states;
	int screenState = 0;

	//create window
	IOscreen ioscreen;
	
	sf::RenderWindow window;
	window.setFramerateLimit(60);
	
	if (ioscreen.getScreenSettings())
	{
		window.create(sf::VideoMode(800, 600, 32), "Pew", sf::Style::Fullscreen);
		window.setMouseCursorVisible(false);
	}
	else
	{
		window.create(sf::VideoMode(800, 600, 32), "Pew", sf::Style::Default);
	}

	//states
	Menu state0;
	states.push_back(&state0);
	Intro state1;
	states.push_back(&state1);
	Settings state2;
	states.push_back(&state2);
	Game state3;
	states.push_back(&state3);
	GraphicSet state4;
	states.push_back(&state4);
	Highscore state5;
	states.push_back(&state5);
	SoundSet state6;
	states.push_back(&state6);
	DiffSet state7;
	states.push_back(&state7);
	CoopSet state8;
	states.push_back(&state8);

	

	//runs states & switches between them
	while (screenState >= 0)
	{
		//main loop
		screenState = states[screenState]->Run(window);

		//when screen changes
		if (screenState == 5)
		{
			state5.setHighscoreManager(state3.getHighScore());
		}
		else if (screenState == 1)
		{
			m_running = true;
			state1.setRunning(m_running);
		}
		else if (screenState != 1)
		{
			m_running = false;
			state1.setRunning(m_running);
		}
		else if (screenState != 3)
		{
			state3.ClearStuff();
		}

		std::cout << screenState << " screenState" << std::endl;
		std::cout << m_running << " m_running" << std::endl;
		std::cout << state1.getRunning() << "intro bool" << std::endl;
	}
	return 0;
}