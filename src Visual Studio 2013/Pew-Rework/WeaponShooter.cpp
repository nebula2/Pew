////WeaponShooter.cpp
//
//
//#include "WeaponShooter.h"
//
//WeaponShooter::WeaponShooter()
//{
//	pTexture = new sf::Texture;
//	pTexture->loadFromFile("bullet1.png");
//	pClock = new sf::Clock;
//	pClock->restart();
//	mCooldown = 0.1;
//	mLock = true;
//	mMyPosition = sf::Vector2f(0, 0);
//}
//WeaponShooter::~WeaponShooter()
//{
//	delete pTexture;
//	delete pClock;
//	pTexture = nullptr;
//	pClock = nullptr;
//}
//void WeaponShooter::Fire()
//{
//	if (mLock)
//	{
//		Shot *s = new Shot(mTarget, mMyPosition, pTexture);
//		mList.push_back(s);
//		pClock->restart();
//		mLock = false;
//	}
//}
//void WeaponShooter::Update(sf::Vector2f position, sf::Vector2f player, float frametime)
//{
//	mMyPosition = player;
//
//	if (!mLock)
//	if (pClock->getElapsedTime().asSeconds() >= mCooldown)
//		mLock = true;
//
//	//richtung berechnen
//	mTarget = position - player;
//	const float length = sqrt(pow(mTarget.x, 2) + pow(mTarget.y, 2));
//	mTarget = mTarget /= length;
//	/////////////////////////////////////////////////////////////////
//	for (auto it = mList.begin(); it != mList.end(); it++)
//	{
//		if (!(*it)->getIsAlive())
//		{
//			delete (*it);
//			(*it) = nullptr;
//
//			it = mList.erase(it);
//		}
//		else
//		{
//			(*it)->Update(frametime);
//		}
//	}
//}
//void WeaponShooter::Render(sf::RenderWindow *window)
//{
//	for (auto it : mList)
//	{
//		it->Render(window);
//	}
//}