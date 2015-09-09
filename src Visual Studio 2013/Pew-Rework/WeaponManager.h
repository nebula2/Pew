//WeaponManager.h

#ifndef WEAPONMANAGER_H
#define WEAPONMANAGER_H

#include <SFML/Graphics.hpp>

class WeaponManager{
public:

	WeaponManager();
	void setWeapon(float elapsedTime, int &points, bool &gotPew);
	void Update();
	void Render(sf::RenderWindow &window);

	bool bulletA;
	bool doubleA;
	bool pewA;

private:

	sf::Texture bulletTex;
	sf::Texture doubleTex;
	sf::Texture pewTex;

	sf::Sprite bulletSprite;
	sf::Sprite doubleSprite;
	sf::Sprite pewSprite;

	int currentWeapon;
	float delay;
};

#endif