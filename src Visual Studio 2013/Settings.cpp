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
	Text coop("Coop", 70), difficulty("Difficulty", 70), graphics("Graphics", 70), sounds("Sound", 70), back("Back", 70);
	

	difficulty.setPosition(270, 100);
	coop.setPosition(270, 200);
	graphics.setPosition(270, 400);
	sounds.setPosition	  (270, 300);
	back.setPosition	  (270, 500);


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
					if (selection < 4)
					{
						selection += 1;
						sound.PlaySound("select");
					}
					else
					{
						selection = 4;
					}
					break;
				case sf::Keyboard::Return:
					if (selection == 0)//diff
					{
						return (7);
					}
					else if (selection == 1)//coop
					{
						return (8);
					}
					else if (selection == 2)//sound
					{
						return (6);
					}
					else if (selection == 3)//graphics
					{
						return (4);
					}
					else//back
					{
						return 0;
					}
				default:
					break;

				}
			}
		}

		if (selection == 0)//diff
		{
			difficulty.setColor(sf::Color(255, 128, 0));
			coop.setColor(sf::Color(255, 255, 255));
			graphics.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 255, 255));
		}
		else if (selection == 1)//coop
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			coop.setColor(sf::Color(255, 128, 0));
			graphics.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 255, 255));
		}
		else if (selection == 2)//sound
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			coop.setColor(sf::Color(255, 255, 255));
			graphics.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 128, 0));
			back.setColor(sf::Color(255, 255, 255));
		}
		else if (selection == 3)//Graphics
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			coop.setColor(sf::Color(255, 255, 255));
			graphics.setColor(sf::Color(255, 128, 0));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 255, 255));
		}
		else//back
		{
			difficulty.setColor(sf::Color(255, 255, 255));
			coop.setColor(sf::Color(255, 255, 255));
			graphics.setColor(sf::Color(255, 255, 255));
			sounds.setColor(sf::Color(255, 255, 255));
			back.setColor(sf::Color(255, 128, 0));
		}

		//draw
		window.clear();
		bg.Render(window);
		graphics.Render(window);
		difficulty.Render(window);
		coop.Render(window);
		sounds.Render(window);
		back.Render(window);
		window.display();
	}

	return (-1);
}
