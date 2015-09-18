//boss3.cpp

#include "Boss3.h"

sf::Texture Boss3::m_enemyTex;
sf::Texture Boss3::m_headSpawnerTex;
sf::Texture Boss3::m_cowSpawnerTex;
sf::Texture Boss3::m_healthTex;

Boss3::Boss3(){
	//get Settings
	IOdiff   diff;
	IOsmooth smooth;

	//init stuff
	m_elapsedTime = 0.0f;
	m_speed = 0.5f;
	m_health = 50 * diff.ReadDiffSettings();
	m_maxHealth = m_health;
	m_damage = 10;
	m_currentState = 0.0f;
	m_active = true;
	m_head1Active = false;
	m_head2Active = false;
	m_cowMActive = false;
	m_shootHeads1 = false; //shoot heads on left side
	m_shootHeads2 = false; //shoot heads on right side
	m_state1Dead = false; //do not jump into state 2	
	m_shootCows = false; //shoot cows or not
	m_moveLeft = true;  //movement indicator
	m_moveDown = false;
	m_moveUp = false;
	m_state3Pos = false;
	m_goneDead = false; //indicator for death
	m_topAfterDeath = false;
	m_fallToGround = false;
	m_startColor = sprite.getColor();
	m_transColor = sf::Color(255, 255, 255, 128);

	//Texture - Sprite Stuff
	m_enemyTex.loadFromFile("graphics/enemies/cowmashine.jpg");
	m_headSpawnerTex.loadFromFile("graphics/enemies/motor.png");
	m_cowSpawnerTex.loadFromFile("graphics/enemies/cowspawner.png");
	
	m_enemyTex.setSmooth(smooth.ReadSmoothSettings());
	m_headSpawnerTex.setSmooth(smooth.ReadSmoothSettings());
	m_cowSpawnerTex.setSmooth(smooth.ReadSmoothSettings());

	sprite.setTexture(m_enemyTex);
	headSprite1.setTexture(m_headSpawnerTex);
	headSprite2.setTexture(m_headSpawnerTex);
	cowSprite.setTexture(m_cowSpawnerTex);
	

	//set start positions for all parts
	sprite.setPosition(150, -300);
	headSprite1.setPosition(sprite.getPosition().x, sprite.getPosition().y + 150);
	headSprite2.setPosition(sprite.getPosition().x + 400, sprite.getPosition().y + 150);
	cowSprite.setPosition(sprite.getPosition().x + 100, sprite.getPosition().y + 150);

	//initialize Healthbar
	initHealthBar();
}

void Boss3::Update(sf::RenderWindow &window, float elapsedTime){
	if (m_active) {

		m_elapsedTime = elapsedTime;
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;
		m_h1y = headSprite1.getPosition().y;
		m_h2y = headSprite2.getPosition().y;
		m_cmy = cowSprite.getPosition().y;

		//see if boss is dead
		if (m_health <= 0)
			m_goneDead = true;

		//handle Movement for each state
		stateMovementHandler(window);

		//handle initialization for each state
		stateInitHandler();

		//Update Healthbar
		UpdateHealthBar();
	}
}

void Boss3::Render(sf::RenderWindow &window)
{
	if (m_active){
		if (m_cowMActive)
			window.draw(cowSprite); //machine
		
		if (m_head1Active)
			window.draw(headSprite1); //left head
		
		if (m_head2Active)
			window.draw(headSprite2); //right head

		window.draw(sprite);

		//draw Healthbar only when boss is attackable
		if (m_currentState == 3){
			window.draw(m_healthbar);
		}
	}
}

//setter
void Boss3::setBossPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Boss3::setHead1Position(float x, float y){
	headSprite1.setPosition(x, y);
}

void Boss3::setHead2Position(float x, float y){
	headSprite2.setPosition(x, y);
}

void Boss3::setCowMPosition(float x, float y){
	cowSprite.setPosition(x, y);
}

void Boss3::reduceHealth(int pDamage){
	m_health -= pDamage;
}

//Move left and right
void Boss3::stateMovementLR(sf::RenderWindow& window){
	//Move left
	if (m_moveLeft && m_xPos > -100){
		m_xPos -= m_speed * m_elapsedTime;
	}
	else{
		m_moveLeft = false;
	}
	
	//Move right
	if (!m_moveLeft && m_xPos < window.getSize().x - 400){
		m_xPos += m_speed * m_elapsedTime;
	}
		
	else{
		m_moveLeft = true;
	}
	
	//set new Position
	sprite.setPosition(m_xPos, m_yPos);
}

