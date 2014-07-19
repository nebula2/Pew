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
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					if (selection < 100)
					{
						selection += 5;
					}
					else
					{
						selection = 100;
					}
					break;
				case sf::Keyboard::Left:
					if (selection > 0)
					{
						selection -= 5;
					}
					break;
				case sf::Keyboard::Escape:
					return 2;
					break;
				case sf::Keyboard::Return:
					iosound.WriteSoundSettings(selection);
					return 2;
					break;
				default:
					break;

				}

			}
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