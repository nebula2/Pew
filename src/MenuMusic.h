#ifndef MENUMUSIC_H
#define MENUMUSIC_H

//sfml and windows header
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
#endif