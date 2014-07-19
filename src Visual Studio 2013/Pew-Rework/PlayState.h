//PlayState.h

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "GameState.h"
#include "IngameSfx.h"
#include "BasicStuffIncludes.h"
#include "UpdateManager.h"
#include "RenderManager.h"
#include "SpawnManager.h"
#include "CollisionManager.h"
#include "IOstuff.h"

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();
	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);
	void ClearStuff();

private:
	void StartPause();
	void EndPause();
	void IncrementCounters();

	void HandleSpawns(Game &game);
	void HandleUpdates(Game &game);
	void HandleCollisions(Game &Game);
	void HandleDraws(Game &game);

	void CountersToNull();
	void UpdateHUD(sf::RenderWindow &window);

	//
	Player				player1;
	Player2				player2;
	SpawnManager		spawnManager;
	Text				pauseText, pHealthS, pointS, lvUp, gameOver;
	MovableBackground	bg;
	Background			hud;
	IOsound				iosound;
	IOtwoPlayer			secPlayer;
	IngameSound			sound;
	Healthbar			hudHealth;
	WeaponManager		weapon;
	GUIcircleShape		pewCD;
	Health				health;

	//SFML Stuff
	sf::Event pEvent;
	sf::Clock pClock;

	//stringstream
	std::stringstream healthStream;
	std::stringstream pointStream;

	//vectors
	std::vector<Bullet>						bulletv;
	std::vector<DoubleShot>					dShotv;
	std::vector<Enemy>						enemyv;
	std::vector<EnemyFormation>				enemyFormationv;
	std::vector<SpaceMonkey>				monkeyv;
	std::vector<Boss1>						boss1v;
	std::vector<Cow>						cowv;
	std::vector<ShitBullets>				shitv;
	std::vector<Boss1Weapon>				b1Weaponv;
	std::vector<HealthDrop>					healthv;
	std::vector<UnlockPew>					unlockPewv;
	std::vector<Pew>						pewv;
	std::vector<Pew>::iterator				pewIt;
	std::vector<Boss2>						boss2v;
	std::vector<Boss2Weapon>				boss2Weaponv;
	std::vector<Boss3>						boss3v;
	std::vector<Boss3firstWeapon>			boss3FWeaponv;
	std::vector<Boss3SecWeapon>				boss3SWeaponv;

	//integer
	int volume;
	int points;
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
	float bgSpeed = 0.3f;
	float elapsedTime;

	//bool
	bool paused			= false;
	bool boss1Dead		= false;
	bool gotPew			= false;
	bool pewOnCooldown  = false;
	bool boss3dead		= false;
};

#endif