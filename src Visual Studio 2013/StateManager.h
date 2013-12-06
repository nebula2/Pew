//StateManager.h

#ifndef STATEMANAGER_H
#define STATEMANAGER_H


//includes that I want at all states
#include "GUI.h"
#include <SFML\Graphics.hpp>

//includes the method to run the active state

class StateManager
{
public:
	virtual int Run(sf::RenderWindow &window) = 0;
};


#endif