//GraphicSet.cpp

#include "GraphicSet.h"

int GraphicSet::Run(sf::RenderWindow &window)
{
	//basic stuff
	running = true;
	Background bg("graphics//core//settings.jpg");
	IOscreen ioscreen;
	isFull = ioscreen.getScreenSettings();
	IOsmooth iosmooth;
	isSmooth = false;
	selectionH = false;
	selectionV = false;

	//Sound
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	MenuSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//buttons
	Text smooth("Smooth", 70), fullscreen("Fullscreen", 70), falseS("false", 50), falseF("false", 50), trueS("true", 50),
		trueF("true", 50), info("enter = save, esc = back", 40);

	smooth.setPosition(50, 75);
	smooth.setColor(sf::Color(255, 128, 0));
	falseS.setPosition(400, 95);
	trueS.setPosition(550, 95);

	fullscreen.setPosition(50, 300);
	fullscreen.setColor(sf::Color(255, 128, 0));
	falseF.setPosition(400, 320);
	trueF.setPosition(550, 320);

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
					//horizontal
				case sf::Keyboard::Up:
					if (selectionV)
					{
						selectionV = false;
						sound.PlaySound("select");
					}
					else
					{
						selectionV = false;
					}
					break;
				case sf::Keyboard::Down:
					if (!selectionV)
					{
						selectionV = true;
						sound.PlaySound("select");
					}
					else
					{
						selectionV = true;
					}
					break;
					//vertical
				case sf::Keyboard::Right:
					if (!selectionH)
					{
						selectionH = true;
						sound.PlaySound("select");
					}
					else
					{
						selectionH = true;
					}
					break;
				case sf::Keyboard::Left:
					if (selectionH)
					{
						selectionH = false;
						sound.PlaySound("select");
					}
					else
					{
						selectionH = false;
					}
					break;
					//confirm or discard
				case sf::Keyboard::Return:
					ioscreen.setScreenSettings(isFull);
					iosmooth.WriteSmoothSettings(isSmooth);
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
	
		//set bools depending on selection
		if (selectionH && selectionV)
		{
			isFull = true;
		}
		else if (!selectionH && !selectionV)
		{
			isSmooth = false;
		}
		else if (selectionH && !selectionV)
		{
			isSmooth = true;
		}
		else if (!selectionH && selectionV)
		{
			isFull = false;
		}
	
		//change color depending on selection
		if (!selectionV)
		{
			if (isFull)
			{
				falseF.setColor(sf::Color(255, 255, 255));
				trueF.setColor(sf::Color(255, 128, 0));
			}
			if (!isFull)
			{
				falseF.setColor(sf::Color(255, 128, 0));
				trueF.setColor(sf::Color(255, 255, 255));
			}
			if (!selectionH)
			{
				falseS.setColor(sf::Color(255, 128, 0));
				trueS.setColor(sf::Color(255, 255, 255));
			}
			if (selectionH)
			{
				falseS.setColor(sf::Color(255, 255, 255));
				trueS.setColor(sf::Color(255, 128, 0));
			}
		}

		if (selectionV)
		{
			if (isSmooth)
			{
				falseS.setColor(sf::Color(255, 255, 255));
				trueS.setColor(sf::Color(255, 128, 0));
			}
			if (!isSmooth)
			{
				falseS.setColor(sf::Color(255, 128, 0));
				trueS.setColor(sf::Color(255, 255, 255));
			}
			if (!selectionH)
			{
				falseF.setColor(sf::Color(255, 128, 0));
				trueF.setColor(sf::Color(255, 255, 255));
			}
			if (selectionH)
			{
				falseF.setColor(sf::Color(255, 255, 255));
				trueF.setColor(sf::Color(255, 128, 0));
			}
		}

		//draw stuff
		window.clear();

		bg.Render(window);
		smooth.Render(window);
		fullscreen.Render(window);
		info.Render(window);
		trueS.Render(window);
		falseS.Render(window);
		trueF.Render(window);
		falseF.Render(window);

		window.display();
	}
	return -1;
}