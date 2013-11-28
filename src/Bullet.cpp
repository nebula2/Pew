#include "Bullet.h"

sf::Texture Bullet::bulletTex;

Bullet::Bullet()
{
	speed = 0.9;
	active = true;
	
	if (!bulletTex.loadFromFile("graphics//bullet.png"))
	{
		std::cout << "Bullet konnte nicht geladen werden" << std::endl;
	}

	bulletTex.setSmooth(false);
	bulletSprite.setTexture(bulletTex);
}

void Bullet::Update(sf::RenderWindow &window, float elapsedTime)
{
	if(active)
	{
		float x = bulletSprite.getPosition().x;
		float y = bulletSprite.getPosition().y;

		if (y >= -10)
		{
			y -= speed*elapsedTime;
		}else
			{
				active = false;
			}
		bulletSprite.setPosition(x, y);
	}

}

void Bullet::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(bulletSprite);
	}
}

void Bullet::SetPosition(float x, float y)
{
	bulletSprite.setPosition(x, y);
}

int Bullet::getDamage()
{
	return 1;
}