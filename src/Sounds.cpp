#include "Sounds.h"

Sounds::Sounds(std::string soundFile)
{
	
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(soundFile))
	{
	std::cout << "fuck";
	}
	sound.setBuffer(soundBuffer);
}

void Sounds::PlaySound()
{
	sound.play();
}