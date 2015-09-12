//EnemyFormation.h

#include "EnemyFormation.h"

sf::Texture EnemyFormation::m_texture;
sf::Texture EnemyFormation::m_healthTex;

EnemyFormation::EnemyFormation(){

	//Get Settings
	IOdiff diff;
	IOsmooth smooth;

	//init stuff
	m_speed = 0.6f;
	m_damage = 15;
	active = true;
	m_hasTargetTexture = false;
	m_health = 3 * diff.ReadDiffSettings();
	m_maxHealth = m_health;

	m_texture.loadFromFile("graphics/enemies/enemyFormation.png");
	m_texture.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_texture);

	//initialize Healthbar
	initHealthBar();
}
void EnemyFormation::Update(sf::RenderWindow &window, float elapsedTime){
	m_xPos = sprite.getPosition().x;
	m_yPos = sprite.getPosition().y;

	if (m_yPos <= window.getSize().y) {
		if (m_yPos <= window.getSize().y / 3){
			m_yPos += (m_speed / 3) * elapsedTime;
		}
		else{
			m_yPos += m_speed * elapsedTime;
		}
	}
	else{
		active = false;
	}
	
	//Update Healthbar
	UpdateHealthBar();

	//do the rest
	sprite.setPosition(m_xPos, m_yPos);
}
void EnemyFormation::Render(sf::RenderWindow &window){
	//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!m_hasTargetTexture){
			m_texture.loadFromFile("graphics/enemies/enemyFormation_target.png");
			sprite.setTexture(m_texture);
			m_hasTargetTexture = true;
		}
	}
	else{
		if (m_hasTargetTexture){
			m_texture.loadFromFile("graphics/enemies/enemyFormation.png");
			sprite.setTexture(m_texture);
			m_hasTargetTexture = false;
		}
	}

	window.draw(sprite);
	window.draw(m_healthbar);
}

void EnemyFormation::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

void EnemyFormation::reduceHealth(int pDamage){
	m_health -= pDamage;
}

//Healthbar init
void EnemyFormation::initHealthBar(){

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
void EnemyFormation::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}