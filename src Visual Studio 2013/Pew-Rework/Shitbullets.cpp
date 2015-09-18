//ShitBullets.cpp

#include "ShitBullets.h"

sf::Texture ShitBullets::m_shitTex;
sf::Texture ShitBullets::m_healthTex;

ShitBullets::ShitBullets(){
	//get Settings
	IOsmooth smooth;
	IOdiff diff;
	m_diff = diff.ReadDiffSettings();
	m_health = 1;
	m_maxHealth = m_health;

	m_active = true;
	m_hasTargetTexture = false;

	m_speed = 0.2f;

	m_shitTex.loadFromFile("graphics/enemies/shit.png");
	m_shitTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_shitTex);
	sprite.setOrigin(m_shitTex.getSize().x / 2.0f, m_shitTex.getSize().y / 2.0f);
}

void ShitBullets::Update(sf::RenderWindow &window, float elapsedTime){
	if (m_active)	{
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		//move until screen ends
		if (m_yPos <= window.getSize().y)
			m_yPos += m_speed*elapsedTime;
		else
			m_active = false;

		//Update Healthbar
		UpdateHealthBar();
		//set Position
		sprite.setPosition(m_xPos, m_yPos);
	}
}

void ShitBullets::Render(sf::RenderWindow &window){
	if (m_active){

		//check for mouseOver
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!m_hasTargetTexture){
				m_shitTex.loadFromFile("graphics/enemies/shit_target.png");
				sprite.setTexture(m_shitTex);
				m_hasTargetTexture = true;
			}
		}
		else{
			if (m_hasTargetTexture){
				m_shitTex.loadFromFile("graphics/enemies/shit.png");
				sprite.setTexture(m_shitTex);
				m_hasTargetTexture = false;
			}
		}

		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void ShitBullets::SetPosition(float x, float y){
	sprite.setPosition(x, y);

	//initialize Healthbar here to make sure that the position is known
	initHealthBar();
}

//Healthbar init
void ShitBullets::initHealthBar(){

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
void ShitBullets::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}

//sets the entity active or inactive
void ShitBullets::setActiveBool(bool active){
	m_active = active;
}