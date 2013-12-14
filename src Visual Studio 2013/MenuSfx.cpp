//MenuSfx.cpp

#include "MenuSfx.h"

//Music
void MenuMusic::LoadMusic(int &volume)
{
	menuTheme.openFromFile("audio//menusong.ogg");
	introTheme.openFromFile("audio//introsong.ogg");
	menuTheme.setVolume(volume);
	introTheme.setVolume(volume);

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

//Sound
void MenuSound::LoadSoundBuffer()
{
	selectBuffer.loadFromFile("audio//select.ogg");
}
void MenuSound::setBuffer(int &volume)
{
	selectSound.setBuffer(selectBuffer);
	selectSound.setVolume(volume);
}

void MenuSound::PlaySound(std::string sound)
{
	if (sound == "select")
	{
		selectSound.play();
	}
}
