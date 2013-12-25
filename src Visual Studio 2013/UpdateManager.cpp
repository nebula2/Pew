//UpdateManager.cpp

#include "UpdateManager.h"


void UpdateManager::EnemySpawn(int &counter, std::vector<Enemy> &vector, int &randomX)
{
	if (counter >= 600)
	{
		randomX = (rand() % 800) + 1;
		Enemy enemyx;
		enemyx.SetPosition(randomX, -35);
		vector.push_back(enemyx);
		counter = 0;
	}
}

void UpdateManager::HealthDropSpawn(int &counter, std::vector<HealthDrop> &vector, int &randomX)
{
	if (counter >= 20000)
	{
		randomX = (rand() % 800) + 1;
		HealthDrop healthx;
		healthx.SetPosition(randomX, -35);
		vector.push_back(healthx);
		counter = 0;
	}
}

void UpdateManager::SpaceMonkeySpawn(int &points, std::vector<SpaceMonkey> &vector, std::vector<Boss2> &bossV)
{
	if (points > 1 && points % 300 == 0 && bossV.size() == 0)
	{
		points += 10;
		SpaceMonkey monkey;
		monkey.SetPosition(364, 25);
		vector.push_back(monkey);
	}
}

void UpdateManager::ShitSpawn(int &counter, std::vector<SpaceMonkey> &smVector, std::vector<ShitBullets> &sVector, IngameSound &sound)
{
	for (int i = 0; i < smVector.size(); i++)
	{
		if (smVector[i].active && counter >= 1500)
		{
			ShitBullets shitx;
			shitx.SetPosition(smVector[i].getPosition().x, smVector[i].getPosition().y);
			sound.PlaySound("fart");
			sVector.push_back(shitx);
			counter = 0;
		}
	}
}

void UpdateManager::Boss1Spawn(int &points, std::vector<Boss1> &vector)
{
	if (points > 1 && points > 2000 && points < 2025)
	{
		points += 30;
		Boss1 Boss1x;
		vector.push_back(Boss1x);
	}
}

void UpdateManager::UnlockPewSpawn(bool &boss1Dead, std::vector<UnlockPew> &vector)
{
	if (boss1Dead)
	{
		UnlockPew unlockPewx;
		unlockPewx.SetPosition(400, 100);
		vector.push_back(unlockPewx);
		boss1Dead = false;
	}
}

void UpdateManager::Boss1WeaponSpawn(int &counter, std::vector<Boss1Weapon> &bwVector, std::vector<Boss1> &bVector, IngameSound &sound)
{
	for (int i = 0; i < bVector.size(); i++)
	{
		if (bVector[i].active && counter >= 2000)
		{
			Boss1Weapon b1Weaponx;
			b1Weaponx.SetPosition(bVector[i].getPosition().x, bVector[i].getPosition().y);
			sound.PlaySound("pew");
			bwVector.push_back(b1Weaponx);
			counter = 0;
		}
	}
}

void UpdateManager::CowSpawn(int &counter, std::vector<Cow> &vector, int &randomX, IngameSound &sound)
{
	if (counter >= 10000)
	{
		randomX = (rand() % 300) + 1;
		Cow cowx;
		cowx.setPosition(randomX, -400);
		sound.PlaySound("cow");
		vector.push_back(cowx);
		counter = 0;
	}
}

//WEAPONS

void UpdateManager::BulletSpawn(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound)
{
	if (counter >= 175 && weapon.bulletA)
	{
		Bullet bulletx;
		highscore.setShotsFired(1);
		bulletx.SetPosition(player.getPosition().x - 4, player.getPosition().y);
		vector.push_back(bulletx);
		sound.PlaySound("bulletShot");
		counter = 0;
	}
}

void UpdateManager::DoubleShotSpawn(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound)
{
	if (counter >= 300 && weapon.doubleA)
	{
		DoubleShot doublex;
		DoubleShot doubley;
		highscore.setShotsFired(2);
		doublex.SetPosition(player.getPosition().x - 12, player.getPosition().y);
		doubley.SetPosition(player.getPosition().x + 10, player.getPosition().y);
		vector.push_back(doublex);
		vector.push_back(doubley);
		sound.PlaySound("bulletShot");
		counter = 0;
	}
}

void UpdateManager::PewSpawn(std::vector<Pew> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, bool &pewOnCooldown)
{
	if (weapon.pewA && !pewOnCooldown)
	{
		Pew pewx;
		highscore.setShotsFired(1);
		pewx.SetPosition(player.getPosition().x - 4, player.getPosition().y);
		vector.push_back(pewx);
		sound.PlaySound("pew");
		pewOnCooldown = true;
	}
}

void UpdateManager::Boss2Spawn(std::vector<Boss2> &vector, int &points)
{
	if (points >= 2800 && points < 2899)
	{
		Boss2 boss2x;
		boss2x.setPosition(400, -300);
		vector.push_back(boss2x);
		points += 100;
	}
}

void UpdateManager::Boss2WeaponSpawn(int &counter, std::vector<Boss2Weapon> &bwvector, std::vector<Boss2> &bvector)
{
	for (int i = 0; i < bvector.size(); i++)
	{
		if (bvector[i].active && bvector[i].getfadeIn() == true && counter >= 2000)
		{
			Boss2Weapon b2Wx;
			b2Wx.setPosition(bvector[i].getPosition().x, bvector[i].getPosition().y);
			bwvector.push_back(b2Wx);
			counter = 0;
		}
	}
}