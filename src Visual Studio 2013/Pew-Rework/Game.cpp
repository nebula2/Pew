//Game.cpp

#include "Game.h"

HighscoreManager Game::getHighScore()
{
	return highscore;
}

int Game::Run(sf::RenderWindow &window)
{
	//++++++++++++++++++++++++++++++++-PREGAME STUFF-+++++++++++++++++++++++++++++++++++++++										
	
	//sound & music
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	IngameSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);
	
	//background and HUD
	MovableBackground bg("graphics//core//background.jpg", window);
	Background hud("graphics//core//hud.png");
	Healthbar hudHealth;
	WeaponManager weapon;
	GUIcircleShape pewCD;

	//basic stuff
	MessageHandler messageHandler(window);
	IOtwoPlayer secPlayer;
	UpdateManager updateMng;
	RenderManager renderMng;
	Player player1("graphics//player.png");
	Player2 player2("graphics//player2.png");

	//what happens if sec player is active
	if (!secPlayer.ReadSettings())
	{
		player2.active = false;
	}

	//counter + random-x-spawn
	Game::CountersToNull();

	//health, points & alive
	Health health("graphics//health.png");
	health.setPosition(0, 12.5);

	//++++++++++++++++++++++++-SPAWN STUFF & INITIALIZE-++++++++++++++++++++++++++++++++++++
	while (running)
	{
		//handle events
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					Game::ClearStuff();
					return (0);
				}
				if (event.key.code == sf::Keyboard::P)
				{
					if (!paused)
					{
						paused = true;
					}
					else
						paused = false;
				}
			}
		}
