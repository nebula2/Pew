#include "Pew.h"

sf::Texture Pew::pewShotTex;

Pew::Pew()
{
	speed = 0.6;
	active = true;
	
	pewShotTex.loadFromFile("graphics//pew.png");

	pewShotTex.setSmooth(false);
	pewShotSprite.setTexture(pewShotTex);
}

void Pew::Update(sf::RenderWindow &Window, float elapsedTime)
{
	if(active)
	{
		float x = pewShotSprite.getPosition().x;
		float y = pewShotSprite.getPosition().y;

		if (y >= -10)
		{
			y -= speed*elapsedTime;
		}else
			{
				active = false;
			}
		pewShotSprite.setPosition(x, y);
	}

}

void Pew::Render(sf::RenderWindow &Window)
{
	if(active)
	{
		Window.draw(pewShotSprite);
	}
}

void Pew::SetPosition(float x, float y)
{
	pewShotSprite.setPosition(x, y);
}

int Pew::getDamage()
{
	return 100;
}