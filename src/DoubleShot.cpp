#include "DoubleShot.h"


sf::Texture DoubleShot::doubleTex;

DoubleShot::DoubleShot()
{
	speed = 0.9;
	active = true;
	
	doubleTex.loadFromFile("graphics//double.png");

	doubleTex.setSmooth(false);
	doubleSprite.setTexture(doubleTex);
}

void DoubleShot::Update(sf::RenderWindow &window, float elapsedTime)
{
	if(active)
	{
		float x = doubleSprite.getPosition().x;
		float y = doubleSprite.getPosition().y;

		if (y >= -10)
		{
			y -= speed*elapsedTime;
		}else
			{
				active = false;
			}
		doubleSprite.setPosition(x, y);
	}

}

void DoubleShot::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(doubleSprite);
	}
}

void DoubleShot::SetPosition(float x, float y)
{
	doubleSprite.setPosition(x, y);
}

int DoubleShot::getDamage()
{
	return 1;
}