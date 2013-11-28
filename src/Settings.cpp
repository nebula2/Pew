#include "Settings.h"


int Settings::Run(sf::RenderWindow &window)
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
	Backgrounds bg("graphics//settings.png");
	auswahl = 0;

	GUItext schwierigkeit("Schwierigkeit", 70);
	schwierigkeit.setPosition(270, 150);
	sf::FloatRect schwierigkeitR(schwierigkeit.getGlobalBoundz());

	GUItext control("Control", 70);
    control.setPosition(270, 350);
	sf::FloatRect controlR(control.getGlobalBoundz());

	GUItext sounds("Sound", 70);
	sounds.setPosition(270, 250);
	sf::FloatRect soundsR(sounds.getGlobalBoundz());

	GUItext back("Back", 70);
	back.setPosition(270, 450);


	while (Running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//mouse
			if (event.type == sf::Event::MouseButtonPressed)
			{
				posMouse = sf::Mouse::getPosition(window);
				posMouseInFloat = static_cast<sf::Vector2f>(posMouse);

				if (schwierigkeitR.contains(posMouseInFloat))
				{
					return 4;
				}
				else if (controlR.contains(posMouseInFloat))
				{
					return 4;
				}
				else if(soundsR.contains(posMouseInFloat))
				{
					return 4;
				}
			}

			//keyboard
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Up:
						if (auswahl > 0)
						{
							auswahl -= 1;
							sound.PlaySound("select");
						}
						else
						{
							auswahl = 0;
						}
						break;
					case sf::Keyboard::Down:
						if (auswahl <3)
						{
							auswahl += 1;
							sound.PlaySound("select");
						}
						else
						{
							auswahl = 3;
						}
						break;
					case sf::Keyboard::Return:
						if (auswahl == 0)
						{
							return (4);
						}
						else if (auswahl == 1)
						{
							return (4);
						}
						else if (auswahl == 2)
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
        
        if (auswahl == 0)//Schwierigkeit
        {
            schwierigkeit.setColor (sf::Color(255, 128,   0));
            control.setColor       (sf::Color(255, 255, 255));
            sounds.setColor		   (sf::Color(255, 255, 255));
			back.setColor		   (sf::Color(255, 255, 255));
        }
        else if (auswahl == 1)//Sound
        {
            schwierigkeit.setColor (sf::Color(255, 255, 255));
            control.setColor	   (sf::Color(255, 255, 255));
            sounds.setColor        (sf::Color(255, 128,   0));
			back.setColor		   (sf::Color(255, 255, 255));
        }
		else if (auswahl == 2)//Control
		{
			schwierigkeit.setColor (sf::Color(255, 255, 255));
            control.setColor       (sf::Color(255, 128,   0));
            sounds.setColor		   (sf::Color(255, 255, 255));
			back.setColor		   (sf::Color(255, 255, 255));
		}
		else 
		{
			schwierigkeit.setColor (sf::Color(255, 255, 255));
            control.setColor       (sf::Color(255, 255, 255));
            sounds.setColor		   (sf::Color(255, 255, 255));
			back.setColor		   (sf::Color(255, 128,   0));
		}

		//draw
		window.clear();
		bg.Render(window);
		control.Render(window);
		schwierigkeit.Render(window);
		sounds.Render(window);
		back.Render(window);
		window.display();
	}

	return (-1);
}
