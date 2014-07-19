//MainMenuState.cpp

#define PI 3.14159
#include "MainMenuState.h"
#include <cmath>

MainMenuState::MainMenuState()
{
	bg.setFilePath("graphics//core//menu.png");
	
	//sound & music
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	speed	  = 0.5;
	selection = 0;


	//Enemy
	elapsedTime = 0;
	x_movement =  0;
	y_movement =  0;
	debauch =	  200;
	texture.loadFromFile("graphics//enemies//enemy.png");
	texture.setSmooth(false);
	sprite.setTexture(texture);
	sprite.setOrigin(36.5, 35);

	//buttons
	play.setStringAndSize	 ("play", 70);
	again.setStringAndSize	 ("again", 70);
	settings.setStringAndSize("settings", 70);
	close.setStringAndSize	 ("close", 70);

	play.setPosition	(270, 150);
	again.setPosition	(270, 150);
	settings.setPosition(270, 250);
	close.setPosition	(270, 350);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::HandleEvents(Game &game)
{
	sf::Event pEvent;

	while (game.window.pollEvent(pEvent))
	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		//Keyboard selection
		if (pEvent.type == sf::Event::KeyPressed)
		{
			switch (pEvent.key.code)
			{
			case sf::Keyboard::Up:
				if (selection > 0)
				{
					selection -= 1;
					sound.PlaySound("select");
				}
				else
					selection = 0;
				break;

			case sf::Keyboard::Down:
				if (selection < 2)
				{
					selection += 1;
					sound.PlaySound("select");
				}
				else
					selection = 2;
				break;

			case sf::Keyboard::Return:
				if (selection == 0)
				{
					if (!game.getIntroPlayed())
					game.ChangeState(Game::gameStates::INTRO);

					else
					{
						game.setIntroPlayed(true);
						game.ChangeState(Game::gameStates::PLAY);
					}
				}
				else if (selection == 1)
					game.ChangeState(Game::gameStates::SETTINGS);
				else
					game.setRunning(false);
				break;
			default:
				break;
			}
		}
	}
}

void MainMenuState::Update(Game &game)
{
	if (selection == 0)//Spielen
	{
		play.setColor(sf::Color(255, 128, 0));
		again.setColor(sf::Color(255, 128, 0));
		settings.setColor(sf::Color(255, 255, 255));
		close.setColor(sf::Color(255, 255, 255));
	}
	else if (selection == 1)//Settings
	{
		play.setColor(sf::Color(255, 255, 255));
		again.setColor(sf::Color(255, 255, 255));
		settings.setColor(sf::Color(255, 128, 0));
		close.setColor(sf::Color(255, 255, 255));
	}
	else//Beenden
	{
		play.setColor(sf::Color(255, 255, 255));
		again.setColor(sf::Color(255, 255, 255));
		settings.setColor(sf::Color(255, 255, 255));
		close.setColor(sf::Color(255, 128, 0));
	}

	//moving enemy
	elapsedTime = pClock.restart().asMilliseconds();
	x_movement += elapsedTime;
	y_movement += elapsedTime;
	y = sprite.getPosition().y;
	x = sprite.getPosition().x;
	y = 300 + std::sin((y_movement * PI) / 180) * debauch;
	x = 400 + std::cos((x_movement * PI) / 180) * debauch;

	if (x_movement > 360)
		x_movement = 0;

	if (y_movement > 360)
		y_movement = 0;

	sprite.setPosition(x, y);
}

void MainMenuState::Render(Game &game)
{
	bg.Render(game.window);
	game.window.draw(sprite);
	settings.Render(game.window);
	close.Render(game.window);
	if (game.getIntroPlayed())
		again.Render(game.window);
	else
		play.Render(game.window);
}