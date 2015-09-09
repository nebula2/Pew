//RenderManager.cpp
//
//#include "RenderManager.h"


//Render for enemy Stuff 

//void RenderManager::Boss2WeaponDraw(std::vector<Boss2Weapon> &vector, sf::RenderWindow &window)
//{
//	for (auto it = vector.begin(); it != vector.end(); it++)
//	{
//		if (it->active)
//			it->Render(window);
//	}
//}

//void RenderManager::EnemyDraw(std::vector<Enemy> &vector, float &elapsedTime, HighscoreManager &highscore, sf::RenderWindow &window)
//{
//
//	for (int i = 0; i < vector.size(); i++)
//	{
//		if (vector[i].active)
//			vector[i].Render(window);
//  }
//}
//
//
////Player Weapons
//
//void RenderManager::BulletDraw(std::vector<Bullet> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window, float &elapsedTime)
//{
//	for (auto it = vector.begin(); it != vector.end(); it++)
//	{
//		if (it->active)
//			it->Render(window);
//	}
//}
//
//void RenderManager::DoubleShotDraw(std::vector<DoubleShot> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window, float &elapsedTime)
//{
//	for (auto it = vector.begin(); it != vector.end();)
//	{
//		if (!it->active)
//			it = vector.erase(it);
//
//
//			it->Render(window);
//			++it;
//		}
//	}
//}
//
//void RenderManager::PewShotDraw(std::vector<Pew> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, std::vector<Boss2> &boss2v, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window, float &elapsedTime)
//{
//	for (auto it = vector.begin(); it != vector.end();)
//	{
//		if (!it->active)
//			it = vector.erase(it);
//
//		else
//		{
//			coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
//			coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
//			coll::ProjectileToListNoHealth(it, shitv, points, sound, highscore);//shit
//			coll::ProjectileToListNoHealth(it, boss2weaponv, points, sound, highscore);//boss2Weapon
//			coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//boss3FirstWeapon
//			coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//boss3SecWeapon
//			coll::Boss2Collision(it, boss2v, points, sound, highscore);//boss2
//			coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
//			coll::Boss3Collision(boss3v, it, sound, highscore, points, boss3dead);//boss3
//
//			it->Update(elapsedTime);
//			it->Render(window);
//			++it;
//		}
//	}
//}


//OLD VERSION WILL BE ACTIVE AS LONG AS THE NEW IS NOT READY
//
//void RenderManager::Boss2WeaponDraw(std::vector<Boss2Weapon> &vector, float &elapsedTime, Player &pPlayer, Player2 &player2, sf::RenderWindow &window)
//{
//	for (auto it = vector.begin(); it != vector.end();)
//	{
//		if (!it->active)
//			it = vector.erase(it);
//
//		else
//		{
//			it->Update(window, elapsedTime, pPlayer, player2);
//			it->Render(window);
//			++it;
//		}
//	}
//}
//
//void RenderManager::EnemyDraw(std::vector<Enemy> &vector, float &elapsedTime, HighscoreManager &highscore, sf::RenderWindow &window)
//{
//
//	for (int i = 0; i < vector.size(); i++)
//	{
//		if (vector[i].active)
//		{
//			vector[i].Update(window, elapsedTime, highscore);
//			vector[i].Render(window);
//		}
//		else
//			vector.erase(vector.begin() + i);
//	}
//}
//
//
////Player Weapons
//
//void RenderManager::BulletDraw(std::vector<Bullet> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window, float &elapsedTime)
//{
//	for (auto it = vector.begin(); it != vector.end();)
//	{
//		if (!it->active)
//			it = vector.erase(it);
//
//		else
//		{
//			coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
//			coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
//			coll::ProjectileToListNoHealth(it, shitv, points, sound, highscore);//shit
//			coll::ProjectileToListNoHealth(it, boss2weaponv, points, sound, highscore);//boss2Weapon
//			coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//boss3FirstWeapon
//			coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//boss3SecWeapon
//			coll::BossCollision(it, boss1v, points, sound, highscore, boss1Dead);//boss1
//			coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
//			coll::Boss3Collision(boss3v, it, sound, highscore, points, boss3dead);//boss3
//
//			it->Update(elapsedTime);
//			it->Render(window);
//			++it;
//		}
//	}
//}
//
//void RenderManager::DoubleShotDraw(std::vector<DoubleShot> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window, float &elapsedTime)
//{
//	for (auto it = vector.begin(); it != vector.end();)
//	{
//		if (!it->active)
//			it = vector.erase(it);
//		
//		else
//		{
//			coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
//			coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
//			coll::ProjectileToListNoHealth(it, shitv, points, sound, highscore);//shit
//			coll::ProjectileToListNoHealth(it, boss2weaponv, points, sound, highscore);//boss2Weapon
//			coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//boss3FirstWeapon
//			coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//boss3SecWeapon
//			coll::BossCollision(it, boss1v, points, sound, highscore, boss1Dead);//boss1
//			coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
//			coll::Boss3Collision(boss3v, it, sound, highscore, points, boss3dead);//boss3
//
//			it->Update(elapsedTime);
//			it->Render(window);
//			++it;
//		}
//	}
//}
//
//void RenderManager::PewShotDraw(std::vector<Pew> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, std::vector<Boss2> &boss2v, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window, float &elapsedTime)
//{
//	for (auto it = vector.begin(); it != vector.end();)
//	{
//		if (!it->active)
//			it = vector.erase(it);
//		
//		else
//		{
//			coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
//			coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
//			coll::ProjectileToListNoHealth(it, shitv, points, sound, highscore);//shit
//			coll::ProjectileToListNoHealth(it, boss2weaponv, points, sound, highscore);//boss2Weapon
//			coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//boss3FirstWeapon
//			coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//boss3SecWeapon
//			coll::Boss2Collision(it, boss2v, points, sound, highscore);//boss2
//			coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
//			coll::Boss3Collision(boss3v, it, sound, highscore, points, boss3dead);//boss3
//
//			it->Update(elapsedTime);
//			it->Render(window);
//			++it;
//		}
//	}
//}