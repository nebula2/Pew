//MessageHandler.h

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "GUI.h"

namespace sf{
	class RenderWindow;
}

class MessageHandler{
public:
	MessageHandler();

	void UpdateStream(std::stringstream &stream, int &value, std::string string);
	void UpdatelvUp(int &points, int &showLvUp, sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window, std::string string);

private:
	Text pauseText, lvUp, gameOver, pHealthS, pointS, pausedInfo;
};

#endif