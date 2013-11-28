#include "MenuSound.h"


void MenuSound::LoadSoundBuffer()
{
	selectBuffer.loadFromFile("audio//select.ogg");
}
void MenuSound::SetBuffer()
{
	selectSound.setBuffer(selectBuffer);
}

void MenuSound::PlaySound(std::string sound)
{
	if (sound == "select")
	{
		selectSound.play();
	}
}
