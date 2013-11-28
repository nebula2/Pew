#include "SpaceMonkey.h"

sf::Texture SpaceMonkey::enemyTex;

SpaceMonkey::SpaceMonkey()
{
	speed = 0.3;
	health = 10;
	active = true;
	moveLeft = true;

	if (!enemyTex.loadFromFile("graphics//spacemonkey.png"))
	{
		std::cout << "Enemy konnte nicht geladen werden" << std::endl;
	}

	enemyTex.setSmooth(false);
	enemySprite.setTexture(enemyTex);
	enemySprite.setOrigin(36, 20);
	enemySprite.setPosition(364, 25); 

}
void SpaceMonkey::Update(sf::RenderWindow &window, float elapsedTime)
{
	float x = enemySprite.getPosition().x;
	float y = enemySprite.getPosition().y;

	if (SpaceMonkey::active)
	{
		if (y <= 80)
		{
			y += speed*elapsedTime;
		}
		if (moveLeft && x > 36)
		{
			x -= speed*elapsedTime;
		}else
			{
				moveLeft = false;
			}
		
		if (!moveLeft && x < window.getSize().x -36)
		{
				x += speed*elapsedTime;
		}else
			{	
				moveLeft = true;
			}
	}	
	enemySprite.setPosition(x, y);
}


void SpaceMonkey::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(enemySprite);
	}
}

void SpaceMonkey::SetPosition(float x, float y)
{
	enemySprite.setPosition(x, y);
}

void SpaceMonkey::reduceHealth(int pDamage)
{
	int newhealth = health-pDamage;
	health = newhealth;
}

int SpaceMonkey::getHealth()
{
	return health;
}

sf::Vector2f SpaceMonkey::getPosition()
{
	return enemySprite.getPosition();
}
int SpaceMonkey::getDamage()
{
	return 20;
}