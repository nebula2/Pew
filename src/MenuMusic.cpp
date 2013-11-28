#include "MenuMusic.h"



void MenuMusic::LoadMusic()
{
	menuTheme.openFromFile("audio//menusong.ogg");
	introTheme.openFromFile("audio//introsong.ogg");
	
}

void MenuMusic::PlayMusic(std::string music)
{
	if (music == "menusong")
	{
		menuTheme.play();
		menuTheme.setLoop(true);
		menuTheme.setPlayingOffset(sf::seconds(8));
	}
	if (music == "introsong")
	{
		introTheme.play();
		introTheme.setLoop(true);
	}
}