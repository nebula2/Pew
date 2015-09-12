//Boss2.cpp

#include "Boss2.h"
#include <cmath>
#define PI 3.14159265

sf::Texture Boss2::m_enemyTex;
sf::Texture Boss2::m_healthTex;

Boss2::Boss2(){
	//get settings
	IOdiff diff;
	IOsmooth smooth;

	//init stuff
	m_hasTargetTexture = false;
	active = true;
	m_fadeIn = false;
	m_moveLeft = true;

	m_speed = 0.5f;
	m_health = 200 * diff.ReadDiffSettings();
	m_maxHealth = m_health;

	m_sinValue = 0.0f;
	m_debauch = 30;

	m_enemyTex.loadFromFile("graphics/enemies/boss2.png");
	m_enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_enemyTex);
	sprite.setOrigin(m_enemyTex.getSize().x / 2.0f, m_enemyTex.getSize().y / 2.0f);

	//initialize Healthbar
	initHealthBar();
}

void Boss2::Update(sf::RenderWindow &window, float elapsedTime){

	if (Boss2::active){
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		m_sinValue += elapsedTime;

		//slow fade in
		if (!m_fadeIn){
			m_yPos += m_speed * elapsedTime / 4;
		}
			
		//if enemy is completely on screen
		if (m_yPos >= 175){
			m_fadeIn = true;
		}

		//handle X movement
		if (m_moveLeft && m_xPos > 75){
			m_xPos -= m_speed * elapsedTime;
		}
	
		else{
			m_moveLeft = false;
		}
		
		if (!m_moveLeft && m_xPos < window.getSize().x - 75){
			m_xPos += m_speed * elapsedTime;
		}
		
		else {
			m_moveLeft = true;
		}

		//handle Y movement
		if (m_fadeIn){
			m_yPos = 175 + (float)std::sin(m_sinValue * PI / 180) * m_debauch;
			
			if (m_sinValue > 360)
				m_sinValue = 0;
		}

		//Update Healthbar
		UpdateHealthBar();

		//set new coordinates
		sprite.setPosition(m_xPos, m_yPos);
	}
}

void Boss2::Render(sf::RenderWindow &window){
	if (active){
		//check for mouseOver
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!m_hasTargetTexture){
				m_enemyTex.loadFromFile("graphics/enemies/boss2_target.png");
				sprite.setTexture(m_enemyTex);
				m_hasTargetTexture = true;
			}
		}
		else{
			if (m_hasTargetTexture){
				m_enemyTex.loadFromFile("graphics/enemies/boss2.png");
				sprite.setTexture(m_enemyTex);
				m_hasTargetTexture = false;
			}
		}

		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void Boss2::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Boss2::reduceHealth(int pDamage){
	m_health -= pDamage;
}

//Healthbar init
void Boss2::initHealthBar(){

	//load Texture
	if (!m_healthTex.loadFromFile("graphics/enemies/health.png")){
		perror("could not load enemy healthbar");
	}

	//set texture
	m_healthbar.setTexture(&m_healthTex);

	//set size of shape to the size of the texture
	m_healthbar.setSize(sf::Vector2f((float)m_healthTex.getSize().x, (float)m_healthTex.getSize().y));

	//pseudo rect
	m_healthbar.setTextureRect(sf::IntRect(0, 0, 0, 0));
}

//Healthbar Update
void Boss2::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}