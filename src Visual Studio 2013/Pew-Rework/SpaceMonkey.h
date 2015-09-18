//ShitMonkey.h

#ifndef SPACEMONKEY_H
#define SPACEMONKEY_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class SpaceMonkey{
public:
	SpaceMonkey();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);
	
	//setter
	void SetPosition(float x, float y);
	void reduceHealth(int pDamage);
	void setDie(bool die){ m_die = die; }
	void setActiveBool(bool active);

	//getter
	int getHealth() const { return m_health; };
	sf::Vector2f getPosition() const { return sprite.getPosition(); };
	int getDamage() const { return 20; };
	bool getDie() const { return m_die; }
	bool getActiveBool() const { return m_active; }

	//variables
	sf::Sprite sprite;
private:
	void initDeath();
	void initHealthBar();
	void UpdateHealthBar();

	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;

	bool m_hasTargetTexture;///< true = is target | false = is not target
	bool m_moveLeft;		///< True = move left | false = move right
	bool m_die;				///< if this is true-> init death animation
	bool m_active;			///< if this is true-> it is active
	sf::Vector2f m_scale;	///< Scale to set smaller if death inits
	sf::Color m_color;		///< for death animation
	int m_alpha;			///< for death animation

	static  sf::Texture m_enemyTex;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;


};

#endif