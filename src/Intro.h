#ifndef INTRO_H
#define INTRO_H

//sfml and windows header
#include <SFML\Graphics.hpp>
//own header
#include "GUIbackgrounds.h"
#include "WindowState.h"
#include "MenuMusic.h"

class Intro : public WindowState
{
public:
	virtual int Run(sf::RenderWindow &window);
private:
	sf::Event event;
	float speed;
	float elapsedTime;
	sf::Clock clock;
};
#endif