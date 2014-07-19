//Music.h

/*
Controlles the music in the menu and ingame.
This was first part of the IngameSfx and MenuSfx files.
In order to to get a smooth feeling into the menu the
music will now be controlled in the main.cpp
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>
#include <string>

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Ingame

class IngameMusic
{
public:
	void LoadMusic(int &volume);
	void PlayMusic();
	void Pause();
	void GameVolume(int &volume);
private:
	sf::Music gameTheme;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Menu + Settings

class MenuMusic
{
public:
	void LoadMusic(int &volume);
	void PlayMusic(std::string music);
	void Pause(std::string which);
	void MenuVolume(int &volume);
	void IntroVolume(int &volume);
private:
	sf::Music menuTheme;
	sf::Music introTheme;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif