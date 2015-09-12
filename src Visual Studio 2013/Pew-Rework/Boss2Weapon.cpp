//Boss2Weapon.cpp

#include "Boss2Weapon.h"

sf::Texture Boss2Weapon::m_weaponTex;
sf::Texture Boss2Weapon::m_healthTex;

Boss2Weapon::Boss2Weapon(){
	//read settings
	IOdiff diff;
	m_diff = diff.ReadDiffSettings();
	IOsmooth smooth;

	//Init stuff
	m_health = 1;
	m_maxHealth = m_health;

	active = true;
	m_hasTargetTexture = false;

	m_speed = 0.3f;

	m_weaponTex.loadFromFile("graphics/enemies/boss2weapon.png");
	m_weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_weaponTex);
	sprite.setOrigin(m_weaponTex.getSize().x / 2.0f, m_weaponTex.getSize().y / 2.0f);

	//initialize Healthbar
	initHealthBar();
}

void Boss2Weapon::Update(sf::RenderWindow &window, float &elapsedTime, Player &pPlayer){
	if (active)	{
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		//track Player Y
		if (m_yPos < pPlayer.getPosition().y){
			m_yPos += m_speed * elapsedTime;
		}
		if (m_yPos > pPlayer.getPosition().y){
			m_yPos -= m_speed * elapsedTime;
		}
		
		
		//track player X
		//if Weapon is left, move right
		if (m_xPos < pPlayer.getPosition().x){
			m_xPos += m_speed * elapsedTime;
		}
		//if Weapon is right, move left
		if (m_xPos > pPlayer.getPosition().x){
			m_xPos -= m_speed * elapsedTime;
		}

		//Update Healthbar
		UpdateHealthBar();

		sprite.setPosition(m_xPos, m_yPos);
	}
}

void Boss2Weapon::Render(sf::RenderWindow &window)
{
	if (active){
		//check for mouseOver
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!m_hasTargetTexture){
				m_weaponTex.loadFromFile("graphics/enemies/boss2weapon_target.png");
				sprite.setTexture(m_weaponTex);
				m_hasTargetTexture = true;
			}
		}
		else{
			if (m_hasTargetTexture){
				m_weaponTex.loadFromFile("graphics/enemies/boss2weapon.png");
				sprite.setTexture(m_weaponTex);
				m_hasTargetTexture = false;
			}
		}

		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void Boss2Weapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

//Healthbar init
void Boss2Weapon::initHealthBar(){

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
void Boss2Weapon::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}