//PlayState.cpp

#include "PlayState.h"

PlayState::PlayState(){
	CountersToNull();
	mousePos.x = 0;
	mousePos.y = 0;

	//sound & music
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//background and HUD
	bg.setStuff("graphics/core//background.jpg", sf::Vector2f(800, 600));
	hud.setFilePath("graphics/core//hud.png");
	bgSpeed = 0.3f;
	health.setPosition(0, 12.5);

	player2.active = false;
	playerHealth = player1.getHealth();

	//unlock pew
	boss1Dead = false;
	gotPew = false;
	pewOnCooldown = false;
}

PlayState::~PlayState(){
}

void PlayState::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent))	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		if (pEvent.type == sf::Event::KeyPressed){
			if (pEvent.key.code == sf::Keyboard::Escape){
				if (!paused)
					StartPause();
				else 
					game.ChangeState(Game::gameStates::MAINMENU);
			}
	
			if (pEvent.key.code == sf::Keyboard::Return && !paused)
				EndPause();
		}
	}
}

void PlayState::Update(Game &game){

	//always set the mouse position
	mousePos = sf::Mouse::getPosition(game.window);

	if (paused)
		pClock.restart();

	if (!paused){
		//Handle everything
		HandleSpawns(game);
		HandleUpdates(game);
		HandleCollisions(game);

		//health & points into string
		playerHealth = player1.getHealth();
		messageHandler.UpdateStream(healthStream, playerHealth, "pHealthS");
		messageHandler.UpdateStream(pointStream, points, "");
	}
}

void PlayState::Render(Game &game){
	bg.Render(game.window);

	if (player1.active)
		if (!paused)
			HandleDraws(game);

		if (gotPew)
			pewCD.Render(game.window);

		if (paused){
			messageHandler.Render(game.window, "pauseText");
			messageHandler.Render(game.window, "pausedInfo");
		}

	//draw HUD
	hudHealth.Render(game.window);
	hud.Render(game.window);
	messageHandler.Render(game.window, "pHealthS");
	health.Render(game.window);
	messageHandler.Render(game.window, "");
	weapon.Render(game.window);

	//new Weapon draw
	messageHandler.UpdatelvUp(points, showLvUp, game.window, elapsedTime);

	//Game over 
	if (!player1.active){
		game.highscore.setPoints(points);
		messageHandler.Render(game.window, "gameOver");

		game.window.display();
		ClearStuff();
		sf::sleep(sf::seconds(1));
		game.ChangeState(Game::gameStates::HIGHSCORE);
	}
}

