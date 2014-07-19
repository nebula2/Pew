//Player2.h

#ifndef PLAYER2_H
#define PLAYER2_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Player2
{
public:

	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	int getHealth();
	void reduceHealth(int pDamage);
	void increaseHealth(int heal);
	void setHealth(int mhealth); //to sync with player1
	sf::Sprite playerSprite;
	sf::Vector2f getPosition();
	Player2(std::string filepath);

	bool active;

private:
	float speed;
	sf::Texture playerTex;
	int health;

};

#endif