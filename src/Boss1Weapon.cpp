#include "Boss1Weapon.h"

sf::Texture Boss1Weapon::weaponTex;

Boss1Weapon::Boss1Weapon()
{
	speed = 0.5;
	active = true;

	weaponTex.loadFromFile("graphics//pew.png");
	weaponTex.setSmooth(false);
	weaponSprite.setTexture(weaponTex);
	weaponSprite.setRotation(180);
	weaponSprite.setOrigin(23.5, 12);
}

void Boss1Weapon::Update(sf::RenderWindow &window, float elapsedTime)
{
	if(active)
	{
		float x = weaponSprite.getPosition().x;
		float y = weaponSprite.getPosition().y;

		if (y <= window.getSize().y)
		{
			y += speed*elapsedTime;
		}else
		{
			active = false;
		}

		weaponSprite.setPosition(x, y);
	}
}

void Boss1Weapon::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(weaponSprite);
	}
}

void Boss1Weapon::SetPosition(float x, float y)
{
	weaponSprite.setPosition(x, y);
}

int Boss1Weapon::getDamage()
{
	return 25;
}