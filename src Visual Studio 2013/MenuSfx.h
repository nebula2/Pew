//MenuSfx.h

#ifndef MENUSFX_H
#define MENUSFX_H

#include <SFML\Audio.hpp>
#include <string>

class MenuMusic
{
public:
	void LoadMusic();
	void PlayMusic(std::string music);

private:
	sf::Music menuTheme;
	sf::Music introTheme;
};

class MenuSound
{
public:

	void LoadSoundBuffer();
	void setBuffer();
	void PlaySound(std::string sound);

private:

	sf::SoundBuffer selectBuffer;
	sf::Sound selectSound;
};

#endif