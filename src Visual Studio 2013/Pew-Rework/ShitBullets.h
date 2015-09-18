//ShitBullets.h

#ifndef _SHIT_H
#define _SHIT_H

#include <SFML/Graphics.hpp>
#include "SpaceMonkey.h"
#include "IOstuff.h"

class ShitBullets{
public:
	ShitBullets();

	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	void SetPosition(float x, float y);
	

	//setter
	void reduceHealth(int pDamage);
	void setActiveBool(bool active);

	//getter
	int getDamage() const{ return 3 * m_diff; };
	int getHealth() const { return m_health; };
	bool getActiveBool() const { return m_active; }

	//variables
	sf::Sprite sprite;
private:
	void initHealthBar();
	void UpdateHealthBar();

	bool m_active;			///< if this is true-> it is active
	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;
	int m_diff;				///< Difficulty
	bool m_hasTargetTexture;///< true = is target | false = is not target

	sf::Vector2f pPosition;

	static sf::Texture m_shitTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;

};
#endif