void PlayState::ClearStuff(){
	points = 0;

	//restart counters
	enemyTimeCount = 0;
	bulletTimeCount = 0;
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
void PlayState::StartPause(){
	paused = true;
}
void PlayState::EndPause(){
	paused = false;
}
void PlayState::IncrementCounters(){
	elapsedTime = pClock.restart().asMilliseconds();
	enemyTimeCount += elapsedTime;
	bulletTimeCount += elapsedTime;
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
void PlayState::HandleSpawns(Game &game){
	//initialize counts & background movement
	IncrementCounters();
	bg.Update(game.window, elapsedTime, bgSpeed);

	//spawns
	if (boss3v.size() == 0){
		spawnManager.EnemySpawn(enemyTimeCount, enemyv, enemyFormationv, randomX);		//enemy
		spawnManager.EnemyFormationSpawn(enemyFormationCount, enemyFormationv, boss2v);//enemyFormation
		spawnManager.SpaceMonkeySpawn(points, monkeyv, boss2v);							//monkey
		spawnManager.ShitSpawn(shitCount, monkeyv, shitv, sound);						//shit
		spawnManager.Boss1Spawn(points, boss1v);										//boss1
		spawnManager.UnlockPewSpawn(boss1Dead, unlockPewv);								//unlockpew
		spawnManager.Boss1WeaponSpawn(boss1WeaponCount, b1Weaponv, boss1v, sound);		//b1Weapon
		spawnManager.Boss2Spawn(boss2v, points);										//boss2
		spawnManager.Boss2WeaponSpawn(boss2WeaponCount, boss2Weaponv, boss2v);			//b2Weapon
		spawnManager.Boss3Spawn(boss3v, points, sound);									//boss3

		if (!boss3dead)
			spawnManager.CowSpawn(cowTimeCount, cowv, randomX, sound);//cow
	}
	spawnManager.HealthDropSpawn(healthDropCount, healthv, randomX);//health
	spawnManager.Boss3FirstWeaponSpawn(boss3FirstWeaponCount1, boss3FirstWeaponCount2, boss3FWeaponv, boss3v, sound);
	spawnManager.Boss3SecWeaponSpawn(boss3SecWeaponCount, boss3SWeaponv, boss3v, sound);

	pewCD.Update(pewOnCooldown, elapsedTime);//pewCooldown

	//player weapon spawn
	if (player1.active){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
			spawnManager.BulletSpawn(bulletTimeCount, bulletv, game.highscore, weapon, player1, sound, game.window);//bullet
			spawnManager.DoubleShotSpawn(bulletTimeCount, dShotv, game.highscore, weapon, player1, sound, game.window);//Doubleshot
			spawnManager.PewSpawn(pewv, game.highscore, weapon, player1, sound, pewOnCooldown, game.window);//Pew
		}
	}
}

void PlayState::HandleUpdates(Game &game){
	UpdateManager::EnemyUpdate(enemyv, game.window, elapsedTime, game.highscore);				//enemy
	UpdateManager::StdUpdate(enemyFormationv, game.window, elapsedTime);						//enemyFormation
	UpdateManager::StdUpdate(monkeyv, game.window, elapsedTime);								//monkey
	UpdateManager::StdUpdate(shitv, game.window, elapsedTime);									//shit
	UpdateManager::StdUpdate(boss1v, game.window, elapsedTime);									//boss1
	UpdateManager::StdUpdate(unlockPewv, game.window, elapsedTime);								//unlockpew
	UpdateManager::StdUpdate(b1Weaponv, game.window, elapsedTime);								//b1Weapon
	UpdateManager::StdUpdate(boss2v, game.window, elapsedTime);									//boss2
	UpdateManager::Boss2WeaponUpdate(boss2Weaponv, game.window, elapsedTime, player1, player2); // b2Weapon
	UpdateManager::StdUpdate(boss3v, game.window, elapsedTime);									//boss3
	UpdateManager::StdUpdate(cowv, game.window, elapsedTime);									//cow
	UpdateManager::StdUpdate(healthv, game.window, elapsedTime);								//health
	UpdateManager::StdUpdate(boss3FWeaponv, game.window, elapsedTime);							//boss3firstWeapon
	UpdateManager::StdUpdate(boss3SWeaponv, game.window, elapsedTime);							//boss3SecWeapon
																								
	UpdateManager::WeaponUpdate(bulletv, elapsedTime);								//bullet
	UpdateManager::WeaponUpdate(dShotv, elapsedTime);								//double shot
	UpdateManager::WeaponUpdate(pewv, elapsedTime);									//pewv

	UpdateHUD(game.window);

	if (player1.active)
	player1.Update(game.window, elapsedTime);

	if (player2.active)
	player2.Update(game.window, elapsedTime);
}

void PlayState::HandleDraws(Game &game){
	if (player1.active)
		player1.Render(game.window);

	Rm::StdDraw(healthv, game.window);//health
	Rm::StdDraw(unlockPewv, game.window);//unlockPew

	Rm::StdDraw(enemyv, game.window);//Enemy
	Rm::StdDraw(shitv, game.window);//shit
	Rm::StdDraw(monkeyv, game.window);//monkey

	Rm::StdDraw(enemyFormationv, game.window);//enemyFormation
	Rm::StdDraw(cowv, game.window);//cow

	Rm::StdDraw(b1Weaponv, game.window);//b1Weapon
	Rm::StdDraw(boss1v, game.window);//boss1
	Rm::StdDraw(boss2Weaponv, game.window);//b2Weapon
	Rm::StdDraw(boss2v, game.window);//boss2

	Rm::StdDraw(boss3FWeaponv, game.window);//boss3FirstWeapon
	Rm::StdDraw(boss3SWeaponv, game.window);//boss3SecWeapon
	Rm::StdDraw(boss3v, game.window);//boss3

	Rm::StdDraw(bulletv, game.window);//bullet
	Rm::StdDraw(dShotv, game.window);//doubleShot
	Rm::StdDraw(pewv,game.window);//Pew
}

void PlayState::HandleCollisions(Game &game){
	CollisionManager::WeaponToEnemy(bulletv, points, sound, game.highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, enemyFormationv, boss3v, boss3FWeaponv, boss3SWeaponv, boss3dead, game.window);//bullet
	CollisionManager::WeaponToEnemy(dShotv, points, sound, game.highscore, enemyv, monkeyv, shitv, boss1v, boss1Dead, boss2Weaponv, enemyFormationv, boss3v, boss3FWeaponv, boss3SWeaponv, boss3dead, game.window);//doubleShot
	CollisionManager::PewToEnemy(pewv, points, sound, game.highscore, enemyv, monkeyv, shitv, boss1v, boss2v, boss2Weaponv, enemyFormationv, boss3v, boss3FWeaponv, boss3SWeaponv, boss3dead, game.window);//Pew
	if (player1.active)	{
		//player collision
		coll::PlayerEnemyInactive(enemyv, player1, sound);//enemy
		coll::PlayerEnemyInactive(shitv, player1, sound);//shit
		coll::PlayerEnemyInactive(b1Weaponv, player1, sound);//b1Weapon
		coll::PlayerEnemyInactive(boss2Weaponv, player1, sound);//b2Weapon
		coll::PlayerEnemyInactive(enemyFormationv, player1, sound);//enemyFormation
		coll::PlayerEnemyInactive(boss3FWeaponv, player1, sound);//boss3firstWeapon
		coll::PlayerEnemyInactive(boss3SWeaponv, player1, sound);//boss3secWeapon
		coll::PlayerHealthGet(healthv, player1, sound);//health
		coll::PlayerUnlockPew(unlockPewv, player1, sound, gotPew, pewOnCooldown);//unlockPew

		//for enemies that are not set inactive there is a damagechill.. otherwise player would instantly die
		if (damageChill > 500){
			coll::PlayerEnemyActive(cowv, player1, sound);//cow
			coll::PlayerEnemyActive(monkeyv, player1, sound);//monkey
			coll::PlayerEnemyActive(boss1v, player1, sound);//boss1
			coll::PlayerEnemyActive(boss2v, player1, sound);//boss2
			coll::PlayerEnemyActive(boss3v, player1, sound);//boss3
			damageChill = 0;
		}
	}
}

void PlayState::CountersToNull(){
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

void PlayState::UpdateHUD(sf::RenderWindow &window){
	hudHealth.Update(window, player1.getHealth());
	weapon.setWeapon(elapsedTime, points, gotPew);
	weapon.Update();
}