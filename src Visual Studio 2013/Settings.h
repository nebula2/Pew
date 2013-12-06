//Settings.h

#ifndef SETTINGS_H
#define SETTINGS_H

#include "StateManager.h"
#include "MenuSfx.h"

class Settings : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);

private:
	bool playing;
	sf::Event event;
	int selection;
};

#endif