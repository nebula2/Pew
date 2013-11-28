#include "Settings_tmp.h"

int Settings_tmp::Run (sf::RenderWindow &window)
{
	bool Running = true;

	//vector for mouse position check
	sf::Vector2f posMouseInFloat;
	sf::Vector2i posMouse;

	//sound
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.SetBuffer();

	MenuMusic music;
	music.LoadMusic();
	music.PlayMusic("menusong");

	//background and "buttons"
	Backgrounds bg("graphics//settings_tmp.jpg");


	while (Running)
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
