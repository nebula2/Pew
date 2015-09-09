//MessageHandler.cpp

#include "MessageHandler.h"

MessageHandler::MessageHandler(){
	pauseText.setStringAndSize("PAUSED", 60);
	pauseText.setOrigin(pauseText.getGlobalBounds().width / 2, pauseText.getGlobalBounds().height / 2);
	pauseText.setPosition(400, 250);

	lvUp.setStringAndSize("NEW WEAPON", 60);
	lvUp.setColor(sf::Color::Yellow);
	lvUp.setOrigin(lvUp.getGlobalBounds().width / 2, lvUp.getGlobalBounds().height / 2);
	lvUp.setPosition(400, 300);

	gameOver.setStringAndSize("GAME OVER", 56);
	gameOver.setPosition(210, 250);
	gameOver.setColor(sf::Color::White);

	pHealthS.setSize(18);
	pHealthS.setPosition(23, 12.5);
	pHealthS.setColor(sf::Color::Green);

	pointS.setSize(25);
	pointS.setPosition(650, 8);
	pointS.setColor(sf::Color::Black);

	pausedInfo.setStringAndSize("Esc = Menu, Return = Resume", 40);
	pausedInfo.setOrigin(pauseText.getGlobalBounds().width / 2, pauseText.getGlobalBounds().height / 2);
	pausedInfo.setPosition(210, 350);
}

void MessageHandler::UpdateStream(std::stringstream &stream, int &value, std::string string){
	if (string == "pHealthS")
		pHealthS.Update(stream, value);
	else
		pointS.Update(stream, value);
}
void MessageHandler::UpdatelvUp(int &points, int &showLvUp, sf::RenderWindow &window, float &elapsedTime){
	if (points >= 1000 && points < 1030)	{
		showLvUp += elapsedTime;

		if (showLvUp > 0 && showLvUp <= 2000)
			MessageHandler::Render(window, "lvUp");
		
		else if (showLvUp > 2000)
			showLvUp = -20000;
	}
}
void MessageHandler::Render(sf::RenderWindow &window, std::string string){
	if (string == "pauseText")
		pauseText.Render(window);

	else if (string == "pausedInfo")
		pausedInfo.Render(window);

	else if (string == "lvUp")
		lvUp.Render(window);
	
	else if (string == "gameOver")
		gameOver.Render(window);
	
	else if (string == "pHealthS")
		pHealthS.Render(window);
	
	else
		pointS.Render(window);
}