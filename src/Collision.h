#ifndef _COLLISION_H
#define _COLLISION_H

//SFML and windows header
#include <vector>
#include <iostream>
//own header
#include "Entity.h"
#include "IngameSound.h"
#include "HighscoreManager.h"



class Collision
{
public:
	void BulletEnemy(std::vector<Bullet>::iterator &Obj , std::vector<Enemy> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void BulletShit(std::vector<Bullet>::iterator &Obj , std::vector<ShitBullets> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void MonkeyBullet(std::vector<Bullet>::iterator &Obj, std::vector<SpaceMonkey> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void BulletBoss1(std::vector<Bullet>::iterator &Obj, std::vector<Boss1> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore, bool &boss1Dead);

	void DoubleEnemy(std::vector<DoubleShot>::iterator &Obj , std::vector<Enemy> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void DoubleShit(std::vector<DoubleShot>::iterator &Obj , std::vector<ShitBullets> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void DoubleMonkey(std::vector<DoubleShot>::iterator &Obj, std::vector<SpaceMonkey> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void DoubleBoss1(std::vector<DoubleShot>::iterator &Obj, std::vector<Boss1> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore, bool &boss1Dead);

	void PewEnemy(std::vector<Pew>::iterator &Obj , std::vector<Enemy> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void PewShit(std::vector<Pew>::iterator &Obj , std::vector<ShitBullets> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);
	void PewMonkey(std::vector<Pew>::iterator &Obj, std::vector<SpaceMonkey> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore);

	void EnemyPlayer(std::vector<Enemy> &ObjList, Player &pPlayer, IngameSound &sound);
	void MonkeyPlayer(std::vector<SpaceMonkey> &ObjList, Player &pPlayer, IngameSound &sound);
	void ShitPlayer(std::vector<ShitBullets> &ObjList, Player &pPlayer, IngameSound &sound);
	void Boss1Player(std::vector<Boss1> &ObjList, Player &pPlayer, IngameSound &sound);
	void PlayerHealth(std::vector<HealthDrop> &ObjList, Player &pPlayer, IngameSound &sound);
	void Boss1WeaponPlayer(std::vector<Boss1Weapon> &ObjList, Player &pPlayer, IngameSound &sound);
	void UnlockPewPlayer(std::vector<UnlockPew> &ObjList, Player &pPlayer, IngameSound &sound, bool &gotPew, bool &pewOnCooldown);


};

#endif