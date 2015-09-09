//SpawnManager.h

#ifndef SPAWNMANAGER_H
#define SPAWNMANAGER_H

#include <vector>

//own header
#include "EntityIncludes.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"
#include "WeaponManager.h"
#include <SFML\Graphics.hpp>

class SpawnManager{
public:
	void HealthDropSpawn(int &counter, std::vector<HealthDrop> &vector, int &randomX);

	//standard enemy spawns
	void EnemySpawn(int &counter, std::vector<Enemy> &vector, std::vector<EnemyFormation> &enemyFormationv, int &randomX);
	void EnemyFormationSpawn(int &counter, std::vector<EnemyFormation> &vector, std::vector<Boss2> &boss2v);
	void CowSpawn(int &counter, std::vector<Cow> &vector, int &randomX, IngameSound &sound);
	void SpaceMonkeySpawn(int &points, std::vector<SpaceMonkey> &vector, std::vector<Boss2> &bossV);
	void ShitSpawn(int &counter, std::vector<SpaceMonkey> &smVector, std::vector<ShitBullets> &sVector, IngameSound &sound);

	//boss related spawns
	void Boss1Spawn(int &points, std::vector<Boss1> &vector);
	void Boss1WeaponSpawn(int &counter, std::vector<Boss1Weapon> &bwVector, std::vector<Boss1> &bVector, IngameSound &sound);
	void UnlockPewSpawn(bool &boss1Dead, std::vector<UnlockPew> &vector);

	void Boss2Spawn(std::vector<Boss2> &vector, int &points);
	void Boss2WeaponSpawn(int &counter, std::vector<Boss2Weapon> &bwvector, std::vector<Boss2> &bvector);

	void Boss3Spawn(std::vector<Boss3> &vector, int &points, IngameSound &sound);
	void Boss3FirstWeaponSpawn(int &counter1, int &counter2, std::vector<Boss3firstWeapon> &vector, std::vector<Boss3> &bVector, IngameSound &sound);
	void Boss3SecWeaponSpawn(int &counter, std::vector<Boss3SecWeapon> &vector, std::vector<Boss3> &bVector, IngameSound &sound);

	//weapon spawns
	void BulletSpawn(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, sf::RenderWindow& window);
	void BulletSpawn2(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, sf::RenderWindow& window);
	
	void DoubleShotSpawn(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, sf::RenderWindow& window);
	void DoubleShotSpawn2(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, sf::RenderWindow& window);
	
	void PewSpawn(std::vector<Pew> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, bool &pewOnCooldown, sf::RenderWindow& window);
	void PewSpawn2(std::vector<Pew> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, bool &pewOnCooldown, sf::RenderWindow& window);
};
#endif