//MenuSfx.cpp

#include "MenuSfx.h"

//Sound
void MenuSound::LoadSoundBuffer()
{
	selectBuffer.loadFromFile("audio//Select.ogg");
}
void MenuSound::setBuffer(int &volume)
{
	selectSound.setBuffer(selectBuffer);
	selectSound.setVolume(volume);
}

void MenuSound::PlaySound(std::string sound)
{
	if (sound == "select")
		selectSound.play();
}
