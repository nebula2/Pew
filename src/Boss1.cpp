#include "Boss1.h"

sf::Texture Boss1::enemyTex;

Boss1::Boss1()
{
	speed = 0.4;
	health = 50;
	active = true;
	moveLeft = true;

	if (!enemyTex.loadFromFile("graphics//robbe.png"))
	{
		std::cout << "Enemy konnte nicht geladen werden" << std::endl;
	}

	enemyTex.setSmooth(false);
	enemySprite.setTexture(enemyTex);
	enemySprite.setOrigin(75, 65);
	enemySprite.setPosition(400, -300); 

}
void Boss1::Update(sf::RenderWindow &window, float elapsedTime)
{
	float x = enemySprite.getPosition().x;
	float y = enemySprite.getPosition().y;

	if (Boss1::active)
	{
		if (y <= 120)
		{
			y += (speed*elapsedTime)/3;
		}
		if (y <= 200)
		{
			y += speed*elapsedTime;
		}
		if (moveLeft && x > 75)
		{
			x -= speed*elapsedTime;
		}else
			{
				moveLeft = false;
			}
		
		if (!moveLeft && x < window.getSize().x -75)
		{
				x += speed*elapsedTime;
		}else
			{	
				moveLeft = true;
			}
	}	
	enemySprite.setPosition(x, y);
}


void Boss1::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(enemySprite);
	}
}

void Boss1::SetPosition(float x, float y)
{
	enemySprite.setPosition(x, y);
}

void Boss1::reduceHealth(int pDamage)
{
	int newhealth = health-pDamage;
	health = newhealth;
}

int Boss1::getHealth()
{
	return health;
}

sf::Vector2f Boss1::getPosition()
{
	return enemySprite.getPosition();
}
int Boss1::getDamage()
{
	return 25;
}