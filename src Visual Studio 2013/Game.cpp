//Game.cpp

#include "Game.h"

HighscoreManager Game::getHighScore()
{
	return highscore;
	elapsedTime = 0;
}

int Game::Run(sf::RenderWindow &window)
{
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//++++++++++++++++++++++++++++++++-PREGAME STUFF-+++++++++++++++++++++++++++++++++++++++										
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool Running = true;

	//sound & music
	IOsound iosound;
	iosound.ReadSoundSettings(volume);
	IngameSound sound;
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);
	IngameMusic music;
	music.LoadMusic(volume);
	music.PlayMusic("ingamesong");

	//background and HUD
	MovableBackground bg("graphics//core//background.jpg", window);
	Background hud("graphics//core//hud.png");
	bgSpeed = 0.3;
	bgDirection = true;
	Healthbar hudHealth;
	WeaponManager weapon;

	//basic stuff
	IOtwoPlayer secPlayer;
	Player player1("graphics//player.png");
	Player2 player2("graphics//player2.png");

	player1health = player1.getHealth();
	player2health = player2.getHealth();

	//what happens if sec player is active
	if (!secPlayer.ReadSettings())
	{
		player2.active = false;
		
	}

	Game::highscore;
	UpdateManager updateMng;
	RenderManager renderMng;
	filename = "screenshot.png";

	//unlock pew
	boss1Dead = false;
	gotPew = false;
	pewOnCooldown = false;
	GUIcircleShape pewCD;

	//counter + random-x-spawn
	bulletTimeCount     = 0;
	enemyTimeCount	    = 0;
	enemyFormationCount = 0;
	shitCount	        = 0;
	healthDropCount     = 0;
	cowTimeCount	    = 0;
	randomX		   	    = 0;
	showLvUp		    = 0;
	damageChill		    = 0;
	boss1WeaponCount    = 0;
	boss2WeaponCount    = 0;

	//health, points & alive
	Health health("graphics//health.png");
	health.setPosition(0, 12.5);

	Text pHealthS(18);
	pHealthS.setPosition(23, 12.5);
	pHealthS.setColor(sf::Color::Green);

	points = 0;
	Text pointS(25);
	pointS.setPosition(650, 8);
	pointS.setColor(sf::Color::Black);
	std::stringstream pointStream;

	Text lvUp("NEW WEAPON", 60);
	lvUp.setColor(sf::Color::Yellow);
	lvUp.setOrigin(lvUp.getGlobalBounds().width / 2, lvUp.getGlobalBounds().height / 2);
	lvUp.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	Text gameOver("GAME OVER", 56);
	gameOver.setPosition(210, 250);
	gameOver.setColor(sf::Color::White);


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++-UPDATE STUFF & INITIALIZE-++++++++++++++++++++++++++++++++++++										
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	while (Running)
	{

		std::cout << player2.active << std::endl;

		//initialize counts & background movement
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
		bg.Update(window, elapsedTime, bgSpeed, bgDirection);

		//handle events
		while (window.pollEvent(event))
		{
			//close
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//menu
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					//reset stuff (bugfix)
					Game::ClearStuff();

					return (0);
				}
			}
		}

		player1health = player1.getHealth();
		player2health = player2.getHealth();

		//spawns
		updateMng.EnemySpawn(enemyTimeCount, enemyv, enemyFormationv,randomX);//enemy
		updateMng.EnemyFormationSpawn(enemyFormationCount, enemyFormationv, boss2v);//enemyFormation
		updateMng.HealthDropSpawn(healthDropCount, healthv, randomX);//health
		updateMng.SpaceMonkeySpawn(points, monkeyv, boss2v);//monkey
		updateMng.ShitSpawn(shitCount, monkeyv, shitv, sound);//shit
		updateMng.Boss1Spawn(points, boss1v);//boss1
		updateMng.UnlockPewSpawn(boss1Dead, unlockPewv);//unlockpew
		updateMng.Boss1WeaponSpawn(boss1WeaponCount, b1Weaponv, boss1v, sound);//b1Weapon
		updateMng.CowSpawn(cowTimeCount, cowv, randomX, sound);//cow
		updateMng.Boss2Spawn(boss2v, points);//boss2
		updateMng.Boss2WeaponSpawn(boss2WeaponCount, boss2Weaponv, boss2v);//b2Weapon
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				updateMng.BulletSpawn2(p2bulletTimeCount, bulletv, highscore, weapon, player2, sound);//bullet
				updateMng.DoubleShotSpawn2(p2bulletTimeCount, dShotv, highscore, weapon, player2, sound);//Doubleshot
				updateMng.PewSpawn2(pewv, highscore, weapon, player2, sound, pewOnCooldown);//Pew
			}
		}

		//hud update
		hudHealth.Update(window, player1.getHealth());
		weapon.setWeapon(elapsedTime, points, gotPew);
		weapon.Update();


		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//++++++++++++++++++++++++++++++++-DRAW & COLLISION-++++++++++++++++++++++++++++++++++++										
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		window.clear();
		bg.Render(window);

		if (player1.active)
		{
			Rm::StdDraw(healthv, elapsedTime, window);//health
			Rm::StdDraw(unlockPewv, elapsedTime, window);//unlockPew
			Rm::StdDraw(monkeyv, elapsedTime, window);//monkey
			Rm::StdDraw(boss1v, elapsedTime, window);//boss1
			Rm::StdDraw(cowv, elapsedTime, window);//cow
			Rm::StdDraw(enemyFormationv, elapsedTime, window);//enemyFormation
			Rm::StdDraw(boss2v, elapsedTime, window);//boss2
			Rm::EnemyStdWeapon(shitv, shititerator, window, elapsedTime);//shit
			Rm::EnemyStdWeapon(b1Weaponv, bWeaponIt, window, elapsedTime);//b1Weapon

			renderMng.Boss2WeaponDraw(boss2Weaponv, boss2WeaponIt, elapsedTime, player1, window);//b2Weapon
			renderMng.EnemyDraw(enemyv, elapsedTime, highscore, window);//Enemy
			renderMng.BulletDraw(bulletv, bulletviterator, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, enemyFormationv, window, elapsedTime);//bullet
			renderMng.DoubleShotDraw(dShotv, dShotIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, enemyFormationv, window, elapsedTime);//doubleShot
			renderMng.PewShotDraw(pewv, pewIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss2v, boss2Weaponv, enemyFormationv, window, elapsedTime);//Pew
		}

		//player collision
		if (player1.active)
		{
			coll::PlayerEnemyInactive(enemyv, player1, sound);//enemy
			coll::PlayerEnemyInactive(shitv, player1, sound);//shit
			coll::PlayerEnemyInactive(b1Weaponv, player1, sound);//b1Weapon
			coll::PlayerEnemyInactive(boss2Weaponv, player1, sound);//b2Weapon
			coll::PlayerEnemyInactive(enemyFormationv, player1, sound);//enemyFormation

			coll::PlayerHealthGet(healthv, player1, sound);//health
			coll::PlayerUnlockPew(unlockPewv, player1, sound, gotPew, pewOnCooldown);//unlockPew

			//for enemies that are not set inactive there is a damagechill.. otherwise player would instantly die
			if (damageChill > 500)
			{
				coll::PlayerEnemyActive(boss2v, player1, sound);//boss2
				coll::PlayerEnemyActive(cowv, player1, sound);//cow
				coll::PlayerEnemyActive(monkeyv, player1, sound);//monkey
				coll::PlayerEnemyActive(boss1v, player1, sound);//boss1
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

			coll::PlayerHealthGet(healthv, player2, sound);//health
			coll::PlayerUnlockPew(unlockPewv, player2, sound, gotPew, pewOnCooldown);//unlockPew

			//for enemies that are not set inactive there is a damagechill.. otherwise player would instantly die
			if (damageChill > 500)
			{
				coll::PlayerEnemyActive(boss2v, player2, sound);//boss2
				coll::PlayerEnemyActive(cowv, player2, sound);//cow
				coll::PlayerEnemyActive(monkeyv, player2, sound);//monkey
				coll::PlayerEnemyActive(boss1v, player2, sound);//boss1
				damageChill = 0;
			}
		}

		//health & points into string
		pHealthS.Update(healthStream, player1.getHealth());
		pointS.Update(pointStream, points);

		//players
		if (player1.active)
		{
			player1.Update(window, elapsedTime);
			player1.Render(window);

			//sync health
			if (player2.active)
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
		}

		if (player2.active)
		{
			player2.Update(window, elapsedTime);
			player2.Render(window);
		}

		//revieve a player
		if (secPlayer.ReadSettings())
		{
			if (player1.active && player1.getHealth() == 100 && !player2.active)
			{
				player2.active = true;
			}
			if (player2.active && player2.getHealth() == 100 && !player1.active)
			{
				player1.active = true;
			}
		}

		//draw HUD
		hudHealth.RenderBG(window);
		hudHealth.Render(window);
		hud.Render(window);
		pHealthS.Render(window);
		health.Render(window);
		pointS.Render(window);
		weapon.Render(window);
		pewCD.Render(window);

		//new weapon draw
		if (points >= 1000 && points <= 1050)
		{
			showLvUp += elapsedTime;
			if (showLvUp >= 0 && showLvUp <= 2000)
			{
				lvUp.Render(window);
			}
			else if (showLvUp > 2000)
			{
				showLvUp = 0;
			}
		}

		//Game over 
		if (!player1.active)
		{
			//adjust highscore and show "Game Over"
			highscore.setPoints(points);
			gameOver.Render(window);
			window.display();
			
			//reset stuff (bugfix)
			Game::ClearStuff();
			
			//delay until the highscore screen appears
			sf::sleep(sf::seconds(1));
			return 5;
		}
		
		window.display();
	}
	return -1;
}

void Game::ClearStuff()
{
	points = 0;

	//restart counters
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

	//clear vectors
	healthv.clear();
	enemyv.clear();
	monkeyv.clear();
	shitv.clear();
	cowv.clear();
	boss2v.clear();
	boss2Weaponv.clear();
	enemyFormationv.clear();
}