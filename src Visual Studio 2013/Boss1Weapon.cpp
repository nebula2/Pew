//Boss1Weapon.cpp

#include "Boss1Weapon.h"

sf::Texture Boss1Weapon::weaponTex;

Boss1Weapon::Boss1Weapon()
{
	speed = 0.5;
	active = true;

	weaponTex.loadFromFile("graphics//pew.png");
	weaponTex.setSmooth(false);
	sprite.setTexture(weaponTex);
	sprite.setRotation(180);
	sprite.setOrigin(23.5, 12);
}

void Boss1Weapon::Update(sf::RenderWindow &Window, float elapsedTime)
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

void Boss1Weapon::Render(sf::RenderWindow &Window)
{
	if (active)
	{
		Window.draw(sprite);
	}
}

void Boss1Weapon::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int Boss1Weapon::getDamage()
{
	return 25;
}