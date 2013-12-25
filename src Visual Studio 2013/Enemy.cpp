//Enemy.cpp

#include "Enemy.h"

sf::Texture Enemy::enemyTex;

Enemy::Enemy()
{
	IOdiff diff;
	IOsmooth smooth;
	speed = 0.6;
	active = true;
	health = 2 * diff.ReadDiffSettings();

	enemyTex.loadFromFile("graphics//enemies//enemy.png");
	enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(enemyTex);
	sprite.setOrigin(36.5, 35);
}

void Enemy::Update(sf::RenderWindow &window, float elapsedTime, HighscoreManager &highscore)
{
	if (Enemy::active)
	{
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)
		{
			if (y <= window.getSize().y / 3)
			{
				y += (speed / 3) * elapsedTime;
			}
			else
			{
				y += speed * elapsedTime;
			}
		}
		else
		{
			active = false;
			highscore.setEnemyMissed(1);
		}

		sprite.setPosition(x, y);
	}
}

void Enemy::Render(sf::RenderWindow &window)
{
	if (active)
	{
		window.draw(sprite);
	}
}

void Enemy::SetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Enemy::reduceHealth(int pDamage)
{
	int newhealth = health - pDamage;
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
