//Menu.h

#ifndef MENU_H
#define MENU_H

#include "StateManager.h"
#include "MenuSfx.h"
#include "IOsound.h"
#include <math.h>

class Menu : public StateManager
{
public: 
	Menu();
	virtual int Run(sf::RenderWindow &window);
	void setPlaying(bool &mPlaying);
	bool getPlaying();
private:
	bool playing;
	sf::Event event;
	int selection;
	int volume;
	sf::Clock clock;
	float elapsedTime;
	float x_movement;
	float y_movement;
	float x, y;
	int debauch;
	sf::Texture texture;
	sf::Sprite sprite;

};
#endif