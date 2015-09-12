//boss3.h

#ifndef BOSS3_H
#define BOSS3_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

#include <iostream>

class Boss3{
public:
	Boss3();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void setBossPosition(float x, float y);

	//setter
	void reduceHealth(int pDamage);
	void setCowMPosition(float x, float y);
	void setHead1Position(float x, float y);
	void setHead2Position(float x, float y);

	//getter
	float getCurrentState() const { return m_currentState; };

	float getHead1XPosition() const { return headSprite1.getPosition().x; };
	float getHead1YPosition() const { return headSprite1.getPosition().y; };

	float getHead2XPosition() const { return headSprite2.getPosition().x; };
	float getHead2YPosition() const { return headSprite2.getPosition().y; };

	float getCowMXPosition() const { return cowSprite.getPosition().x; };
	float getCowMYPosition() const { return cowSprite.getPosition().y; };

	int getDamage() const { return m_damage; };
	int getHealth() const { return m_health; };
	bool getShootHeads1() const { return m_shootHeads1; };
	bool getShootHeads2() const { return m_shootHeads2; };
	bool getShootCows() const { return m_shootCows; };
	bool getCowMActive() const { return m_cowMActive; };
	bool getHead1Active() const { return m_head1Active; };
	bool getHead2Active() const { return m_head2Active; };
	bool getGoneDead() const { return m_goneDead; };

	bool active;
	sf::Sprite sprite;
	sf::Sprite headSprite1;
	sf::Sprite headSprite2;
	sf::Sprite cowSprite;

private:
	///PRIVATE MEMBER FUNCTIONS
	void stateMovementHandler(sf::RenderWindow& window);
	void stateMovementLR(sf::RenderWindow& window);
	void stateMovement3(sf::RenderWindow& window);
	void stateMovement4(sf::RenderWindow& window);

	void stateInitHandler();
	void stateInit0();
	void stateInit1();
	void stateInit1B();
	void stateInit2();
	void stateInit2B();
	void stateInit3();

	void initHealthBar();
	void UpdateHealthBar();

	///PRIVATE MEMBER VARIABLES

	/*
	currentState:
	0 = nothing (boss comes in, transparent)		    //dont draw other parts
	1 = heads   (boss is there and mashines drive out)  //dont draw cow spawn
	1.5 mashines active
	2 = cow (mashines dead, cow spawn thing drives out) //dont draw mashines
	2.5 active
	3 = body (cow spawn dead, body attacks by movement) //just body again
	4 = death animation
	*/
	float m_currentState;	///< indicates the current state of the boss
	float m_speed;			///< speed in which the boss moves
	float m_elapsedTime;	///< elapsed Time - given from game

	float m_xPos;			///< X-Position of Boss 3
	float m_yPos;			///< Y-Position of Boss 3
	float m_h1y;			///< Y-Position of Headspawner 1
	float m_h2y;			///< Y-Position of Headspawner 2
	float m_cmy;			///< Y-Position of Cow-Maschine

	bool m_head1Active;		///< if the first head is active this is true
	bool m_head2Active;		///< if the second head is active this is true
	bool m_state1Dead;		///< if this is true -> first state is done
	bool m_cowMActive;		///< if this is true -> Cow Machine is active
	bool m_shootHeads1;		///< if this is true -> shoot heads out of first spawner
	bool m_shootHeads2;		///< if this is true -> shoot heads out of second spawner
	bool m_shootCows;		///< if this is true -> shoot cows out of middle spawner
	bool m_moveLeft;		///< if this is true -> move to the left
	bool m_moveDown;		///< if this is true -> move down
	bool m_moveUp;			///< if this is true -> move up
	bool m_goneDead;		///< if this is true -> boss is dead
	bool m_state3Pos;		///< if this is true -> boss reached position for third state
	bool m_topAfterDeath;	///< if this is true -> top is reached after death (movement relevant)
	bool m_fallToGround;	///< if this is true -> fall to ground (movement relevant)

	int	m_damage;			///< damage the boss makes
	int	m_health;			///< the health
	int	m_maxHealth;		///< maximum health

	sf::Color m_startColor;	///< normal color
	sf::Color m_transColor;	///< transparent color 

	//Texture stuff
	static sf::Texture m_enemyTex;
	static sf::Texture m_headSpawnerTex;
	static sf::Texture m_cowSpawnerTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;
};

#endif