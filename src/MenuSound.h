#ifndef MENUSOUND_H
#define MENUSOUND_H

//sfml and windows header
#include <SFML\Audio.hpp>
#include <string>

class MenuSound
{
public:
	
	void LoadSoundBuffer();
	void SetBuffer();
	void PlaySound(std::string sound);

private:

	sf::SoundBuffer selectBuffer;
	sf::Sound selectSound;
};


#endif