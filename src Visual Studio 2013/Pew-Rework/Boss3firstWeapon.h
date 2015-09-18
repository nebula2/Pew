//Boss3firstWeapon.h

#ifndef BOSS3FIRSTWEAPON_H
#define BOSS3FIRSTWEAPON_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Boss3firstWeapon{
public:
	Boss3firstWeapon();
	void Update(sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window);

	//setter
	void setPosition(float x, float y);
	void setActiveBool(bool active);

	//getters
	int getDamage() const { return 5 * m_diff; };
	bool getActiveBool() const { return m_active; }
	
	sf::Sprite sprite;
private:
	void initHealthBar();
	void UpdateHealthBar();

	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_diff;				///< Difficulty
	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;

	bool m_hasTargetTexture;///< true = is target | false = is not target
	bool m_active;			///< if this is true-> it is active

	static sf::Texture m_weaponTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;
};

#endif