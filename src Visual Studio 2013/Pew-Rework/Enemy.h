//Enemy.h

#ifndef _ENEMY_H
#define _ENEMY_H

#include <SFML/Graphics.hpp>
#include "HighscoreManager.h"
#include "IOstuff.h"

class Enemy{
public:
	Enemy();
	void Update(sf::RenderWindow &window, float elapsedTime, HighscoreManager &highscore);
	void Render(sf::RenderWindow &window);
	
	//setter
	void SetPosition(float x, float y);
	void reduceHealth(int pDamage);
	
	//getter
	int getHealth() const { return m_health; };
	int getDamage() const { return 10; };

	sf::Sprite sprite;
	bool active;
private:
	void initHealthBar();
	void UpdateHealthBar();

	float m_speed;			///< the speed
	float m_rotation;		///< for enemy to spawn rotated
	float m_elapsedTime;	///< needed tmp to get random rotation
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;
	bool m_hasTargetTexture;///< true = is target | false = is not target

	static sf::Texture m_enemyTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;
};
#endif