//___________________________________________________________________________________________
		window.clear();
		bg.Render(window);
		
		if (paused)
		{
			clock.restart();
			messageHandler.Render(window, "pauseText");
		} else 
		{
			Game::HandleSpawns(window, bg, player1, player2, updateMng, sound, pewCD, weapon);
			Game::UpdateHud(window, player1, hudHealth, weapon);

		//++++++++++++++++++++++++++-UPDATE & DRAW & COLLISION-+++++++++++++++++++++++++++++++++

			if (player1.active || player2.active)
			{
				Game::HandleDraws(window, renderMng, player1, player2, sound);
				Game::HandlePlayerInteraction(player1, player2, sound, secPlayer);			
			}

			//health & points into string
			messageHandler.UpdateStream(healthStream, player1health, "pHealthS");
			messageHandler.UpdateStream(pointStream, points, "");

			//draw HUD
			hudHealth.Render(window);
			hud.Render(window);
			messageHandler.Render(window, "pHealthS");
			health.Render(window);
			messageHandler.Render(window, "");
			weapon.Render(window);
			pewCD.Render(window);

			//new weapon draw
			messageHandler.UpdatelvUp(points, showLvUp, window, elapsedTime);

			//Game over 
			if (!player1.active)
			{
				highscore.setPoints(points);
				messageHandler.Render(window, "gameOver");
				window.display();

				Game::ClearStuff();
				sf::sleep(sf::seconds(1));
				return 5;
			}
		}

		window.display();
	}
	return -1;
}
/*
------------------------------------------------------------------------------------------------------------------------------
*/
void Game::ClearStuff()
{
	//restart counters
	points = 0;
	enemyTimeCount = 0;
	bulletTimeCount = 0;
	p2bulletTimeCount = 0;
	shitCount = 0;
	boss1WeaponCount = 0;
	boss2WeaponCount = 0;
	healthDropCount = 0;
	cowTimeCount = 0;
	damageChill = 0;
	enemyFormationCount = 0;
	boss3FirstWeaponCount1 = 0;
	boss3FirstWeaponCount2 = 0;
	boss3SecWeaponCount = 0;

	//clear vectors
	healthv.clear();
	enemyv.clear();
	monkeyv.clear();
	shitv.clear();
	boss1v.clear();
	cowv.clear();
	boss2v.clear();
	boss2Weaponv.clear();
	enemyFormationv.clear();
	boss3v.clear();
	boss3FWeaponv.clear();
	boss3SWeaponv.clear();
}
/*
------------------------------------------------------------------------------------------------------------------------------
*/
void Game::IncrementCounters()
{
	elapsedTime = clock.restart().asMilliseconds();
	enemyTimeCount += elapsedTime;
	bulletTimeCount += elapsedTime;
	p2bulletTimeCount += elapsedTime;
	shitCount += elapsedTime;
	boss1WeaponCount += elapsedTime;
	boss2WeaponCount += elapsedTime;
	healthDropCount += elapsedTime;
	cowTimeCount += elapsedTime;
	damageChill += elapsedTime;
	enemyFormationCount += elapsedTime;
	boss3FirstWeaponCount1 += elapsedTime;
	boss3FirstWeaponCount2 += elapsedTime;
	boss3SecWeaponCount += elapsedTime;
}
/*
------------------------------------------------------------------------------------------------------------------------------
*/
void Game::HandleSpawns(sf::RenderWindow &window, MovableBackground &bg, Player &player1, Player2 &player2, UpdateManager &updateMng, IngameSound &sound, GUIcircleShape &pewCD, WeaponManager &weapon)
{
	//initialize counts & background movement
	Game::IncrementCounters();
	bg.Update(window, elapsedTime, bgSpeed);

	//sync health
	player1health = player1.getHealth();
	player2health = player2.getHealth();

	//spawns
	if (boss3v.size() == 0)
	{
		updateMng.EnemySpawn(enemyTimeCount, enemyv, enemyFormationv, randomX);//enemy
		updateMng.EnemyFormationSpawn(enemyFormationCount, enemyFormationv, boss2v);//enemyFormation
		updateMng.SpaceMonkeySpawn(points, monkeyv, boss2v);//monkey
		updateMng.ShitSpawn(shitCount, monkeyv, shitv, sound);//shit
		updateMng.Boss1Spawn(points, boss1v);//boss1
		updateMng.UnlockPewSpawn(boss1Dead, unlockPewv);//unlockpew
		updateMng.Boss1WeaponSpawn(boss1WeaponCount, b1Weaponv, boss1v, sound);//b1Weapon
		if (!boss3dead) //when boss3 is dead, no more cows should be ingame :D
		{
			updateMng.CowSpawn(cowTimeCount, cowv, randomX, sound);//cow
		}
		updateMng.Boss2Spawn(boss2v, points);//boss2
		updateMng.Boss2WeaponSpawn(boss2WeaponCount, boss2Weaponv, boss2v);//b2Weapon
		updateMng.Boss3Spawn(boss3v, points, sound);//boss3
	}
	updateMng.HealthDropSpawn(healthDropCount, healthv, randomX);//health
	updateMng.Boss3FirstWeaponSpawn(boss3FirstWeaponCount1, boss3FirstWeaponCount2, boss3FWeaponv, boss3v, sound);
	updateMng.Boss3SecWeaponSpawn(boss3SecWeaponCount, boss3SWeaponv, boss3v, sound);
	

	pewCD.Update(pewOnCooldown, elapsedTime);//pewCooldown
	//player weapon spawn
	if (player1.active)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			updateMng.BulletSpawn(bulletTimeCount, bulletv, highscore, weapon, player1, sound);//bullet
			updateMng.DoubleShotSpawn(bulletTimeCount, dShotv, highscore, weapon, player1, sound);//Doubleshot
			updateMng.PewSpawn(pewv, highscore, weapon, player1, sound, pewOnCooldown);//Pew
		}
	}

	if (player2.active)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			updateMng.BulletSpawn2(p2bulletTimeCount, bulletv, highscore, weapon, player2, sound);//bullet
			updateMng.DoubleShotSpawn2(p2bulletTimeCount, dShotv, highscore, weapon, player2, sound);//Doubleshot
			updateMng.PewSpawn2(pewv, highscore, weapon, player2, sound, pewOnCooldown);//Pew
		}
	}
}
/*
------------------------------------------------------------------------------------------------------------------------------
*/
void Game::HandleDraws(sf::RenderWindow &window, RenderManager &renderMng, Player &player1, Player2 &player2, IngameSound &sound)
{
	//players
	if (player1.active)
	{
		player1.Update(window, elapsedTime);
		player1.Render(window);
	}
	if (player2.active)
	{
		player2.Update(window, elapsedTime);
		player2.Render(window);
	}
	Rm::StdDraw(healthv, elapsedTime, window);//health
	Rm::StdDraw(unlockPewv, elapsedTime, window);//unlockPew
	Rm::StdDraw(monkeyv, elapsedTime, window);//monkey
	Rm::StdDraw(boss1v, elapsedTime, window);//boss1
	Rm::StdDraw(cowv, elapsedTime, window);//cow
	Rm::StdDraw(enemyFormationv, elapsedTime, window);//enemyFormation
	Rm::StdDraw(boss2v, elapsedTime, window);//boss2
	Rm::EnemyStdWeapon(shitv, shititerator, window, elapsedTime);//shit
	Rm::EnemyStdWeapon(b1Weaponv, bWeaponIt, window, elapsedTime);//b1Weapon
	Rm::EnemyStdWeapon(boss3FWeaponv, boss3FWeaponIt, window, elapsedTime);//boss3FirstWeapon
	Rm::EnemyStdWeapon(boss3SWeaponv, boss3SweaponIt, window, elapsedTime);//boss3SecWeapon
	Rm::StdDraw(boss3v, elapsedTime, window);//boss3
	
	renderMng.Boss2WeaponDraw(boss2Weaponv, boss2WeaponIt, elapsedTime, player1, player2, window);//b2Weapon
	renderMng.EnemyDraw(enemyv, elapsedTime, highscore, window);//Enemy
	renderMng.BulletDraw(bulletv, bulletviterator, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, enemyFormationv, boss3v,boss3FWeaponv, boss3SWeaponv, boss3dead, window, elapsedTime);//bullet
	renderMng.DoubleShotDraw(dShotv, dShotIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, enemyFormationv, boss3v, boss3FWeaponv, boss3SWeaponv, boss3dead, window, elapsedTime);//doubleShot
	renderMng.PewShotDraw(pewv, pewIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss2v, boss2Weaponv, enemyFormationv, boss3v, boss3FWeaponv, boss3SWeaponv, boss3dead, window, elapsedTime);//Pew
}
/*
------------------------------------------------------------------------------------------------------------------------------
*/
void Game::CountersToNull()
{
	bulletTimeCount = 0;
	enemyTimeCount = 0;
	enemyFormationCount = 0;
	shitCount = 0;
	healthDropCount = 0;
	cowTimeCount = 0;
	randomX = 0;
	showLvUp = 0;
	damageChill = 0;
	boss1WeaponCount = 0;
	boss2WeaponCount = 0;
	boss3FirstWeaponCount1 = 0;
	boss3FirstWeaponCount2 = 0;
	boss3SecWeaponCount = 0;
}
/*
------------------------------------------------------------------------------------------------------------------------------
*/
void Game::UpdateHud(sf::RenderWindow &window, Player &player1, Healthbar &hudHealth, WeaponManager &weapon)
{
	hudHealth.Update(window, player1.getHealth());
	weapon.setWeapon(elapsedTime, points, gotPew);
	weapon.Update();
}

