//Boss3firstWeapon.cpp

#include "Boss3firstWeapon.h"

sf::Texture Boss3firstWeapon::m_weaponTex;
sf::Texture Boss3firstWeapon::m_healthTex;

Boss3firstWeapon::Boss3firstWeapon(){
	//read settings
	IOdiff diff;
	m_diff = diff.ReadDiffSettings();
	IOsmooth smooth;

	//init stuff
	m_speed = 0.5f;
	active = true;
	m_hasTargetTexture = false;
	m_health = 1;
	m_maxHealth = m_health;


	m_weaponTex.loadFromFile("graphics/enemies/cowWeapon.png");
	m_weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_weaponTex);
	sprite.setRotation(180);
	sprite.setOrigin(m_weaponTex.getSize().x / 2.0f, m_weaponTex.getSize().y / 2.0f);

	//initialize Healthbar here to make sure that the position is known
	initHealthBar();
}

void Boss3firstWeapon::Update(sf::RenderWindow &window, float &elapsedTime){
	if (active)	{
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		if (m_yPos <= window.getSize().y){
			m_yPos += m_speed*elapsedTime;
		}		
		else{
			active = false;
		}
		
		//Update Healthbar
		UpdateHealthBar();

		//do the rest
		sprite.setPosition(m_xPos, m_yPos);
		sprite.rotate(5);
	}
}

void Boss3firstWeapon::Render(sf::RenderWindow &window){
	if (active){

		//check for mouseOver
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!m_hasTargetTexture){
				m_weaponTex.loadFromFile("graphics/enemies/cowWeapon_target.png");
				sprite.setTexture(m_weaponTex);
				m_hasTargetTexture = true;
			}
		}
		else{
			if (m_hasTargetTexture){
				m_weaponTex.loadFromFile("graphics/enemies/cowWeapon.png");
				sprite.setTexture(m_weaponTex);
				m_hasTargetTexture = false;
			}
		}

		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void Boss3firstWeapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

//Healthbar init
void Boss3firstWeapon::initHealthBar(){

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
void Boss3firstWeapon::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}