#include "IngameMusic.h"



void IngameMusic::LoadMusic()
{
	gameTheme.openFromFile("audio//ingamesong.ogg");
	
}

void IngameMusic::PlayMusic(std::string music)
{
	if (music == "ingamesong")
	{
		gameTheme.play();
		gameTheme.setVolume(40);
		gameTheme.setLoop(true);
	}
}

void IngameMusic::getCurrentPosition()
{
	gameTheme.getPlayingOffset();
}
void IngameMusic::Stop()
{
	gameTheme.stop();
}