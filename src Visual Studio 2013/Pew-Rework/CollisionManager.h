//CollisionManager.h

#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "EntityIncludes.h"
#include "HighscoreManager.h"
#include "IngameSfx.h"
#include "Collision.h"

namespace CollisionManager
{
	template <class C>
	/**
	For Weapons which are not Pew
	**/
	void WeaponToEnemy(std::vector<C> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window)
	{
		for (auto it = vector.begin(); it != vector.end();)
		{
			if (!it->active)
				it = vector.erase(it);

			else
			{
				coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
				coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
				coll::ProjectileToListNoHealth(it, shitv, points, sound, highscore);//shit
				coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
				coll::BossCollision(it, boss1v, points, sound, highscore, boss1Dead);//boss1
				coll::ProjectileToListNoHealth(it, boss2weaponv, points, sound, highscore);//boss2Weapon
				coll::Boss3Collision(boss3v, it, sound, highscore, points, boss3dead);//boss3
				coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//boss3FirstWeapon
				coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//boss3SecWeapon

				++it;
			}
		}
	}

	template <class C>
	/**
	For Pew 
	**/
	void PewToEnemy(std::vector<C> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, std::vector<Boss2> &boss2v, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<Boss3> &boss3v, std::vector<Boss3firstWeapon> &b3FWeapon, std::vector<Boss3SecWeapon> &b3SWeapon, bool &boss3dead, sf::RenderWindow &window)
	{
		for (auto it = vector.begin(); it != vector.end();)
		{
			if (!it->active)
				it = vector.erase(it);

			else
			{
				coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
				coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
				coll::ProjectileToListNoHealth(it, shitv, points, sound, highscore);//shit
				coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
				coll::Boss2Collision(it, boss2v, points, sound, highscore);//boss2
				coll::ProjectileToListNoHealth(it, boss2weaponv, points, sound, highscore);//boss2Weapon
				coll::Boss3Collision(boss3v, it, sound, highscore, points, boss3dead);//boss3
				coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//boss3FirstWeapon
				coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//boss3SecWeapon

				++it;
			}
		}
	}
}
#endif