//Enemy.cpp

#include "Enemy.h"

sf::Texture Enemy::m_enemyTex;
sf::Texture Enemy::m_healthTex;

Enemy::Enemy(){

	//get settings
	IOdiff diff;
	IOsmooth smooth;

	//init stuff
	m_hasTargetTexture = false;
	m_die = false;
	m_active = true;

	m_speed = 0.6f;
	m_xPos = 0.0f;
	m_yPos = 0.0f;

	m_health = 2 * diff.ReadDiffSettings();
	m_maxHealth = m_health;

	m_enemyTex.loadFromFile("graphics/enemies/enemy.png");
	m_enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_enemyTex);
	sprite.setOrigin(m_enemyTex.getSize().x / 2.0f, m_enemyTex.getSize().y / 2.0f);

	//initialize Healthbar
	initHealthBar();
}

void Enemy::Update(sf::RenderWindow &window, float elapsedTime, HighscoreManager &highscore){
	if (m_active)	{
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		if (m_yPos <= window.getSize().y) {

			//at top 1/3 of screen, let it come slow
			if (m_yPos <= window.getSize().y / 3)
				m_yPos += (m_speed / 3) * elapsedTime;
			else
				//normal speed
				m_yPos += m_speed * elapsedTime;
		}
		else{
			//if enemy got through player, do this
			m_active = false;
			highscore.setEnemyMissed(1);
		}

		//Update Healthbar
		UpdateHealthBar();

		//do the rest
		sprite.setPosition(m_xPos, m_yPos);
		m_elapsedTime = elapsedTime;

		//see if death should be initialized
		m_scale = sprite.getScale();
		initDeath();
	}
}

void Enemy::Render(sf::RenderWindow &window){
	if (m_active){

		//spawn it with pseudo random rotation
		if (m_rotation < 360){
			m_rotation /= m_elapsedTime;
			sprite.rotate(m_rotation);
		}
		else{
			m_rotation = 0;
		}

		//check for mouseOver #Target
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!m_hasTargetTexture){
				m_enemyTex.loadFromFile("graphics/enemies/enemy_target.png");
				sprite.setTexture(m_enemyTex);
				m_hasTargetTexture = true;
			}
		}
		else{
			if (m_hasTargetTexture){
				m_enemyTex.loadFromFile("graphics/enemies/enemy.png");
				sprite.setTexture(m_enemyTex);
				m_hasTargetTexture = false;
			}
		}

		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void Enemy::initDeath(){
	if (m_die){
		sprite.rotate(5);
		m_scale.x -= 0.1f;
		m_scale.y -= 0.1f;
		sprite.setScale(sf::Vector2f(m_scale.x, m_scale.y));

		if (m_scale.x <= 0.05f || m_scale.y <= 0.05f){
			m_active = false;
		}
	}
}

void Enemy::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Enemy::reduceHealth(int pDamage){
	m_health -= pDamage;
}

//Healthbar init
void Enemy::initHealthBar(){
	
	//load Texture
	if (!m_healthTex.loadFromFile("graphics/enemies/health.png")){
		perror("could not load enemy healthbar");
	}

	//set texture
	m_healthbar.setTexture(&m_healthTex);

	//set size of shape to the size of the texture
	m_healthbar.setSize(sf::Vector2f((float)m_healthTex.getSize().x,(float)m_healthTex.getSize().y));

	//pseudo rect
	m_healthbar.setTextureRect(sf::IntRect(0, 0, 0, 0));
}

//Healthbar Update
void Enemy::UpdateHealthBar(){

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
void Enemy::setActiveBool(bool active){
	m_active = active;
}