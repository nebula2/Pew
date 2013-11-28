#ifndef INGAMEMUSIC_H
#define INGAMEMUSIC_H

//sfml and windows header
#include <SFML\Audio.hpp>
#include <string>

class IngameMusic
{
public:
	void LoadMusic();
	void PlayMusic(std::string music);
	void getCurrentPosition();
	void Stop();
private:
	sf::Music gameTheme;
};
#endif