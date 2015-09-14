//ShitMonkey.cpp

#include "SpaceMonkey.h"

sf::Texture SpaceMonkey::m_enemyTex;
sf::Texture SpaceMonkey::m_healthTex;

SpaceMonkey::SpaceMonkey(){

	//get settings
	IOdiff diff;
	IOsmooth smooth;

	//init stuff
	m_hasTargetTexture = false;
	active = true;
	m_moveLeft = true;
	m_die = false;

	m_speed = 0.3f;
	m_health = 10 * diff.ReadDiffSettings();
	m_maxHealth = m_health;

	m_enemyTex.loadFromFile("graphics/enemies/spacemonkey.png");
	m_enemyTex.setSmooth(smooth.ReadSmoothSettings());

	sprite.setTexture(m_enemyTex);
	sprite.setOrigin(m_enemyTex.getSize().x / 2.0f, m_enemyTex.getSize().y / 2.0f);
	sprite.setPosition(364.0f, 25.0f);

	m_color = sprite.getColor();
	m_alpha = 255;
}
void SpaceMonkey::Update(sf::RenderWindow &window, float elapsedTime){
	m_xPos = sprite.getPosition().x;
	m_yPos = sprite.getPosition().y;

	if (SpaceMonkey::active) {
		//fade into screen
		if (m_yPos <= 80.0f)
			m_yPos += m_speed*elapsedTime;
		
		//move left
		if (m_moveLeft && m_xPos > 36.0f)
			m_xPos -= m_speed*elapsedTime;
		else
			m_moveLeft = false;
		
		//move right
		if (!m_moveLeft && m_xPos < window.getSize().x - 36.0f)
			m_xPos += m_speed*elapsedTime;
		else
			m_moveLeft = true;
	
		//Update Healthbar
		UpdateHealthBar();
		//set Position
		sprite.setPosition(m_xPos, m_yPos);

		//see if death should be initialized
		m_scale = sprite.getScale();
		initDeath();
	}
}


void SpaceMonkey::Render(sf::RenderWindow &window){
	if (active)

		//check for mouseOver
	if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
		if (!m_hasTargetTexture){
			m_enemyTex.loadFromFile("graphics/enemies/spacemonkey_target.png");
			sprite.setTexture(m_enemyTex);
			m_hasTargetTexture = true;
		}
	}
	else{
		if (m_hasTargetTexture){
			m_enemyTex.loadFromFile("graphics/enemies/spacemonkey.png");
			sprite.setTexture(m_enemyTex);
			m_hasTargetTexture = false;
		}
	}

		window.draw(sprite);
		window.draw(m_healthbar);
}

void SpaceMonkey::initDeath(){
	if (m_die){
		sprite.rotate(7);
		m_scale.x += 0.08f;
		m_scale.y += 0.08f;
		sprite.setScale(sf::Vector2f(m_scale.x, m_scale.y));

		m_alpha -= 10;
		sprite.setColor(sf::Color(sprite.getColor().r, sprite.getColor().g, sprite.getColor().b, m_alpha));

		if (m_scale.x >= 1.5f || m_scale.y >= 1.5f || m_alpha <=5){
			active = false;
		}
	}
}

void SpaceMonkey::SetPosition(float x, float y){
	sprite.setPosition(x, y);

	//initialize Healthbar here to make sure that the position is known
	initHealthBar();
}

void SpaceMonkey::reduceHealth(int pDamage){
	m_health -= pDamage;
}


//Healthbar init
void SpaceMonkey::initHealthBar(){

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
void SpaceMonkey::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}