#ifndef WINDOWSTATE_H
#define WINDOWSTATE_H
#include <SFML\Graphics.hpp>

class WindowState
{
public:
	virtual int Run (sf::RenderWindow &window) = 0;
};

#endif