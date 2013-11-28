#ifndef GAME_H
#define GAME_H

//SFML and windows header
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include <sstream>

//own header
#include "BasicStuff.h"
#include "UpdateManager.h"
#include "RenderManager.h"

class Game : public WindowState
{
public:
	virtual int Run (sf::RenderWindow &window);
	HighscoreManager getHighScore();
private:
	//basic stuff
	sf::Event event;
	sf::Clock clock;
	float elapsedTime;
	HighscoreManager highscore;
	
	//stringstreams & image
	std::stringstream healthStream;
	std::stringstream  pointStream;
	std::string			  filename;
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

	//bool
	bool boss1Dead;
	bool gotPew;
	bool pewOnCooldown;
};

#endif