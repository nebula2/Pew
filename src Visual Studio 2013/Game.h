//Game.h

#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "IngameSfx.h"
#include "BasicStuff.h"
#include "UpdateManager.h"
#include "RenderManager.h"

#include <vector>
#include <string>
#include <sstream>

class Game : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
	HighscoreManager getHighScore();
private:
	sf::Event event;
	sf::Clock clock;
	float elapsedTime;

	//stringstreams & image
	std::stringstream healthStream;
	std::stringstream pointStream;
	std::string		  filename;
	sf::Image			  screenie;
	//vectors
	std::vector<Bullet>				   bulletv;
	std::vector<Bullet>::iterator	   bulletviterator;
	std::vector<DoubleShot>			   dShotv;
	std::vector<DoubleShot>::iterator  dShotIt;
	std::vector<Enemy>				   enemyv;
	std::vector<SpaceMonkey>		   monkeyv;
	std::vector<Boss1>				   boss1v;
	std::vector<ShitBullets>		   shitv;
	std::vector<Boss1Weapon>		   b1Weaponv;
	std::vector<ShitBullets>::iterator shititerator;
	std::vector<Boss1Weapon>::iterator bWeaponIt;
	std::vector<HealthDrop>			   healthv;
	std::vector<UnlockPew>			   unlockPewv;
	std::vector<Pew>				   pewv;
	std::vector<Pew>::iterator		   pewIt;
	HighscoreManager highscore;

	//integer
	int points;
	int bulletTimeCount;
	int enemyTimeCount;
	int shitCount;
	int boss1WeaponCount;
	int healthDropCount;
	int randomX;
	int showLvUp;
	int damageChill;

	//float
	float bgSpeed;

	//bool
	bool boss1Dead;
	bool gotPew;
	bool pewOnCooldown;
	bool bgDirection;
};

#endif