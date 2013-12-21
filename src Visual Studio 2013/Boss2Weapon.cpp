//Boss2Weapon.cpp

#include "Boss2Weapon.h"

sf::Texture Boss2Weapon::weaponTex;

Boss2Weapon::Boss2Weapon()
{
	speed = 0.4;
	active = true;

	weaponTex.loadFromFile("graphics//enemies//boss2weapon.png");
	weaponTex.setSmooth(false);
	sprite.setTexture(weaponTex);
	sprite.setOrigin(44, 49.5);
}

void Boss2Weapon::Update(sf::RenderWindow &window, float &elapsedTime, Player &pPlayer)
{
	if (active)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		//move down
		if (y <= window.getSize().y)
		{
			y += speed * elapsedTime;
		}
		else
		{
			active = false;
		}

		//track player
		if (x < pPlayer.getPosition().x)
		{
			x += speed * elapsedTime;
		}
		if (x > pPlayer.getPosition().x)
		{
			x -= speed * elapsedTime;
		}

		sprite.setPosition(x, y);
	}
}

void Boss2Weapon::Render(sf::RenderWindow &window)
{
	if (active)
	{
		window.draw(sprite);
	}
}

void Boss2Weapon::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int Boss2Weapon::getDamage()
{
	return 15;
}