//Menu.h

#ifndef MENU_H
#define MENU_H

#include "StateManager.h"
#include "MenuSfx.h"
#include "IOsound.h"

class Menu : public StateManager
{
public: 
	virtual int Run(sf::RenderWindow &window);
private:
	bool playing;
	sf::Event event;
	int selection;
	int volume;
};
#endif