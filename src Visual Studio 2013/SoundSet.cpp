//SoundSet.cpp

#include "SoundSet.h"

int SoundSet::Run(sf::RenderWindow &window)
{
	//set up the window
	running = true;
	Background bg("graphics//core//soundset.jpg");
	Text selectionString(50);
		 selectionString.setPosition(350, 250);
		 selectionString.setColor(sf::Color::White);
	elapsedTime = 0;



	//read actual settings into volume
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	selection = volume;
	

	while (running)
	{
		//user input
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					return(2);
				}
				if (event.key.code == sf::Keyboard::Return)
				{

					iosound.WriteSoundSettings(selection);
					return (2);
				}
			}
		}

		//let the user define the volume
		elapsedTime = clock.restart().asMilliseconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (selection >= 0)
			selection -= 0.05 * elapsedTime;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (selection <= 99)
			selection += 0.1 * elapsedTime;
		}
		
		//stream int
		selectionString.Update(selectionStream, selection);

		//draw
		window.clear();
		bg.Render(window);
		selectionString.Render(window);
		window.display();
	}
	return (-1);
}