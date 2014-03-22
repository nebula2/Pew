//ShitBullets.cpp

#include "ShitBullets.h"

sf::Texture ShitBullets::shitTex;

ShitBullets::ShitBullets()
{
	speed = 0.2;
	IOsmooth smooth;
	active = true;

	shitTex.loadFromFile("graphics//enemies//shit.png");
	shitTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(shitTex);
	sprite.setOrigin(17.5, 17.5);
}

void ShitBullets::Update(sf::RenderWindow &window, float elapsedTime)
{
	if (active)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)
		{
			y += speed*elapsedTime;
		}
		else
		{
			active = false;
		}

		sprite.setPosition(x, y);
	}
}

void ShitBullets::Render(sf::RenderWindow &window)
{
	if (active)
	{
		window.draw(sprite);
	}
}

void ShitBullets::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int ShitBullets::getDamage()
{
	IOdiff diff;
	return 10 * diff.ReadDiffSettings();
}
