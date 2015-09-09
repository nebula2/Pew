//Player.cpp

#include "Player.h"
#include <math.h>

Player::Player(){
	speed = 0.7;
	health = 100;
	active = true;

	playerTex.loadFromFile("graphics//player.png");
	playerTex.setSmooth(false);
	playerSprite.setTexture(playerTex);
	playerSprite.setOrigin(playerTex.getSize().x / 2, playerTex.getSize().y / 2);
	playerSprite.setPosition(400, 300);
}

void Player::Update(sf::RenderWindow &window, float elapsedTime){
	float x = playerSprite.getPosition().x;
	float y = playerSprite.getPosition().y;

	//Handle input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if (x <= -7)
			x = window.getSize().x;
		
		else{
			x -= speed*elapsedTime;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if (x >= window.getSize().x + 7)
			x = 0;
		
		else{
			x += speed*elapsedTime;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if (y <= 67)
			y = 67;
		
		else{
			y -= speed*elapsedTime;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if (y >= window.getSize().y - 17)
			y = window.getSize().y - 17;
		
		else{
			y += speed*elapsedTime;
		}
	}

	//rotate the player so that he points to the mouse cursor
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerSprite.setRotation((-atan2(sf::Mouse::getPosition(window).x - x, sf::Mouse::getPosition(window).y - y)*180 / 3.14159));
	
	playerSprite.setPosition(x, y);
}

void Player::Render(sf::RenderWindow &window){
	if (active)
		window.draw(playerSprite);
}

sf::Vector2f Player::getPosition(){
	return playerSprite.getPosition();
}

const int Player::getHealth(){
	return health;
}

void Player::reduceHealth(int pDamage){
	health -= pDamage;
}

void Player::increaseHealth(int heal){
	int newHealth = health + heal;
	health = newHealth;
	if (health >= 100)
		health = 100;
}

void Player::setHealth(int mhealth){
	health = mhealth;
}