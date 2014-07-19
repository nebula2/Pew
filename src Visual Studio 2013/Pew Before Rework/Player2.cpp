//Player2.cpp

#include "Player2.h"

Player2::Player2(std::string filepath)
{

	speed = 0.7;
	health = 100;
	active = true;

	playerTex.loadFromFile(filepath);
	playerTex.setSmooth(false);
	playerSprite.setTexture(playerTex);
	playerSprite.setOrigin(23, 17);
	playerSprite.setPosition(400, 300);
}

void Player2::Update(sf::RenderWindow &window, float elapsedTime)
{
	float x = playerSprite.getPosition().x;
	float y = playerSprite.getPosition().y;
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2i center(window.getSize().x / 2, window.getSize().y / 2);

	if (mousePos.x < window.getSize().x / 2)//left
	{
		//move player2
		if (x <= -7)
		{
			x = window.getSize().x;
		}
		else
		{
			x -= speed*elapsedTime;
		}
		//reset mouse
		sf::Mouse::setPosition(center, window);
	}

	if (mousePos.x > window.getSize().x / 2) //right
	{
		
		if (x >= window.getSize().x + 7)
		{
			x = 0;
		}
		else
		{
			x += speed*elapsedTime;
		}
		//reset mouse
		sf::Mouse::setPosition(center, window);
	}

	if (mousePos.y < window.getSize().y / 2)//up
	{
		if (y <= 67)
		{
			y = 67;
		}
		else
		{
			y -= speed*elapsedTime;
		}
		//reset mouse
		sf::Mouse::setPosition(center, window);
	}

	if (mousePos.y > window.getSize().y / 2)
	{
		if (y >= window.getSize().y - 17)
		{
			y = window.getSize().y - 17;
		}
		else
		{
			y += speed*elapsedTime;
		}
		//reset mouse
		sf::Mouse::setPosition(center, window);
	}

	playerSprite.setPosition(x, y);
}

void Player2::Render(sf::RenderWindow &window)
{
	if (active)
	{
		window.draw(playerSprite);
	}
}

sf::Vector2f Player2::getPosition()
{
	return playerSprite.getPosition();
}

int Player2::getHealth()
{
	return health;
}

void Player2::reduceHealth(int pDamage)
{
	int newhealth = health - pDamage;
	health = newhealth;
}

void Player2::increaseHealth(int heal)
{
	int newHealth = health + heal;
	health = newHealth;
	if (health >= 100)
	{
		health = 100;
	}
}

void Player2::setHealth(int mhealth)
{
	health = mhealth;
}