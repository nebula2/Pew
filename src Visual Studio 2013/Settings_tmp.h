//Settings_tmp.h

#ifndef SETTINGS_TMP_H
#define SETTINGS_TMP_H

#include "StateManager.h"
#include "MenuSfx.h"

class Settings_tmp : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);

private:
	sf::Event event;
};

#endif