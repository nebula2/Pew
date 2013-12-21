//UpdateManager.h

#ifndef UPDATEMANAGER_H
#define UPDATEMANAGER_H

//SFML and windows header
#include <vector>

//own header
#include "Entity.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"
#include "WeaponManager.h"

class UpdateManager
{
public:
	void EnemySpawn(int &counter, std::vector<Enemy> &vector, int &randomX);
	void HealthDropSpawn(int &counter, std::vector<HealthDrop> &vector, int &randomX);
	void SpaceMonkeySpawn(int &points, std::vector<SpaceMonkey> &vector, std::vector<Boss2> &bossV);
	void ShitSpawn(int &counter, std::vector<SpaceMonkey> &smVector, std::vector<ShitBullets> &sVector, IngameSound &sound);
	void Boss1Spawn(int &points, std::vector<Boss1> &vector);
	void UnlockPewSpawn(bool &boss1Dead, std::vector<UnlockPew> &vector);
	void Boss1WeaponSpawn(int &counter, std::vector<Boss1Weapon> &bwVector, std::vector<Boss1> &bVector, IngameSound &sound);
	void BulletSpawn(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound);
	void CowSpawn(int &counter, std::vector<Cow> &vector, int &randomX, IngameSound &sound);
	void DoubleShotSpawn(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound);
	void PewSpawn(std::vector<Pew> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, bool &pewOnCooldown);
	void Boss2Spawn(std::vector<Boss2> &vector, int &points);
	void Boss2WeaponSpawn(int &counter, std::vector<Boss2Weapon> &bwvector, std::vector<Boss2> &bvector);
};
#endif