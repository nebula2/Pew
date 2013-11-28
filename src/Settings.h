#ifndef SETTINGS_H
#define SETTINGS_H

//sfml and windows header
#include <SFML\Graphics.hpp>

//own header
#include "GUIbackgrounds.h"
#include "WindowState.h"
#include "MenuSound.h"
#include "MenuMusic.h"
#include "GUItext.h"

class Settings : public WindowState
{
public:
	virtual int Run(sf::RenderWindow &window);

private:
	bool playing;
	sf::Event event;
	int auswahl;
};
#endif