void Game::HandlePlayerInteraction(Player &player1, Player2 &player2, IngameSound &sound, IOtwoPlayer &secPlayer)
{
	if (player1.active)
	{
		coll::PlayerEnemyInactive(enemyv, player1, sound);//enemy
		coll::PlayerEnemyInactive(shitv, player1, sound);//shit
		coll::PlayerEnemyInactive(b1Weaponv, player1, sound);//b1Weapon
		coll::PlayerEnemyInactive(boss2Weaponv, player1, sound);//b2Weapon
		coll::PlayerEnemyInactive(enemyFormationv, player1, sound);//enemyFormation
		coll::PlayerEnemyInactive(boss3FWeaponv, player1, sound);//boss3firstWeapon
		coll::PlayerEnemyInactive(boss3SWeaponv, player1, sound);//boss3secWeapon
		coll::PlayerHealthGet(healthv, player1, sound);//health
		coll::PlayerUnlockPew(unlockPewv, player1, sound, gotPew, pewOnCooldown);//unlockPew

		if (damageChill > 500)
		{
			coll::PlayerEnemyActive(boss2v, player1, sound);//boss2
			coll::PlayerEnemyActive(cowv, player1, sound);//cow
			coll::PlayerEnemyActive(monkeyv, player1, sound);//monkey
			coll::PlayerEnemyActive(boss1v, player1, sound);//boss1
			coll::PlayerEnemyActive(boss3v, player1, sound);//boss3
			damageChill = 0;
		}
	}
	if (player2.active)
	{
		coll::PlayerEnemyInactive(enemyv, player2, sound);//enemy
		coll::PlayerEnemyInactive(shitv, player2, sound);//shit
		coll::PlayerEnemyInactive(b1Weaponv, player2, sound);//b1Weapon
		coll::PlayerEnemyInactive(boss2Weaponv, player2, sound);//b2Weapon
		coll::PlayerEnemyInactive(enemyFormationv, player2, sound);//enemyFormation
		coll::PlayerEnemyInactive(boss3FWeaponv, player2, sound);//boss3firstWeapon
		coll::PlayerEnemyInactive(boss3SWeaponv, player2, sound);//boss3secWeapon
		coll::PlayerHealthGet(healthv, player2, sound);//health
		coll::PlayerUnlockPew(unlockPewv, player2, sound, gotPew, pewOnCooldown);//unlockPew

		if (damageChill > 500)
		{
			coll::PlayerEnemyActive(boss2v, player2, sound);//boss2
			coll::PlayerEnemyActive(cowv, player2, sound);//cow
			coll::PlayerEnemyActive(monkeyv, player2, sound);//monkey
			coll::PlayerEnemyActive(boss1v, player2, sound);//boss1
			coll::PlayerEnemyActive(boss3v, player2, sound);//boss3
			damageChill = 0;
		}
	}
	//sync health
	if (player2.active && player1.active)
	{
		if (player2.getHealth() < player1.getHealth())
		{
			player1.setHealth(player2health);
		}
		if (player1.getHealth() < player2.getHealth())
		{
			player2.setHealth(player1health);
		}
	}
	//revieve a player
	if (secPlayer.ReadSettings())
	{
		if (player1.active && player1.getHealth() == 100 && !player2.active)
		{
			player2.active = true;
			player2.setHealth(100);
		}
		if (player2.active && player2.getHealth() == 100 && !player1.active)
		{
			player1.active = true;
			player1.setHealth(100);
		}
	}
}