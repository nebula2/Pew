//Boss3SecWeapon.h
#ifndef BOSS3SECWEAPON_H
#define BOSS3SECWEAPON_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Boss3SecWeapon{
public:
	Boss3SecWeapon();
	void Update(sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window);
	void setPosition(float x, float y);
	void setActiveBool(bool active);

	//setter
	void reduceHealth(int pDamage);
	void setDie(bool die){ m_die = die; }
	bool getActiveBool() const { return m_active; }

	//getter
	int getHealth() const { return m_health; };
	int getDamage() const { return 5 * m_diff; };
	bool getDie() const { return m_die; }

	sf::Sprite sprite;

private:
	void initDeath();
	void initHealthBar();
	void UpdateHealthBar();

	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_diff;				///< Difficulty
	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;

	bool m_active;			///< if this is true-> it is active
	bool m_hasTargetTexture;///< true = is target | false = is not target
	bool m_die;				///< if this is true-> init death animation

	sf::Vector2f m_scale;	///< Scale to set smaller if death inits

	static sf::Texture m_weaponTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;

};
#endif