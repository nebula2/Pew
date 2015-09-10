//GraphicSet.cpp

#include "GraphicSet.h"

GraphicSet::GraphicSet(){
	//basic stuff
	bg.setFilePath("graphics/core/settings.jpg");

	isFull = ioscreen.getScreenSettings();

	if (iosmooth.ReadSmoothSettings())
		isSmooth = false;
	else
		isSmooth = true;

	selectionH = false;
	selectionV = false;

	//Sound
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//buttons
	smooth.setStringAndSize("Smooth", 70);
	fullscreen.setStringAndSize("Fullscreen", 70);
	falseS.setStringAndSize("false", 50);
	falseF.setStringAndSize("false", 50);
	trueS.setStringAndSize("true", 50);
	trueF.setStringAndSize("true", 50);
	info.setStringAndSize("enter = save, esc = back", 40);

	smooth.setPosition(50, 75);
	smooth.setColor(sf::Color(255, 128, 0));
	falseS.setPosition(480, 95);
	trueS.setPosition(630, 95);

	fullscreen.setPosition(50, 300);
	fullscreen.setColor(sf::Color(255, 128, 0));
	falseF.setPosition(480, 320);
	trueF.setPosition(630, 320);

	info.setPosition(50, 500);
	info.setColor(sf::Color(255, 128, 0));
}
GraphicSet::~GraphicSet(){
}

void GraphicSet::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent)){
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//keyboard selection
		if (pEvent.type == sf::Event::KeyPressed){
			switch (pEvent.key.code){
				//horizontal
			case sf::Keyboard::Up:
				if (selectionV){
					selectionV = false;
					sound.PlaySound("select");
				}
				else
					selectionV = false;
				break;
			case sf::Keyboard::Down:
				if (!selectionV){
					selectionV = true;
					sound.PlaySound("select");
				}
				else
					selectionV = true;
				break;
				//vertical
			case sf::Keyboard::Right:
				if (!selectionH){
					selectionH = true;
					sound.PlaySound("select");
				}
				else
					selectionH = true;
				break;
			case sf::Keyboard::Left:
				if (selectionH){
					selectionH = false;
					sound.PlaySound("select");
				}
				else
					selectionH = false;
				break;
				//confirm or discard
			case sf::Keyboard::Return:
				ioscreen.setScreenSettings(isFull);
				iosmooth.WriteSmoothSettings(isSmooth);
				game.ChangeState(Game::gameStates::SETTINGS);
				break;
			case sf::Keyboard::Escape:
				game.ChangeState(Game::gameStates::SETTINGS);
				break;
			default:
				break;
			}
		}
	}
}
void GraphicSet::Update(Game &game)
{
	//set bools depending on selection
	if (selectionH && selectionV)
		isFull = true;

	else if (!selectionH && !selectionV)
		isSmooth = false;

	else if (selectionH && !selectionV)
		isSmooth = true;

	else if (!selectionH && selectionV)
		isFull = false;

	//change color depending on selection
	if (!selectionV){
		if (isFull){
			falseF.setColor(sf::Color(255, 255, 255));
			trueF.setColor(sf::Color(255, 128, 0));
		}
		if (!isFull){
			falseF.setColor(sf::Color(255, 128, 0));
			trueF.setColor(sf::Color(255, 255, 255));
		}
		if (!selectionH){
			falseS.setColor(sf::Color(255, 128, 0));
			trueS.setColor(sf::Color(255, 255, 255));
		}
		if (selectionH){
			falseS.setColor(sf::Color(255, 255, 255));
			trueS.setColor(sf::Color(255, 128, 0));
		}
	}

	if (selectionV){
		if (isSmooth){
			falseS.setColor(sf::Color(255, 255, 255));
			trueS.setColor(sf::Color(255, 128, 0));
		}
		if (!isSmooth){
			falseS.setColor(sf::Color(255, 128, 0));
			trueS.setColor(sf::Color(255, 255, 255));
		}
		if (!selectionH){
			falseF.setColor(sf::Color(255, 128, 0));
			trueF.setColor(sf::Color(255, 255, 255));
		}
		if (selectionH){
			falseF.setColor(sf::Color(255, 255, 255));
			trueF.setColor(sf::Color(255, 128, 0));
		}
	}
}
void GraphicSet::Render(Game &game){
	bg.Render(game.window);
	smooth.Render(game.window);
	fullscreen.Render(game.window);
	info.Render(game.window);
	trueS.Render(game.window);
	falseS.Render(game.window);
	trueF.Render(game.window);
	falseF.Render(game.window);
}