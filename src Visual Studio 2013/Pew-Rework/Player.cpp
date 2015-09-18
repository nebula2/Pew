//Player.cpp

#include "Player.h"
#include <math.h>

Player::Player(){
	m_speed = 0.7f;
	m_health = 100;
	m_active = true;
	
	//get textures
	if (!m_playerTex.loadFromFile("graphics/player.png")){
		perror("could not load player texture \"graphics/player.png\" \n");
	}
	m_playerTex.setSmooth(false);

	if (!m_playerTexMoving.loadFromFile("graphics/player_move.png")){
		perror("could not load player texture \"graphics/player_move.png\" \n");
	}
	m_playerTexMoving.setSmooth(false);

	//set up the sprite with the standing texture
	playerSprite.setTexture(m_playerTex);
	m_hasMovingTexture = false;
	playerSprite.setOrigin(m_playerTex.getSize().x / 2.0f, m_playerTex.getSize().y / 2.0f);
	playerSprite.setPosition(400.0f, 300.0f);
}

void Player::Update(sf::RenderWindow &window, float elapsedTime){
	
	//update variables
	m_xPos = playerSprite.getPosition().x;
	m_yPos = playerSprite.getPosition().y;
	m_elapsedTime = elapsedTime;

	//Handle input
	handleInput(window);

	//Handle Player Appearance
	handleRotation(window);

	//set the new Position
	playerSprite.setPosition(m_xPos, m_yPos);
}

void Player::Render(sf::RenderWindow &window){
	if (m_active){
		window.draw(playerSprite);
	}
}

void Player::reduceHealth(int pDamage){
	m_health -= pDamage;
}

void Player::increaseHealth(int heal){
	//add heal
	m_health += heal;
	//make sure player does not have more than 100 health
	if (m_health >= 100){
		m_health = 100;
	}
}

void Player::setHealth(int mhealth){
	m_health = mhealth;
}

//Handles the Input for Player-Movement
void Player::handleInput(sf::RenderWindow& window){

	//LEFT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		if (m_xPos <= 15.0f){
			m_xPos = 15.0f;
		}
		else{
			m_xPos -= m_speed * m_elapsedTime;
		}
		setMovingTexture();
	}

	//RIGHT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		if (m_xPos >= window.getSize().x - 15.0f){
			m_xPos = window.getSize().x - 15.0f;
		}
			
		else{
			m_xPos += m_speed * m_elapsedTime;
		}
		setMovingTexture();
	}

	//UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if (m_yPos <= 67.0f){
			m_yPos = 67.0f;
		}
		else{
			m_yPos -= m_speed * m_elapsedTime;
		}
		setMovingTexture();
	}

	//DOWN
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if (m_yPos >= window.getSize().y - 17.0f){
			m_yPos = window.getSize().y - 17.0f;
		}
		else{
			m_yPos += m_speed * m_elapsedTime;
		}
		setMovingTexture();
	}

	//NO MOVEMENT
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		setStandingTexture();
	}
}

//Handles the rotation so that the Player follows the mouse
void Player::handleRotation(sf::RenderWindow& window){

	//set the rotation so that the player directs to the mouse position
	playerSprite.setRotation((-atan2((float)sf::Mouse::getPosition(window).x - m_xPos, 
									 (float)sf::Mouse::getPosition(window).y - m_yPos) * 180.0f / 3.14159f));
}

//sets the Move-Texture if not set
void Player::setMovingTexture(){
	if (!m_hasMovingTexture){
		playerSprite.setTexture(m_playerTexMoving);
		m_hasMovingTexture = true;
	}
}

//sets the Standing-Texture if not set
void Player::setStandingTexture(){
	if (m_hasMovingTexture){
		playerSprite.setTexture(m_playerTex);
		m_hasMovingTexture = false;
	}
}

//sets the entity active or inactive
void Player::setActiveBool(bool active){
	m_active = active;
}