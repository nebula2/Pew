//Player.h

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player2.h"

class Player{
public:
	Player();

	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	const int getHealth();
	void reduceHealth(int pDamage);
	void increaseHealth(int heal);
	void setHealth(int mhealth); //to sync with player2
	sf::Sprite playerSprite;
	sf::Vector2f getPosition();

	bool active;

private:
	float speed;
	sf::Texture playerTex;
	int health;

};
#endif