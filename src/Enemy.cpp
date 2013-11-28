#include "enemy.h"

sf::Texture Enemy::enemyTex;

Enemy::Enemy()
{
	speed = 0.6;
	active = true;
	health = 2;

	enemyTex.loadFromFile("graphics//enemy.png");
	enemyTex.setSmooth(false);
	enemySprite.setTexture(enemyTex);
	enemySprite.setOrigin(36.5, 35);
}

void Enemy::Update(sf::RenderWindow &window, float elapsedTime, HighscoreManager &highscore)
{
	if (Enemy::active)
	{
		float x = enemySprite.getPosition().x;
		float y = enemySprite.getPosition().y;

		if (y <= window.getSize().y)
		{
			if (y <= window.getSize().y / 3)
			{
				y += (speed / 3) * elapsedTime;
			}else
			{
				y += speed * elapsedTime;
			}
		}else
		{
			active = false;
			highscore.setEnemyMissed(1);
		}

		enemySprite.setPosition(x, y);
	}
}

void Enemy::Render(sf::RenderWindow &window)
{
	if(active)
	{
		window.draw(enemySprite);
	}
}

void Enemy::SetPosition(float x, float y)
{
	enemySprite.setPosition(x, y);
}

void Enemy::reduceHealth(int pDamage)
{
	int newhealth = health-pDamage;
	health = newhealth;
}

int  Enemy::getHealth()
{
	return health;
}

int Enemy::getDamage()
{
	return 10;
}
