//Game.h

#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "IngameSfx.h"
#include "BasicStuff.h"
#include "MessageHandler.h"
#include "UpdateManager.h"
#include "RenderManager.h"
#include "IOstuff.h"
#include <vector>
#include <string>
#include <sstream>

class Game : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
	HighscoreManager getHighScore();
	void ClearStuff();

private:
	void IncrementCounters();
	void HandleSpawns(sf::RenderWindow &window, MovableBackground &bg, Player &player1, Player2 &player2, UpdateManager &updateMng, IngameSound &sound, GUIcircleShape &pewCD, WeaponManager &weapon);
	void HandleDraws(sf::RenderWindow &window, RenderManager &renderMng, Player &player1, Player2 &player2, IngameSound &sound);
	void CountersToNull();
	void UpdateHud(sf::RenderWindow &window, Player &player1, Healthbar &hudHealth, WeaponManager &weapon);
	void HandlePlayerInteraction(Player &player1, Player2 &player2, IngameSound &sound, IOtwoPlayer &secPlayer);

	//SMFL stuff
	sf::Event event;
	sf::Clock clock;

	//stringstreams & image
	std::stringstream healthStream;
	std::stringstream  pointStream;

	//vectors
	std::vector<Bullet>						bulletv;
	std::vector<Bullet>::iterator			bulletviterator;
	std::vector<DoubleShot>					dShotv;
	std::vector<DoubleShot>::iterator		dShotIt;
	std::vector<Enemy>						enemyv;
	std::vector<EnemyFormation>				enemyFormationv;
	std::vector<SpaceMonkey>				monkeyv;
	std::vector<Boss1>						boss1v;
	std::vector<Cow>						cowv;
	std::vector<ShitBullets>				shitv;
	std::vector<Boss1Weapon>				b1Weaponv;
	std::vector<ShitBullets>::iterator		shititerator;
	std::vector<Boss1Weapon>::iterator		bWeaponIt;
	std::vector<HealthDrop>					healthv;
	std::vector<UnlockPew>					unlockPewv;
	std::vector<Pew>						pewv;
	std::vector<Pew>::iterator				pewIt;
	std::vector<Boss2>						boss2v;
	std::vector<Boss2Weapon>				boss2Weaponv;
	std::vector<Boss2Weapon>::iterator		boss2WeaponIt;
	std::vector<Boss3>						boss3v;
	std::vector<Boss3firstWeapon>			boss3FWeaponv;
	std::vector<Boss3firstWeapon>::iterator boss3FWeaponIt;
	std::vector<Boss3SecWeapon>				boss3SWeaponv;
	std::vector<Boss3SecWeapon>::iterator	boss3SweaponIt;

	HighscoreManager highscore;

	//integer
	int volume;
	int points = 0;
	int player1health;
	int player2health;
	int bulletTimeCount;
	int p2bulletTimeCount;
	int enemyTimeCount;
	int enemyFormationCount;
	int shitCount;
	int boss1WeaponCount;
	int boss2WeaponCount;
	int boss3FirstWeaponCount1;
	int boss3FirstWeaponCount2;
	int boss3SecWeaponCount;
	int cowTimeCount;
	int healthDropCount;
	int randomX;
	int showLvUp;
	int damageChill;

	//float
	float bgSpeed = 0.3;
	float elapsedTime;

	//bool
	bool running = true;
	bool paused = false;
	bool boss1Dead = false;
	bool gotPew = false;
	bool boss3dead = false;
	bool pewOnCooldown = false;
};

#endif