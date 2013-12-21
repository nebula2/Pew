//ShitBullets.cpp

#include "ShitBullets.h"

sf::Texture ShitBullets::shitTex;

ShitBullets::ShitBullets()
{
	speed = 0.2;
	active = true;

	if (!shitTex.loadFromFile("graphics//enemies//shit.png"))
	{
		std::cout << "shit konnte nicht geladen werden" << std::endl;
	}

	shitTex.setSmooth(false);
	sprite.setTexture(shitTex);
	sprite.setOrigin(17.5, 17.5);
}

void ShitBullets::Update(sf::RenderWindow &Window, float elapsedTime)
{
	if (active)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= Window.getSize().y)
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

void ShitBullets::Render(sf::RenderWindow &Window)
{
	if (active)
	{
		Window.draw(sprite);
	}
}

void ShitBullets::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int ShitBullets::getDamage()
{
	return 10;
}
