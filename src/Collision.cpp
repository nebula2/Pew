#include "collision.h"


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++-Collision with bullets-++++++++++++++++++++++++++++++++++++										
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Collision::BulletEnemy(std::vector<Bullet>::iterator &Obj , std::vector<Enemy> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
		{
			if (Obj->bulletSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				Obj->active = false;
				highscore.setShotsGot(1);
				points += 5;
				sound.PlaySound("enemyCollision");
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					ObjList[i].active = false;
					highscore.setEnemyKilled(1);
				}
			}
		}
	}
}

void Collision::BulletShit(std::vector<Bullet>::iterator &Obj , std::vector<ShitBullets> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->bulletSprite.getGlobalBounds().intersects(ObjList[i].shitSprite.getGlobalBounds())) 
			{
				ObjList[i].active = false;
				Obj->active = false;
				points += 5;
				sound.PlaySound("enemyCollision");
				highscore.setEnemyKilled(1);
				highscore.setShotsGot(1);
			}
		}
	}
}

void Collision::MonkeyBullet(std::vector<Bullet>::iterator &Obj, std::vector<SpaceMonkey> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->bulletSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				Obj->active = false;
				sound.PlaySound("enemyCollision");
				highscore.setShotsGot(1);
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					sound.PlaySound("audio//bossDeath.ogg");
					ObjList[i].active = false;
					points += 20;
					highscore.setEnemyKilled(1);
				}
			}
		}
	}
}

void Collision::BulletBoss1(std::vector<Bullet>::iterator &Obj, std::vector<Boss1> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore, bool &boss1Dead)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->bulletSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				Obj->active = false;
				sound.PlaySound("boss1Hit");
				highscore.setShotsGot(1);
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					sound.PlaySound("audio//bossDeath.ogg");
					ObjList[i].active = false;
					points += 20;
					highscore.setEnemyKilled(1);
					boss1Dead = true;
				}
			}
		}
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++-Collision with doubleShot-++++++++++++++++++++++++++++++++++++										
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Collision::DoubleEnemy(std::vector<DoubleShot>::iterator &Obj , std::vector<Enemy> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->doubleSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				Obj->active = false;
				points += 5;
				highscore.setShotsGot(1);
				sound.PlaySound("enemyCollision");
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					ObjList[i].active = false;
					highscore.setEnemyKilled(1);
				}
			}
		}
	}
}
void Collision::DoubleShit(std::vector<DoubleShot>::iterator &Obj , std::vector<ShitBullets> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{

	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->doubleSprite.getGlobalBounds().intersects(ObjList[i].shitSprite.getGlobalBounds())) 
			{
				ObjList[i].active = false;
				Obj->active = false;
				points += 5;
				sound.PlaySound("enemyCollision");
				highscore.setEnemyKilled(1);
				highscore.setShotsGot(1);
			}
		}
	}
}

void Collision::DoubleMonkey(std::vector<DoubleShot>::iterator &Obj, std::vector<SpaceMonkey> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->doubleSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				Obj->active = false;
				sound.PlaySound("enemyCollision");
				highscore.setShotsGot(1);
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					sound.PlaySound("audio//bossDeath.ogg");
					ObjList[i].active = false;
					points += 20;
					highscore.setEnemyKilled(1);
				}
			}
		}
	}
}

void Collision::DoubleBoss1(std::vector<DoubleShot>::iterator &Obj, std::vector<Boss1> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore, bool &boss1Dead)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->doubleSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				Obj->active = false;
				sound.PlaySound("boss1Hit");
				highscore.setShotsGot(1);
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					sound.PlaySound("audio//bossDeath.ogg");
					ObjList[i].active = false;
					points += 20;
					highscore.setEnemyKilled(1);
					boss1Dead = true;
				}
			}
		}
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++-Collision with Pew-+++++++++++++++++++++++++++++++++++++++										
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Collision::PewEnemy(std::vector<Pew>::iterator &Obj , std::vector<Enemy> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
		{
			if (Obj->pewShotSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				highscore.setShotsGot(1);
				points += 5;
				sound.PlaySound("enemyCollision");
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					ObjList[i].active = false;
					highscore.setEnemyKilled(1);
				}
			}
		}
	}
}

