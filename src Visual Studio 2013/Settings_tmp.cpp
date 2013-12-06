//Settings_tmp.cpp

#include "Settings_tmp.h"

int Settings_tmp::Run(sf::RenderWindow &window)
{
	bool running = true;


	//sound
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer();

	MenuMusic music;
	music.LoadMusic();
	music.PlayMusic("menusong");

	//background and "buttons"
	Background bg("graphics//core//settings_tmp.jpg");


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

				case sf::Keyboard::Return:
					return (2);
					break;
				default:
					break;
				}
			}
		}

		//draw
		window.clear();
		bg.Render(window);
		window.display();
	}

	return (-1);
}
