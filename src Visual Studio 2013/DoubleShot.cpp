//DoubleShot.cpp

#include "DoubleShot.h"


sf::Texture DoubleShot::doubleTex;

DoubleShot::DoubleShot()
{
	speed = 0.9;
	active = true;
	isPew = false;

	doubleTex.loadFromFile("graphics//weapons//double.png");

	doubleTex.setSmooth(false);
	sprite.setTexture(doubleTex);
}

void DoubleShot::Update(sf::RenderWindow &Window, float elapsedTime)
{
	if (active)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y >= -10)
		{
			y -= speed*elapsedTime;
		}
		else
		{
			active = false;
		}
		sprite.setPosition(x, y);
	}

}

void DoubleShot::Render(sf::RenderWindow &Window)
{
	if (active)
	{
		Window.draw(sprite);
	}
}

void DoubleShot::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int DoubleShot::getDamage()
{
	return 1;
}