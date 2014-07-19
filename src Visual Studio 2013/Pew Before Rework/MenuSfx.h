//MenuSfx.h

#ifndef MENUSFX_H
#define MENUSFX_H

#include <SFML/Audio.hpp>
#include <string>

class MenuSound
{
public:

	void LoadSoundBuffer();
	void setBuffer(int &volume);
	void PlaySound(std::string sound);

private:

	sf::SoundBuffer selectBuffer;
	sf::Sound selectSound;
};

#endif