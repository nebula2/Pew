//Game.h

#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "IngameSfx.h"
#include "BasicStuff.h"
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
	void StartPause();
	void EndPause();
	void IncrementCounters();
	void HandleSpawns(sf::RenderWindow &window, MovableBackground &bg, Player &player1, Player2 &player2, UpdateManager &updateMng, IngameSound &sound, GUIcircleShape &pewCD, WeaponManager &weapon);
	void HandleDraws(sf::RenderWindow &window, RenderManager &renderMng, Player &player1, Player2 &player2, IngameSound &sound);
	void CountersToNull();
	void UpdateHud(sf::RenderWindow &window, Player &player1, Healthbar &hudHealth, WeaponManager &weapon);

	//SMFL stuff
	sf::Event event;
	sf::Clock clock;

	//stringstreams & image
	std::stringstream healthStream;
	std::stringstream  pointStream;

	//vectors
	std::vector<Bullet>				   bulletv;
	std::vector<Bullet>::iterator	   bulletviterator;
	std::vector<DoubleShot>			   dShotv;
	std::vector<DoubleShot>::iterator  dShotIt;
	std::vector<Enemy>				   enemyv;
	std::vector<EnemyFormation>        enemyFormationv;
	std::vector<SpaceMonkey>		   monkeyv;
	std::vector<Boss1>				   boss1v;
	std::vector<Cow>				   cowv;
	std::vector<ShitBullets>		   shitv;
	std::vector<Boss1Weapon>		   b1Weaponv;
	std::vector<ShitBullets>::iterator shititerator;
	std::vector<Boss1Weapon>::iterator bWeaponIt;
	std::vector<HealthDrop>			   healthv;
	std::vector<UnlockPew>			   unlockPewv;
	std::vector<Pew>				   pewv;
	std::vector<Pew>::iterator		   pewIt;
	std::vector<Boss2>				   boss2v;
	std::vector<Boss2Weapon>		   boss2Weaponv;
	std::vector<Boss2Weapon>::iterator boss2WeaponIt;
	HighscoreManager highscore;

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
	int cowTimeCount;
	int healthDropCount;
	int randomX;
	int showLvUp;
	int damageChill;

	//float
	float bgSpeed;
	float elapsedTime;

	//bool
	bool paused;
	bool boss1Dead;
	bool gotPew;
	bool pewOnCooldown;
	bool bgDirection;
};

#endif