//handles movement of third state
void Boss3::stateMovement3(sf::RenderWindow& window){
	//move fast to the start position
	if (!m_state3Pos){
		if (m_xPos < window.getSize().x / 2){
			m_xPos += m_speed * m_elapsedTime * 2;
			m_moveLeft = false;
			m_state3Pos = true;
		}
		if (m_xPos >= window.getSize().x / 2){
			m_xPos -= m_speed * m_elapsedTime * 2;
			m_moveLeft = false;
			m_state3Pos = true;
		}
	}
	//RIGHT
	if (!m_moveLeft && !m_moveDown && !m_moveUp){
		if (m_xPos < window.getSize().x - 200){
			if (m_health > m_maxHealth / 2)
				m_xPos += m_speed * m_elapsedTime;

			else
				m_xPos += m_speed * m_elapsedTime * 1.5f;
		}

		if (m_xPos >= (float)window.getSize().x - 200.0f){
			m_xPos = (float)window.getSize().x - 200.0f;
			m_moveLeft = true;
			m_moveDown = true;
		}
	}

	//DOWN
	if (m_moveLeft && m_moveDown && !m_moveUp){
		if (m_yPos < window.getSize().y - 200){
			if (m_health > m_maxHealth / 2)
				m_yPos += m_speed * m_elapsedTime;

			else
				m_yPos += m_speed * m_elapsedTime * 1.5f;
		}

		if (m_yPos >= (float)window.getSize().y - 200.0f){
			m_yPos = (float)window.getSize().y - 200.0f;
			m_moveDown = false;
		}
	}

	//LEFT
	if (m_moveLeft && !m_moveDown && !m_moveUp){
		if (m_xPos > 200.0f){
			if (m_health > m_maxHealth / 2)
				m_xPos -= m_speed * m_elapsedTime;

			else
				m_xPos -= m_speed * m_elapsedTime * 1.5f;
		}
		if (m_xPos <= 200){
			m_xPos = 200;
			m_moveLeft = false;
			m_moveUp = true;
		}
	}

	//UP
	if (!m_moveLeft && !m_moveDown && m_moveUp){
		if (m_yPos > 200){
			if (m_health > m_maxHealth / 2)
				m_yPos -= m_speed * m_elapsedTime;

			else
				m_yPos -= m_speed * m_elapsedTime * 1.5f;

		}
		if (m_yPos <= 200){
			m_yPos = 200;
			m_moveUp = false;
		}
	}
	sprite.setPosition(m_xPos, m_yPos);
}

//handles movement of fourth state
void Boss3::stateMovement4(sf::RenderWindow& window){
	//DIE Motherf***er
	if (!m_topAfterDeath){
		if (m_yPos > -600)
			m_yPos -= m_speed * m_elapsedTime;

		if (m_yPos <= -590 && m_yPos > -600){
			m_topAfterDeath = true;
			sprite.setRotation(0);
		}
		sprite.setPosition(m_xPos, m_yPos);
	}
	if (m_topAfterDeath)
		m_fallToGround = true;

	if (m_fallToGround){
		if (m_yPos < 700){
			m_yPos += m_speed * m_elapsedTime * 2;
			sprite.setPosition(m_xPos, m_yPos);
		}
		if (m_yPos >= 700)
			m_active = false;
	}
}

//inits state 0
void Boss3::stateInit0(){
	sprite.setColor(m_transColor);
	if (m_yPos < 0){
		m_yPos += m_speed * m_elapsedTime / 7;
		sprite.setPosition(m_xPos, m_yPos);
	}

	//care that the other parts are behind boss
	headSprite1.setPosition(m_xPos, m_yPos + 150);
	headSprite2.setPosition(m_xPos + 400, m_yPos + 150);
	cowSprite.setPosition(m_xPos + 100, m_yPos + 150);

	if (m_yPos >= 0 && m_yPos < 2){
		sprite.setColor(m_startColor);
		sprite.setPosition(sprite.getPosition().x, 0);
		m_currentState = 1;
	}
}

