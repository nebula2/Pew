//Boss1Weapon.h

#ifndef BOSS1WEAPON_H
#define BOSS1WEAPON_H


#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class Boss1Weapon{
public:
	Boss1Weapon();
	void Update(sf::RenderWindow &window, float &elapsedTime);
	void Render(sf::RenderWindow &window);

	//Setter
	void setPosition(float x, float y);
	void setActiveBool(bool active);

	//Getter
	int getDamage() const { return m_dmg; };
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	sf::Vector2f pPosition;
	float speed;
	static sf::Texture weaponTex;
	bool hasTargetTexture;
	bool m_active;			///< if this is true-> it is active
	IOdiff m_diff;
	int m_dmg;

};
#endif