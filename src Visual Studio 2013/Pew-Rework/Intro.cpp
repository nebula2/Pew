//Intro.cpp

#include "Intro.h"

Intro::Intro()
{
	//basic
	running = false;
	elapsedTime = 0;

	//background
	intro.loadFromFile("graphics//core//intro.jpg");
	introSprite.setTexture(intro);
	introSprite.setPosition(0, 600);
	bgSpeed = 0.03;
}

int Intro::Run(sf::RenderWindow &window)
{	
	running = true;
	startintro = false;
	returnCounter = 0;
	float y = introSprite.getPosition().y;

	if (!startintro)
		introSprite.setPosition(0, 600);


	//stuff for user start
	Text startText("Return to start", 60);
	startText.setOrigin(startText.getGlobalBounds().width / 2, startText.getGlobalBounds().height / 2);
	startText.setPosition(window.getSize().x / 2, window.getSize().y / 2);


	while (running)
	{
		//handle events
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return (-1);
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
					returnCounter += 1;
				if (event.key.code == sf::Keyboard::Escape)
					return 0;

			}
		}
		
		if (returnCounter == 1)
			startintro = true;
		if (returnCounter >= 2)
			return 3;

		//move background
		elapsedTime = clock.restart().asMilliseconds();
		y -= bgSpeed * elapsedTime;
		introSprite.setPosition(0, y);

		//end intro
		if (y <= -1200)
		{
			return 3;
			startintro = false;
		}

		//draw
		window.clear();

		if (!startintro)
			startText.Render(window);
		if (startintro)
			window.draw(introSprite);

		window.display();
	}
	return -1; 
}