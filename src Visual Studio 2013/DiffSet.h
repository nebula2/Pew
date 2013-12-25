//DiffSet.h

#ifndef DIFFSET_H
#define DIFFSET_H

#include "StateManager.h"
#include "IOdiff.h"
#include "IOsound.h"
#include "MenuSfx.h"

class DiffSet : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
private:
	sf::Event event;
	bool running;
	int selection;
	int volume;
};

#endif