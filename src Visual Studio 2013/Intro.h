//Intro.h

#ifndef INTRO_H
#define INTRO_H

#include "StateManager.h"


class Intro : public StateManager
{
public:
	Intro();
	virtual int Run(sf::RenderWindow &window);
private:
	sf::Event event;
	sf::Clock clock;
	sf::Texture intro;
	sf::Sprite introSprite;
	float elapsedTime;
	float bgSpeed;
	bool running;
	bool startintro;
	int returnCounter;
};

#endif