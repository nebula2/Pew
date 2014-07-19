//boss3.h

#ifndef BOSS3_H
#define BOSS3_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

#include <iostream>

class Boss3
{
public:
	Boss3();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void setBossPosition(float x, float y);
	float getHead1XPosition();
	float getHead1YPosition();
	void setHead1Position(float x, float y);
	float getHead2XPosition();
	float getHead2YPosition();
	void setHead2Position(float x, float y);
	float getCowMXPosition();
	float getCowMYPosition();
	void setCowMPosition(float x, float y);
	void reduceHealth(int pDamage);
	float getCurrentState();
	int getDamage();
	int getHealth();
	bool getShootHeads1();
	bool getShootHeads2();
	bool getShootCows();
	bool getCowMActive();
	bool getHead1Active();
	bool getHead2Active();
	bool getGoneDead();

	bool active;
	sf::Sprite sprite;
	sf::Sprite headSprite1;
	sf::Sprite headSprite2;
	sf::Sprite cowSprite;

private:

	bool			   head1Active;
	bool			   head2Active;
	bool			   state1Dead;
	bool			   cowMActive;
	bool			   shootHeads1;
	bool			   shootHeads2;
	bool			   shootCows;
	bool			   moveLeft;
	bool			   moveDown;
	bool			   moveUp;
	bool			   goneDead;
	bool			   state3Pos;
	bool			   topAfterDeath;
	bool			   fallToGround;
	float			   speed;
	int				   damage;
	int				   health;
	int				   startHealth;
	int				   bossRotation;
	float			   currentState;
	static sf::Texture enemyTex;
	static sf::Texture headSpawnerTex;
	static sf::Texture cowSpawnerTex;
	sf::Color		   startColor;
	sf::Color		   transColor = sf::Color(255, 255, 255, 128);
};

#endif