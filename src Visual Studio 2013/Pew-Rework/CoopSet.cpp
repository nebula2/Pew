//CoopSet.cpp

#include "CoopSet.h"


CoopSet::CoopSet()
{
	//basic stuff
	selection = secPlayer.ReadSettings();
	bg.setFilePath("graphics//core//settings.jpg");

	//Sound
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//buttons
	on.setStringAndSize("on", 70);
	off.setStringAndSize("off", 70);
	info1.setStringAndSize("fullscreen recommended for Coop", 30);
	info.setStringAndSize("enter = save, esc = back", 40);;

	on.setPosition(350, 150);
	off.setPosition(350, 250);
	info1.setPosition(50, 400);
	info1.setColor(sf::Color(255, 128, 0));
	info.setPosition(50, 500);
	info.setColor(sf::Color(255, 128, 0));
}
CoopSet::~CoopSet()
{
}
void CoopSet::HandleEvents(Game &game)
{
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent))
	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//keyboard selection
		if (pEvent.type == sf::Event::KeyPressed)
		{
			switch (pEvent.key.code)
			{
			case sf::Keyboard::Up:
				if (!selection)
				{
					selection = true;
					sound.PlaySound("select");
				}
				else
					selection = true;
				break;
			case sf::Keyboard::Down:
				if (selection)
				{
					selection = false;
					sound.PlaySound("select");
				}
				else
					selection = false;
				break;
			case sf::Keyboard::Return:
				secPlayer.WriteSettings(selection);
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
void CoopSet::Update(Game &game)
{
	//change the color depending on selection
	if (selection)//on
	{
		on.setColor(sf::Color(255, 128, 0));
		off.setColor(sf::Color(255, 255, 255));
	}
	else if (!selection)//off
	{
		on.setColor(sf::Color(255, 255, 255));
		off.setColor(sf::Color(255, 128, 0));
	}

}
void CoopSet::Render(Game &game)
{
	bg.Render(game.window);
	on.Render(game.window);
	off.Render(game.window);
	info1.Render(game.window);
	info.Render(game.window);
}