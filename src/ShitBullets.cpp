#include "ShitBullets.h"

sf::Texture ShitBullets::shitTex;

ShitBullets::ShitBullets()
{
	speed = 0.2;
	active = true;

	
	if (!shitTex.loadFromFile("graphics//shit.png"))
	{
		std::cout << "shit konnte nicht geladen werden" << std::endl;
	}

	shitTex.setSmooth(false);
	shitSprite.setTexture(shitTex);
	shitSprite.setOrigin(17.5, 17.5);
}

void ShitBullets::Update(sf::RenderWindow &window, float elapsedTime)
{
	if(active)
	{
		float x = shitSprite.getPosition().x;
		float y = shitSprite.getPosition().y;

		if (y <= window.getSize().y)
		{
			y += speed*elapsedTime;
		}else
		{
			active = false;
		}

		shitSprite.setPosition(x, y);
	}
}

void ShitBullets::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(shitSprite);
	}
}

void ShitBullets::SetPosition(float x, float y)
{
	shitSprite.setPosition(x, y);
}
int ShitBullets::getDamage()
{
	return 10;
}