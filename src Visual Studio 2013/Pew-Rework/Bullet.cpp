//Bullet.cpp

#include "Bullet.h"

sf::Texture Bullet::bulletTex;

Bullet::Bullet()
{
	speed = 0.9;
	active = true;
	isPew = false;

	bulletTex.loadFromFile("graphics//weapons//bullet.png");
	bulletTex.setSmooth(false);
	sprite.setTexture(bulletTex);
}

void Bullet::Update(float elapsedTime)
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

void Bullet::Render(sf::RenderWindow &window)
{
	if (active)
	{
		window.draw(sprite);
	}
}

void Bullet::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int Bullet::getDamage()
{
	return 1;
}