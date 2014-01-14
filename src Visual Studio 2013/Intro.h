//Intro.h

#ifndef INTRO_H
#define INTRO_H

#include "StateManager.h"
#include "MenuSfx.h"
#include "IOsound.h"

class Intro : public StateManager
{
public:
	Intro();
	virtual int Run(sf::RenderWindow &window);
	void setRunning(bool &m_running);
	bool getRunning();
private:
	sf::Event event;
	sf::Clock clock;
	sf::Texture intro;
	sf::Sprite introSprite;
	float elapsedTime;
	float bgSpeed;
	bool running;
	int volume;
};

#endif