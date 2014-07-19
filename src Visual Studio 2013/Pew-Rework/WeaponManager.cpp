//WeaponManager.cpp

#include "WeaponManager.h"

WeaponManager::WeaponManager()
{
	currentWeapon = 0;
	delay = 0;

	bulletTex.loadFromFile("graphics//weapons//bulletA.png");
	bulletTex.setSmooth(false);
	bulletSprite.setTexture(bulletTex);
	bulletSprite.setPosition(306, 0);
	bulletA = true;

	doubleTex.loadFromFile("graphics//weapons//doubleA.png");
	doubleTex.setSmooth(false);
	doubleSprite.setTexture(doubleTex);
	doubleSprite.setPosition(374, 0);
	doubleA = false;
	
	pewTex.loadFromFile("graphics//weapons//pewA.png");
	pewTex.setSmooth(false);
	pewSprite.setTexture(pewTex);
	pewSprite.setPosition(450, 0);
	pewA = false;

}

void WeaponManager::setWeapon(float elapsedTime, int &points, bool &gotPew)
{
	delay += elapsedTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (currentWeapon != 0) && delay >= 200)
	{
		currentWeapon -= 1;
		delay = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && (currentWeapon != 1) && delay >= 200 && points >= 1000)
	{
		currentWeapon += 1;
		delay = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && (currentWeapon != 2) && delay >= 200 && gotPew)
	{
		currentWeapon += 1;
		delay = 0;
	}
}

void WeaponManager::Update()
{

	if (currentWeapon == 0)
	{
		bulletA = true;
		doubleA = false;
		pewA = false;
	}
	if (currentWeapon == 1)
	{
		bulletA = false;
		doubleA = true;
		pewA = false;
	}
	if (currentWeapon == 2)
	{
		bulletA = false;
		doubleA = false;
		pewA = true;
	}
}

void WeaponManager::Render(sf::RenderWindow &window)
{
	if (bulletA == true)
	{
		window.draw(bulletSprite);
	}
	if (doubleA == true)
	{
		window.draw(doubleSprite);
	}
	if (pewA == true)
	{
		window.draw(pewSprite);
	}
}