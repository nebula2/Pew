//DiffSet.cpp

#include "DiffSet.h"

int DiffSet::Run(sf::RenderWindow &window)
{
	//basic stuff
	running = true;
	IOdiff diff;
	selection = diff.ReadDiffSettings();
	Background bg("graphics//core//settings.jpg");

	//Sound
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//buttons
	Text easy("easy", 70), normal("normal", 70), crazy("crazy", 70), info("enter = save, esc = back", 40);
	easy.setPosition(270, 150);
	normal.setPosition(270, 250);
	crazy.setPosition(270, 350);
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
					if (selection > 1)
					{
						selection -= 1;
						sound.PlaySound("select");
					}
					else
					{
						selection = 1;
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
					diff.WriteDiffSettings(selection);
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
		if (selection == 1)//easy
		{
			easy.setColor(sf::Color(255, 128, 0));
			normal.setColor(sf::Color(255, 255, 255));
			crazy.setColor(sf::Color(255, 255, 255));
		}
		else if (selection == 2)//normal
		{
			easy.setColor(sf::Color(255, 255, 255));
			normal.setColor(sf::Color(255, 128, 0));
			crazy.setColor(sf::Color(255, 255, 255));
		}
		else //crazy
		{
			easy.setColor(sf::Color(255, 255, 255));
			normal.setColor(sf::Color(255, 255, 255));
			crazy.setColor(sf::Color(255, 128, 0));
		}
		
		//draw stuff
		window.clear();

		bg.Render(window);
		easy.Render(window);
		normal.Render(window);
		crazy.Render(window);
		info.Render(window);

		window.display();
	}
	return -1;
}