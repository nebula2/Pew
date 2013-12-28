//Pew.cpp

#include "Pew.h"

sf::Texture Pew::pewShotTex;

Pew::Pew()
{
	speed = 0.9;
	active = true;
	isPew = true;

	pewShotTex.loadFromFile("graphics//weapons//pew.png");

	pewShotTex.setSmooth(false);
	sprite.setTexture(pewShotTex);
}

void Pew::Update(sf::RenderWindow &Window, float elapsedTime)
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

void Pew::Render(sf::RenderWindow &Window)
{
	if (active)
	{
		Window.draw(sprite);
	}
}

void Pew::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int Pew::getDamage()
{
	return 20;
}