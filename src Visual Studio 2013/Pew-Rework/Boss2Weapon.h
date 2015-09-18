//Boss2Weapon.h

#ifndef BOSS2WEAPON_H
#define BOSS2WEAPON_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Player2.h"
#include "IOstuff.h"

class Boss2Weapon{
public:
	Boss2Weapon();
	void Update(sf::RenderWindow &window, float &elapsedTime, Player &pPlayer);
	void Render(sf::RenderWindow &window);
	
	//setter
	void setPosition(float x, float y);
	void setActiveBool(bool active);

	//getter
	int getDamage() const { return 8 * m_diff; };
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	void initHealthBar();
	void UpdateHealthBar();

	float m_speed;				///< the speed
	float m_xPos;				///< X-Position
	float m_yPos;				///< Y-Position

	int m_diff;					///< Difficulty
	int m_health;				///< actual health
	int m_maxHealth;			///< max amount of health;

	bool m_active;			///< if this is true-> it is active
	bool m_hasTargetTexture;	///< true = is target | false = is not target
	

	static sf::Texture m_weaponTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;
};

#endif