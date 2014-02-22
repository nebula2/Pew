//CoopSet.h

#ifndef COOPSET_H
#define COOPSET_H

#include "StateManager.h"
#include "IOstuff.h"
#include "MenuSfx.h"

class CoopSet : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
private:
	sf::Event event;
	bool running;
	bool selection;
	int volume;
};

#endif