//GraphicSet.h

#ifndef GRAPHICSET_H
#define GRAPHICSET_H

#include "StateManager.h"
#include "IOsound.h"
#include "IOscreen.h"
#include "IOsmooth.h"
#include "MenuSfx.h"

class GraphicSet : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
private:
	sf::Event event;
	bool running;
	bool selectionH;
	bool selectionV;
	int volume;
	bool isSmooth;
	bool isFull;
};

#endif