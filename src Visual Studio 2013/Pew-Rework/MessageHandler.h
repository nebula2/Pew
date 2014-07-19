//MessageHandler.h

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "GUI.h"

class MessageHandler
{
public:
	MessageHandler(sf::RenderWindow &window);
	void UpdateStream(std::stringstream &stream, int &points, std::string string);
	void UpdatelvUp(int &points, int &showLvUp, sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window, std::string string);
	

private:
	Text pauseText, lvUp, gameOver, pHealthS, pointS;
};

#endif