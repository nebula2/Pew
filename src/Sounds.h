#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML\Audio.hpp>
#include <iostream>
#include <string>

class Sounds
{
public:
	Sounds(std::string soundFile);
	void PlaySound();

private:
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
};

#endif