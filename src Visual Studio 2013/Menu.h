//Menu.h

#ifndef MENU_H
#define MENU_H

#include "StateManager.h"
#include "MenuSfx.h"
#include "IOsound.h"

class Menu : public StateManager
{
public: 
	Menu();
	virtual int Run(sf::RenderWindow &window);
	void setPlaying(bool &mPlaying);
	bool getPlaying();
private:
	bool playing;
	sf::Event event;
	int selection;
	int volume;
};
#endif