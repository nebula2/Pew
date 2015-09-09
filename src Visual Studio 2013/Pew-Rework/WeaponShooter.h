////WeaponShooter.h
//
//#ifndef WEAPONSHOOTER_H
//#define WEAPONSHOOTER_H
//
//#include <SFML\Graphics.hpp>
//#include <list>
//
//#include "Weapon.h"
//#include "Bullet.h"
//#include "DoubleShot.h"
//#include "Pew.h"
//
//class WeaponShooter
//{
//public:
//	WeaponShooter();
//	~WeaponShooter();
//
//	void Fire();
//	void Update(sf::Vector2f position, sf::Vector2f player, float frametime);
//	void Render(sf::RenderWindow *window);
//
//	std::list<Weapon*> *getShotList(){ return &mList; };
//private:
//	std::list<Weapon*>	  mList;
//	sf::Vector2f          mTarget;
//	sf::Vector2f		  mMyPosition;
//	sf::Texture			 *pTexture;
//	sf::Clock			 *pClock;
//
//	bool				  mLock;
//	float				  mCooldown;
//};
//
//
//#endif