//inits state 1
void Boss3::stateInit1(){
	//activate heads
	if (!m_head1Active || !m_head2Active){
		m_head1Active = true;
		m_head2Active = true;
	}

	//positioning
	if (m_h1y < 200)
		headSprite1.setPosition(m_xPos, m_h1y += m_speed * m_elapsedTime / 6);

	else
		headSprite1.setPosition(m_xPos, m_yPos + 200);

	if (m_h2y < 200)
		headSprite2.setPosition(m_xPos + 400, m_h2y += m_speed * m_elapsedTime / 6);

	else
		headSprite2.setPosition(m_xPos + 400, m_yPos + 200);

	if ((m_h1y >= 199 && m_h1y <= 201) || (m_h2y >= m_yPos + 199 && m_h2y <= m_yPos + 201))
		m_currentState = 1.5;
}

//inits state 1.5
void Boss3::stateInit1B(){
	m_shootHeads1 = true;
	m_shootHeads2 = true;

	headSprite1.setPosition(sprite.getPosition().x, m_h1y);
	headSprite2.setPosition(sprite.getPosition().x + 400, m_h2y);

	if (m_h1y <= m_yPos + 150){
		m_shootHeads1 = false;
		m_head1Active = false;
		m_state1Dead = true;
	}
	if (m_h2y <= m_yPos + 150){
		m_shootHeads2 = false;
		m_head2Active = false;
		m_state1Dead = true;
	}
	if (!m_shootHeads1 && !m_shootHeads2 && m_state1Dead){
		m_currentState = 2;
		cowSprite.setPosition(m_xPos + 100, m_yPos + 150);
		m_cowMActive = true;
	}
}

//inits state 2
void Boss3::stateInit2(){
	if (m_cmy <= m_yPos + 200){
		cowSprite.setPosition(m_xPos + 100, m_cmy += m_speed * m_elapsedTime / 4);
	}
	else{
		cowSprite.setPosition(m_xPos + 100, m_yPos + 200);
	}
	if (m_cmy >= 199 && m_cmy < 201){
		cowSprite.setPosition(sprite.getPosition().x + 100, m_cmy);
		m_currentState = 2.5;
		m_shootCows = true;
	}
}

//inits state 2.5
void Boss3::stateInit2B(){
	cowSprite.setPosition(sprite.getPosition().x + 100, m_cmy);

	if (m_cmy <= m_yPos + 150){
		m_shootCows = false;
		m_cowMActive = false;
	}
	if (!m_cowMActive)
		m_currentState = 3;
}

//inits state 3
void Boss3::stateInit3(){
	if (m_yPos <= 175 && sprite.getOrigin().x != m_enemyTex.getSize().x / 2){
		m_yPos += m_speed * m_elapsedTime / 2;
	}

	//get dat thing to rotate :D
	sprite.setOrigin(m_enemyTex.getSize().x / 2.0f, m_enemyTex.getSize().y / 2.0f);

	sprite.rotate(5);

	if (m_health <= 0)
		m_currentState = 4;
}

//Healthbar init
void Boss3::initHealthBar(){

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
void Boss3::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}

void Boss3::stateMovementHandler(sf::RenderWindow& window){
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++++++++++++++-MOVEMENT-+++++++++++++++++++++++++++++++++++++++++
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	/*
	from 1 to 2.5 simple left to right as seen before
	3 = move from corner to corner in a square
	4 = move to the top from where it is, then sink to the bottom
	*/

	if (m_currentState >= 1 && m_currentState <= 2.5) {
		stateMovementLR(window);
	}

	if (m_currentState == 3){
		stateMovement3(window);
	}

	if (m_currentState == 4){
		stateMovement4(window);
	}
}

void Boss3::stateInitHandler(){
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//++++++++++++++++++++++++++++++++-INITIALIZATION-++++++++++++++++++++++++++++++++++++++
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	//state 0
	if (m_currentState == 0){
		stateInit0();
	}

	//state 1
	if (m_currentState == 1){
		stateInit1();
	}

	//state 1.5 (collision movement for the maschines controlled by collision)
	if (m_currentState == 1.5){
		stateInit1B();
	}

	//state2
	if (m_currentState == 2){
		stateInit2();
	}

	//state 2.5
	if (m_currentState == 2.5){
		stateInit2B();
	}

	//state 3
	if (m_currentState == 3){
		//get good position to rotate
		stateInit3();
	}
}

//sets the entity active or inactive
void Boss3::setActiveBool(bool active){
	m_active = active;
}