//Settings.cpp

#include "Settings.h"

int Settings::Run(sf::RenderWindow &window)
{
	bool running = true;

	//sound
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	MenuMusic music;
	music.LoadMusic(volume);
	music.PlayMusic("menusong");

	//background and "buttons"
	Background bg("graphics//core//settings.png");
	selection = 0;

	//buttons
	Text difficulty("Difficulty", 70), control("Control", 70), sounds("Sound", 70), back("Back", 70);
	
	difficulty.setPosition(270, 150);
	control.setPosition	  (270, 350);
	sounds.setPosition	  (270, 250);
	back.setPosition	  (270, 450);


	while (running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//keyboard
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					if (selection > 0)
					{
						selection -= 1;
						sound.PlaySound("select");
					}
					else
					{
						selection = 0;
					}
					break;
				case sf::Keyboard::Down:
					if (selection < 3)
					{
						selection += 1;
						sound.PlaySound("select");
					}
					else
					{
						selection = 3;
					}
					break;
				case sf::Keyboard::Return:
					if (selection == 0)
					{
						return (4);
					}
					else if (selection == 1)
					{
						return (6);
					}
					else if (selection == 2)
					{
						return (4);
					}
					else
					{
						return 0;
					}
				default:
					break;

				}
			}
		}

		if (selection == 0)//Schwierigkeit
		{
			difficulty.setColor(sf::Color(255, 128, 0));
			control.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 255, 255));
		}
		else if (selection == 1)//Sound
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			control.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 128, 0));
			back.setColor(sf::Color(255, 255, 255));
		}
		else if (selection == 2)//Control
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			control.setColor(sf::Color(255, 128, 0));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 255, 255));
		}
		else
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			control.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 128, 0));
		}

		//draw
		window.clear();
		bg.Render(window);
		control.Render(window);
		difficulty.Render(window);
		sounds.Render(window);
		back.Render(window);
		window.display();
	}

	return (-1);
}
