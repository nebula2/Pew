//CoopSet.cpp

#include "CoopSet.h"

int CoopSet::Run(sf::RenderWindow &window)
{
	//basic stuff
	running = true;
	IOtwoPlayer secPlayer;
	selection = secPlayer.ReadSettings();
	Background bg("graphics//core//settings.jpg");

	//Sound
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//buttons
	Text on("on", 70), off("off", 70), info1("fullscreen recommended for Coop", 30), 
		 info("enter = save, esc = back", 40);
	on.setPosition(350, 150);
	off.setPosition(350, 250);
	info1.setPosition(50, 400);
	info1.setColor(sf::Color(255, 128, 0));
	info.setPosition(50, 500);
	info.setColor(sf::Color(255, 128, 0));

	while (running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return -1;
			}

			//keyboard selection
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					if (!selection)
					{
						selection = true;
						sound.PlaySound("select");
					}
					else
					{
						selection = true;
					}
					break;
				case sf::Keyboard::Down:
					if (selection)
					{
						selection = false;
						sound.PlaySound("select");
					}
					else
					{
						selection = false;
					}
					break;
				case sf::Keyboard::Return:
					secPlayer.WriteSettings(selection);
					return 2;
					break;
				case sf::Keyboard::Escape:
					return 2;
					break;
				default:
					break;
				}
			}
		}
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

		//draw stuff
		window.clear();

		bg.Render(window);
		on.Render(window);
		off.Render(window);
		info1.Render(window);
		info.Render(window);

		window.display();
	}
	return -1;
}