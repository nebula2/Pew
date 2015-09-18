//Boss2.h

#ifndef BOSS2_H
#define BOSS2_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include "IOstuff.h"

class Boss2{
public:
	Boss2();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);

	//setter
	void setPosition(float x, float y);
	void reduceHealth(int pDamage);
	void setActiveBool(bool active);

	//getter
	int getHealth() const { return m_health; };
	int getDamage() const { return 30; };
	bool getfadeIn() const { return m_fadeIn; };
	sf::Vector2f getPosition() const { return sprite.getPosition(); };
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	void initHealthBar();
	void UpdateHealthBar();

	float m_sinValue;		///< value for curvy motion
	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;
	int m_debauch;			///< value for curvy motion

	bool m_active;			///< if this is true-> it is active
	bool m_fadeIn;			///< True = fading in | false = is there
	bool m_moveLeft;		///< True = move left | false = move right
	bool m_hasTargetTexture;///< true = is target | false = is not target

	static sf::Texture m_enemyTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;
};

#endif