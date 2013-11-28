#ifndef MENU_H
#define MENU_H

//sfml and windows header
#include <SFML\Graphics.hpp>
#include <iostream>
//own header
#include "GUIbackgrounds.h"
#include "WindowState.h"
#include "MenuSound.h"
#include "MenuMusic.h"

class Menu : public WindowState
{
public:
	virtual int Run(sf::RenderWindow &window);
	Menu();
private:
	bool playing;
	sf::Event event;
	int auswahl;
};
#endif
