//Intro.h

#ifndef INTRO_H
#define INTRO_H

#include "StateManager.h"
#include "MenuSfx.h"
#include "IOsound.h"

class Intro : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
private:
	sf::Event event;
	sf::Clock clock;
	float elapsedTime;
	float bgSpeed;
	bool running;
	int volume;
};

#endif