void Collision::PewShit(std::vector<Pew>::iterator &Obj , std::vector<ShitBullets> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->pewShotSprite.getGlobalBounds().intersects(ObjList[i].shitSprite.getGlobalBounds())) 
			{
				ObjList[i].active = false;
				points += 5;
				sound.PlaySound("enemyCollision");
				highscore.setEnemyKilled(1);
				highscore.setShotsGot(1);
			}
		}
	}
}

void Collision::PewMonkey(std::vector<Pew>::iterator &Obj, std::vector<SpaceMonkey> &ObjList, int &points, IngameSound &sound, HighscoreManager &highscore)
{
	for (int i = 0; i < ObjList.size(); i++)
	{
		if (ObjList[i].active)
			{
			if (Obj->pewShotSprite.getGlobalBounds().intersects(ObjList[i].enemySprite.getGlobalBounds())) 
			{
				sound.PlaySound("enemyCollision");
				highscore.setShotsGot(1);
				ObjList[i].reduceHealth(Obj->getDamage());
				if (ObjList[i].getHealth() <= 0)
				{
					sound.PlaySound("audio//bossDeath.ogg");
					ObjList[i].active = false;
					points += 20;
					highscore.setEnemyKilled(1);
				}
			}
		}
	}
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++-Collision with the Player-++++++++++++++++++++++++++++++++++++										
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Collision::EnemyPlayer(std::vector<Enemy> &ObjList, Player &pPlayer, IngameSound &sound)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].enemySprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				ObjList[i].active = false;
				pPlayer.reduceHealth(ObjList[i].getDamage());
				sound.PlaySound("playerCollision");
				if(pPlayer.getHealth() <= 0)
				{
					pPlayer.active = false;
					sound.PlaySound("playerDeath");
				}
			}
		}
	}
}



void Collision::MonkeyPlayer(std::vector<SpaceMonkey> &ObjList, Player &pPlayer, IngameSound &sound)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].enemySprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				pPlayer.reduceHealth(ObjList[i].getDamage());
				sound.PlaySound("playerCollision");
				if(pPlayer.getHealth() <= 0)
				{
					pPlayer.active = false;
					sound.PlaySound("playerDeath");
				}
			}
		}
	}
}

void Collision::ShitPlayer(std::vector<ShitBullets> &ObjList, Player &pPlayer, IngameSound &sound)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].shitSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				ObjList[i].active = false;
				pPlayer.reduceHealth(ObjList[i].getDamage());
				sound.PlaySound("playerCollision");
				if(pPlayer.getHealth() <= 0)
				{
					pPlayer.active = false;
					sound.PlaySound("playerDeath");
				}
			}
		}
	}
}

void Collision::Boss1Player(std::vector<Boss1> &ObjList, Player &pPlayer, IngameSound &sound)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].enemySprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				pPlayer.reduceHealth(ObjList[i].getDamage());
				sound.PlaySound("playerCollision");
				if(pPlayer.getHealth() <= 0)
				{
					pPlayer.active = false;
					sound.PlaySound("playerDeath");
				}
			}
		}
	}
}

void Collision::PlayerHealth(std::vector<HealthDrop> &ObjList, Player &pPlayer, IngameSound &sound)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].healthDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				ObjList[i].active = false;
				sound.PlaySound("healthDrop");
				if (pPlayer.getHealth() <= 100)
				{
					pPlayer.increaseHealth(20);
				}
			}
		}
	}
}

void Collision::Boss1WeaponPlayer(std::vector<Boss1Weapon> &ObjList, Player &pPlayer, IngameSound &sound)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].weaponSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				ObjList[i].active = false;
				pPlayer.reduceHealth(ObjList[i].getDamage());
				sound.PlaySound("playerCollision");
				if(pPlayer.getHealth() <= 0)
				{
					pPlayer.active = false;
					sound.PlaySound("playerDeath");
				}
			}
		}
	}
}

void Collision::UnlockPewPlayer(std::vector<UnlockPew> &ObjList, Player &pPlayer, IngameSound &sound, bool &gotPew, bool &pewOnCooldown)
{
	sf::Sprite pSprite = pPlayer.playerSprite;
	for (int i = 0; i < ObjList.size(); i++)
	{
		if(ObjList[i].active)
		{
			if(ObjList[i].pewDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
			{
				ObjList[i].active = false;
				sound.PlaySound("healthDrop");
				gotPew = true;
				pewOnCooldown = true;

				if (pPlayer.getHealth() <= 100)
				{
					pPlayer.increaseHealth(100);
				}
			}
		}
	}
}