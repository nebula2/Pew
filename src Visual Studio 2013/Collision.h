//Collision.h

#ifndef _COLLISION_H
#define _COLLISION_H

//SFML and windows header
#include <vector>
//own header
#include "Entity.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"

//namespace-try for collision detection

namespace coll
{
	
	template <class Object, class ObjectList>
	void ProjectileToList(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore)
	{
		//collision detection for normal enemies
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))
				{
					if (obj->isPew == false)
					{
						obj->active = false;
					}
					highscore.setShotsGot(1);
					points += 5;
					sound.PlaySound("enemyCollision");
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0)
					{
						objList[i].active = false;
						highscore.setEnemyKilled(1);
					}
				}
			}
		}
	}
	template <class Object, class ObjectList>
	void ProjectileToMonkey(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore)
	{
		//collision detection for monkey (got a seperate to count monkey kills)
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))
				{
					if (obj->isPew == false)
					{
						obj->active = false;
					}
					sound.PlaySound("enemyCollision");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0)
					{
						sound.PlaySound("audio//bossDeath.ogg");
						objList[i].active = false;
						points += 20;
						highscore.setMonkeyKilled(1);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void ProjectileToListNoHealth(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore)
	{
		//Collision detection for things with no health
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))
				{
					if (obj->isPew == false)
					{
						obj->active = false;
					}
					objList[i].active = false;
					points += 5;
					sound.PlaySound("enemyCollision");
					highscore.setEnemyKilled(1);
					highscore.setShotsGot(1);
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void BossCollision(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager&highscore, bool &boss1Dead)
	{
		//Boss 1 Collision detection
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))
				{
					obj->active = false;
					sound.PlaySound("boss1Hit");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0)
					{
						sound.PlaySound("audio//bossDeath.ogg");
						objList[i].active = false;
						points += 20;
						highscore.setEnemyKilled(1);
						boss1Dead = true;
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void Boss2Collision(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager&highscore)
	{
		//Boss 2 Collision detection
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))
				{
					obj->active = false;
					sound.PlaySound("boss1Hit");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0)
					{
						sound.PlaySound("audio//bossDeath.ogg");
						objList[i].active = false;
						points += 20;
						highscore.setEnemyKilled(1);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerEnemyInactive(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound)
	{
		//player collision with Enemies <- Enemies are set inactive if collision appeares
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (objList[i].sprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
				{
					objList[i].active = false;
					pPlayer.reduceHealth(objList[i].getDamage());
					sound.PlaySound("playerCollision");
					if (pPlayer.getHealth() <= 0)
					{
						pPlayer.active = false;
						sound.PlaySound("playerDeath");
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerEnemyActive(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound)
	{
		//player collision with Enemies which shall not be set inactive after collision
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (objList[i].sprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
				{
					pPlayer.reduceHealth(objList[i].getDamage());
					sound.PlaySound("playerCollision");
					if (pPlayer.getHealth() <= 0)
					{
						pPlayer.active = false;
						sound.PlaySound("playerDeath");
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerHealthGet(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound)
	{
		//HealthDrop Collision
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objList.size(); i++)
		{
			if (objList[i].active)
			{
				if (objList[i].healthDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
				{
					objList[i].active = false;
					sound.PlaySound("healthDrop");
					if (pPlayer.getHealth() <= 100)
					{
						pPlayer.increaseHealth(20);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerUnlockPew(std::vector<ObjectList> &objectList, Object &pPlayer, IngameSound &sound, bool &gotPew, bool &pewOnCooldown)
	{
		//Player Collision to unlock the third weapon
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objectList.size(); i++)
		{
			if (objectList[i].active)
			{
				if (objectList[i].pewDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds()))
				{
					objectList[i].active = false;
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
}

#endif