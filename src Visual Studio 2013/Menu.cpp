//Menu.cpp

#include "Menu.h"

Menu::Menu()
{
	playing = false;
}

void Menu::setPlaying(bool &mPlaying)
{
	playing = mPlaying;
}

bool Menu::getPlaying()
{
	return playing;
}

int Menu::Run(sf::RenderWindow &window)
{
	//basic stuff
	bool running = true;
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	selection = 0;

	//background and buttons
	Background bg("graphics//core//menu.png");

	//sound & music
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	MenuMusic music;
	music.LoadMusic(volume);
	music.PlayMusic("menusong");

	//buttons
	Text play("play", 70), again("again", 70), settings("settings", 70), close("close", 70);
	
	play.setPosition	(270, 150);
	again.setPosition	(270, 150);
	settings.setPosition(270, 250);	
	close.setPosition	(270, 350);

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
					if (selection < 2)
					{
						selection += 1;
						sound.PlaySound("select");
					}
					else
					{
						selection = 2;
					}
					break;
				case sf::Keyboard::Return:
					if (selection == 0)
					{
						if (playing == true)
						{
							return 3;
						}
						else
						{
							playing = true;
							return 1;
						}
					}
					else if (selection == 1)
					{
						return 2;
					}
					else
					{
						return -1;
					}
					break;
				default:
					break;
				}
			}
		}

		//change the color depending on selection
		if (selection == 0)//Spielen
		{
			play.setColor	 (sf::Color(255, 128,   0));
			again.setColor	 (sf::Color(255, 128,   0));
			settings.setColor(sf::Color(255, 255, 255));
			close.setColor	 (sf::Color(255, 255, 255));
		}
		else if (selection == 1)//Settings
		{
			play.setColor	 (sf::Color(255, 255, 255));
			again.setColor	 (sf::Color(255, 255, 255));
			settings.setColor(sf::Color(255, 128,   0));
			close.setColor	 (sf::Color(255, 255, 255));
		}
		else//Beenden
		{
			play.setColor	 (sf::Color(255, 255, 255));
			again.setColor	 (sf::Color(255, 255, 255));
			settings.setColor(sf::Color(255, 255, 255));
			close.setColor	 (sf::Color(255, 128,   0));
		}

		//draw stuff
		window.clear();
		bg.Render(window);

		if (playing)
		{
			again.Render(window);
		}
		else
		{
			play.Render(window);
		}
		settings.Render(window);
		close.Render(window);

		window.display();
	}
	return -1;
}