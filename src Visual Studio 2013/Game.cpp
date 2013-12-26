//Game.cpp

#include "Game.h"

HighscoreManager Game::getHighScore()
{
	return highscore;
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
	Player player1("graphics//player.png");
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
	bulletTimeCount  = 0;
	enemyTimeCount	 = 0;
	shitCount	     = 0;
	healthDropCount  = 0;
	cowTimeCount	 = 0;
	randomX			 = 0;
	showLvUp		 = 0;
	damageChill		 = 0;
	boss1WeaponCount = 0;
	boss2WeaponCount = 0;

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
	lvUp.setPosition(250, 300);

	Text gameOver("GAME OVER", 56);
	gameOver.setPosition(210, 250);
	gameOver.setColor(sf::Color::White);


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//+++++++++++++++++++++++-UPDATE STUFF & INITIALIZE-++++++++++++++++++++++++++++++++++++										
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	while (Running)
	{
		//initialize counts & background movement
		elapsedTime = clock.restart().asMilliseconds();
		enemyTimeCount += elapsedTime;
		bulletTimeCount += elapsedTime;
		shitCount += elapsedTime;
		boss1WeaponCount += elapsedTime;
		boss2WeaponCount += elapsedTime;
		healthDropCount += elapsedTime;
		cowTimeCount += elapsedTime;
		damageChill += elapsedTime;
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
					points = 0;
					enemyv.clear();
					monkeyv.clear();
					shitv.clear();
					cowv.clear();

					return (0);
				}
			}
		}

		//spawns
		updateMng.EnemySpawn(enemyTimeCount, enemyv, randomX);
		updateMng.HealthDropSpawn(healthDropCount, healthv, randomX);
		updateMng.SpaceMonkeySpawn(points, monkeyv, boss2v);
		updateMng.ShitSpawn(shitCount, monkeyv, shitv, sound);
		updateMng.Boss1Spawn(points, boss1v);
		updateMng.UnlockPewSpawn(boss1Dead, unlockPewv);
		updateMng.Boss1WeaponSpawn(boss1WeaponCount, b1Weaponv, boss1v, sound);
		updateMng.CowSpawn(cowTimeCount, cowv, randomX, sound);
		updateMng.Boss2Spawn(boss2v, points);
		updateMng.Boss2WeaponSpawn(boss2WeaponCount, boss2Weaponv, boss2v);
		pewCD.Update(pewOnCooldown, elapsedTime);

		//player weapon spawn
		if (player1.active)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				updateMng.BulletSpawn(bulletTimeCount, bulletv, highscore, weapon, player1, sound);
				updateMng.DoubleShotSpawn(bulletTimeCount, dShotv, highscore, weapon, player1, sound);
				updateMng.PewSpawn(pewv, highscore, weapon, player1, sound, pewOnCooldown);
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
			Rm::StdDraw(healthv, elapsedTime, window);
			Rm::StdDraw(unlockPewv, elapsedTime, window);
			Rm::StdDraw(monkeyv, elapsedTime, window);
			Rm::StdDraw(boss1v, elapsedTime, window);
			Rm::StdDraw(cowv, elapsedTime, window);
			Rm::StdDraw(boss2v, elapsedTime, window);
			Rm::EnemyStdWeapon(shitv, shititerator, window, elapsedTime);
			Rm::EnemyStdWeapon(b1Weaponv, bWeaponIt, window, elapsedTime);

			renderMng.Boss2WeaponDraw(boss2Weaponv, boss2WeaponIt, elapsedTime, player1, window);
			renderMng.EnemyDraw(enemyv, elapsedTime, highscore, window);
			renderMng.BulletDraw(bulletv, bulletviterator, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, window, elapsedTime);
			renderMng.DoubleShotDraw(dShotv, dShotIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, window, elapsedTime);
			renderMng.PewShotDraw(pewv, pewIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss2v, boss2Weaponv, window, elapsedTime);
		}

		//player collision
		if (player1.active)
		{
			coll::PlayerEnemyInactive(enemyv, player1, sound);
			coll::PlayerEnemyInactive(shitv, player1, sound);
			coll::PlayerEnemyInactive(b1Weaponv, player1, sound);
			coll::PlayerEnemyInactive(boss2Weaponv, player1, sound);

			coll::PlayerHealthGet(healthv, player1, sound);
			coll::PlayerUnlockPew(unlockPewv, player1, sound, gotPew, pewOnCooldown);

			//for enemies that are not set inactive there is a damagechill.. otherwise player would instantly die
			if (damageChill > 500)
			{
				coll::PlayerEnemyActive(boss2v, player1, sound);
				coll::PlayerEnemyActive(cowv, player1, sound);
				coll::PlayerEnemyActive(monkeyv, player1, sound);
				coll::PlayerEnemyActive(boss1v, player1, sound);
				damageChill = 0;
			}
		}

		//health & points into string
		pHealthS.Update(healthStream, player1.getHealth());
		pointS.Update(pointStream, points);

		//player
		if (player1.active)
		{
			player1.Update(window, elapsedTime);
			player1.Render(window);
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
			points = 0;
			enemyv.clear();
			monkeyv.clear();
			shitv.clear();
			cowv.clear();
			
			//delay until the highscore screen appears
			sf::sleep(sf::seconds(1));
			return 5;
		}
		
		window.display();
	}
	return -1;
}