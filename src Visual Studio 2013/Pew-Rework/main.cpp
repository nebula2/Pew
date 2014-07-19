//main.cpp

#include <vector>
#include <iostream>
#include "StateManager.h"
#include "WindowStates.h"
#include "IOstuff.h"
#include "Music.h"

int main()
{
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

	//Music
	int volume;
	int volumeCheck = NULL;
	int newVolume = NULL;
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	IngameMusic ingMusic;
	ingMusic.LoadMusic(volume);
	MenuMusic	menMusic;
	menMusic.LoadMusic(volume);
	menMusic.PlayMusic("menu");

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

	while (screenState >= 0)
	{
		//when screen changes
		if (screenState == 5)
			state5.setHighscoreManager(state3.getHighScore());
		
		if (screenState != 3)
			state3.ClearStuff();
		//Control Music
		if (screenState == 1)
		{
			menMusic.Pause("menu");
			menMusic.PlayMusic("intro");
		}

		if (screenState != 3)
			ingMusic.Pause();

		if (screenState == 3)
		{
			menMusic.Pause("menu");
			ingMusic.PlayMusic();
		}

		if (screenState != 1)
			menMusic.Pause("intro");

		if (screenState == 0)
			menMusic.PlayMusic("menu");

		if (screenState != 6)
		{
			iosound.ReadSoundSettings(volumeCheck);
			newVolume = (volume != volumeCheck) ? volumeCheck : volume;
			menMusic.MenuVolume(newVolume);
			menMusic.IntroVolume(newVolume);
			ingMusic.GameVolume(newVolume);
		}	

		//main loop
		screenState = states[screenState]->Run(window);
	}
	return 0;
}