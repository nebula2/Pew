//Music.cpp

#include "Music.h"

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void IngameMusic::LoadMusic(int &volume)
{
	gameTheme.openFromFile("audio//ingamesong.ogg");
	gameTheme.setVolume(volume);
}

void IngameMusic::PlayMusic()
{
		gameTheme.play();
		gameTheme.setLoop(true);
}

void IngameMusic::Pause()
{
	gameTheme.pause();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

void MenuMusic::LoadMusic(int &volume)
{
	menuTheme.openFromFile("audio//menusong.ogg");
	introTheme.openFromFile("audio//introsong.ogg");
	menuTheme.setVolume(volume);
	introTheme.setVolume(volume);
}

void MenuMusic::PlayMusic(std::string music)
{
	if (music == "menu")
	{
		menuTheme.play();
		menuTheme.setLoop(true);
		menuTheme.setPlayingOffset(sf::seconds(8));
	}
	if (music == "intro")
	{
		introTheme.play();
		introTheme.setLoop(true);
	}
}

void MenuMusic::Pause(std::string which)
{
	if (which == "menu")
	{
		menuTheme.pause();
	}
	if (which == "intro")
	{
		introTheme.pause();
	}
}

<<<<<<< HEAD
=======
//ÜBERARBEITEN!!!

void MenuMusic::UnpauseMenu()
{
	if (menuTheme.getStatus() == sf::SoundSource::Paused)
	{
		menuTheme.play();
	}
}

>>>>>>> fceb53ddab56bf7d7c9268c7bcad42670f7806c4
void MenuMusic::MenuVolume(int volume)
{
	menuTheme.setVolume(volume);
}
