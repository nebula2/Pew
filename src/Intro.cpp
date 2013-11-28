#include "Intro.h"

int Intro::Run(sf::RenderWindow &window)
{
	bool Running = true;
	speed = 0.03;
	elapsedTime = 0;

	//music
	MenuMusic music;
	music.LoadMusic();
	music.PlayMusic("introsong");

	//the intro
	sf::Texture intro;
	intro.loadFromFile("graphics//intro.jpg");
	sf::Sprite introSprite;
	introSprite.setTexture(intro);
	introSprite.setPosition(0, 600);

	float y = introSprite.getPosition().y;


	while (Running)
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
					return 1;
				}		
			}
		}
	
		//move intro upwards
		elapsedTime = clock.restart().asMilliseconds();
		y -= speed*elapsedTime;
	
		introSprite.setPosition(0, y);

		if ( y <= -1200)
		{
			return 1;
		}

		//draw
		window.clear();
		window.draw(introSprite);
		window.display();
	
	}
	return -1;
}