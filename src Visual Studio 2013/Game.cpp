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
	IngameSound sound;
	sound.LoadSoundBuffer();
	sound.SetBuffer();
	IngameMusic music;
	music.LoadMusic();
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
	bulletTimeCount = 0;
	enemyTimeCount = 0;
	shitCount = 0;
	healthDropCount = 0;
	randomX = 0;
	showLvUp = 0;
	damageChill = 0;
	boss1WeaponCount = 0;

	//health, points & alive
	Health health("graphics//health.png");
	health.setPosition(5, 12.5);

	Text pHealthS(20);
	pHealthS.setPosition(32, 12.5);
	pHealthS.setColor(sf::Color::Green);

	points = 0;
	Text pointS(20);
	pointS.setPosition(650, 12.5);
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
		healthDropCount += elapsedTime;
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
					return (0);
				}
			}
		}

		//screenshot
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			screenie = window.capture();
			screenie.saveToFile(filename);
		}

		//spawns
		updateMng.EnemySpawn(enemyTimeCount, enemyv, randomX);
		updateMng.HealthDropSpawn(healthDropCount, healthv, randomX);
		updateMng.SpaceMonkeySpawn(points, monkeyv);
		updateMng.ShitSpawn(shitCount, monkeyv, shitv, sound);
		updateMng.Boss1Spawn(points, boss1v);
		updateMng.UnlockPewSpawn(boss1Dead, unlockPewv);
		updateMng.Boss1WeaponSpawn(boss1WeaponCount, b1Weaponv, boss1v, sound);
		pewCD.Update(pewOnCooldown, elapsedTime);

		//bullet spawn
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
		renderMng.EnemyDraw(enemyv, elapsedTime, highscore, window);
		renderMng.HealthDraw(healthv, elapsedTime, window);
		renderMng.SpaceMonkeyDraw(monkeyv, elapsedTime, window);
		renderMng.Boss1Draw(boss1v, elapsedTime, window);
		renderMng.UnlockPewDraw(unlockPewv, elapsedTime, window);

		//player collision
		if (player1.active)
		{
			coll::PlayerEnemyInactive(enemyv, player1, sound);
			coll::PlayerEnemyInactive(shitv, player1, sound);
			coll::PlayerHealthGet(healthv, player1, sound);
			coll::PlayerEnemyInactive(b1Weaponv, player1, sound);
			coll::PlayerUnlockPew(unlockPewv, player1, sound, gotPew, pewOnCooldown);
			if (damageChill > 500)
			{
				coll::PlayerEnemyActive(monkeyv, player1, sound);
				coll::PlayerEnemyActive(boss1v, player1, sound);
				damageChill = 0;
			}
		}

		//shots draw + collisions
		if (player1.active)
		{
			renderMng.BulletDraw(bulletv, bulletviterator, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, window, elapsedTime);
			renderMng.DoubleShotDraw(dShotv, dShotIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, window, elapsedTime);
			renderMng.PewShotDraw(pewv, pewIt, points, sound, highscore, enemyv, monkeyv, shitv, boss1v, window, elapsedTime);
			renderMng.ShitDraw(shitv, shititerator, window, elapsedTime);
			renderMng.Boss1WeaponDraw(b1Weaponv, bWeaponIt, window, elapsedTime);
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
			highscore.setPoints(points);
			gameOver.Render(window);
			window.display();
			sf::sleep(sf::seconds(1));

			//hier kommt der fehler
			return 5;
		}

		window.display();
	}
	return -1;
}