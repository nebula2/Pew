#ifndef _PLAYER_H
#define _PLAYER_H
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
class Player
{
public:

	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	int getHealth();
	void reduceHealth(int pDamage);
	void increaseHealth (int heal);
	sf::Sprite playerSprite;
	sf::Vector2f getPosition();
	Player(std::string texture);
	
	bool active;

private:
	float speed;
	sf::Texture playerTex;
	int health;
	
};
#endif