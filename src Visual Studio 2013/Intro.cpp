//Intro.cpp

#include "Intro.h"

Intro::Intro()
{
	//basic
	running = false;
	elapsedTime = 0;

	//music
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	MenuMusic music;
	music.LoadMusic(volume);
	music.PlayMusic("introsong");


	//background
	intro.loadFromFile("graphics//core//intro.jpg");
	introSprite.setTexture(intro);
	introSprite.setPosition(0, 600);
	bgSpeed = 0.03;
}

int Intro::Run(sf::RenderWindow &window)
{	

	while (!running)
	{
		introSprite.setPosition(0, 600);
		//draw
		window.clear();
		window.draw(introSprite);
		window.display();
	}
	
	float y = introSprite.getPosition().y;

	while (running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					return 3;
				}
			}
		}

		//move background
		elapsedTime = clock.restart().asMilliseconds();
		y -= bgSpeed * elapsedTime;
		introSprite.setPosition(0, y);

		//end intro
		if (y <= -1200)
		{
			return 3;
		}

		//draw
		window.clear();
		window.draw(introSprite);
		window.display();
	}
	return -1; 
}

void Intro::setRunning(bool &m_running)
{
	running = m_running;
}

bool Intro::getRunning()
{
	return running;
}