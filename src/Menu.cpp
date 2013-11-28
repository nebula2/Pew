#include "Menu.h"


Menu::Menu()
{
	playing = false;
}

int Menu::Run(sf::RenderWindow &window)
{
	bool Running = true;

	//vector for mouse position check
	sf::Vector2f posMouseInFloat;
	sf::Vector2i posMouse;

	//sound & music
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.SetBuffer();

	MenuMusic music;
	music.LoadMusic();
	music.PlayMusic("menusong");

	//background and "buttons"
	Backgrounds bg("graphics//menu.png");
	sf::Font font;
	sf::Text spielen, beenden, nochmal, settings;
	auswahl = 0;
	font.loadFromFile("arial.ttf");

	spielen.setFont(font);
    spielen.setCharacterSize(70);
    spielen.setString("Spielen");
    spielen.setPosition(270, 150);
	sf::FloatRect spielR(spielen.getGlobalBounds());

    beenden.setFont(font);
    beenden.setCharacterSize(70);
    beenden.setString("Beenden");
    beenden.setPosition(270, 350);
	sf::FloatRect beendenR(beenden.getGlobalBounds());

    nochmal.setFont(font);
    nochmal.setCharacterSize(70);
    nochmal.setString("Nochmal");
    nochmal.setPosition(270, 150);

	settings.setFont(font);
    settings.setCharacterSize(70);
    settings.setString("Einstellungen");
    settings.setPosition(270, 250);
	sf::FloatRect settingsR(settings.getGlobalBounds());

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

				if (spielR.contains(posMouseInFloat))
				{
					return 3;
				}
				else if (beendenR.contains(posMouseInFloat))
				{
					return -1;
				}
				else if(settingsR.contains(posMouseInFloat))
				{
					return 2;
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
						if (auswahl <2)
						{
							auswahl += 1;
							sound.PlaySound("select");
						}
						else
						{
							auswahl = 2;
						}
						break;
					case sf::Keyboard::Return:
						if (auswahl == 0)
						{
							if (playing == true)
							{
								return 1;
							}
							else
							{
								playing = true;
								return (3);
							}
						}
						else if (auswahl == 1)
						{
							return (2);
						}
						else
						{
							return (-1);
						}
						break;
					default:
						break;
				}
			}
		}
        
		//change the color depending on selection
        if (auswahl == 0)//Spielen
        {
            spielen.setColor (sf::Color(255, 128,   0));
			settings.setColor(sf::Color(255, 255, 255));
            beenden.setColor (sf::Color(255, 255, 255));
            nochmal.setColor (sf::Color(255, 128,   0));
        }
        else if (auswahl == 1)//Settings
        {
            spielen.setColor (sf::Color(255, 255, 255));
			settings.setColor(sf::Color(255, 128,   0));
            beenden.setColor (sf::Color(255, 255, 255));
            nochmal.setColor (sf::Color(255, 255, 255));
        }
		else//Beenden
		{
			spielen.setColor (sf::Color(255, 255, 255));
			settings.setColor(sf::Color(255, 255, 255));
            beenden.setColor (sf::Color(255, 128,   0));
            nochmal.setColor (sf::Color(255, 255, 255));
		}

		//draw
		window.clear();
		bg.Render(window);
	
		if (playing)
		{
			window.draw(nochmal);
		}
		else
		{
			window.draw(spielen);
		}
		window.draw(beenden);
		window.draw(settings);

		window.display();
	}
	return (-1);
}