//Collision.h

#ifndef _COLLISION_H
#define _COLLISION_H

#include <vector>
#include "EntityIncludes.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"

namespace coll{
	
	template <class Object, class ObjectList>
	void ProjectileToList(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore)	{
		//collision detection for normal enemies
		for (unsigned int i = 0; i < objList.size(); i++)		{
			if (objList[i].active)			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))				{
					if (obj->isPew == false)
						obj->active = false;

					highscore.setShotsGot(1);
					points += 5;
					sound.PlaySound("enemyCollision");
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						objList[i].active = false;
						highscore.setEnemyKilled(1);
					}
				}
			}
		}
	}
	template <class Object, class ObjectList>
	void ProjectileToMonkey(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore){
		//collision detection for monkey (got a seperate to count monkey kills)
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					if (obj->isPew == false)
						obj->active = false;
					
					sound.PlaySound("enemyCollision");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						sound.PlaySound("bossDeath");
						objList[i].active = false;
						points += 20;
						highscore.setMonkeyKilled(1);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void ProjectileToListNoHealth(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore){
		//Collision detection for things with no health
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					if (obj->isPew == false)
						obj->active = false;
					
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
	void BossCollision(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager&highscore, bool &boss1Dead){
		//Boss 1 Collision detection
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					obj->active = false;
					sound.PlaySound("boss1Hit");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						sound.PlaySound("bossDeath");
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
	void Boss2Collision(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager&highscore){
		//Boss 2 Collision detection
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					obj->active = false;
					sound.PlaySound("boss1Hit");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						sound.PlaySound("bossDeath");
						objList[i].active = false;
						points += 20;
						highscore.setEnemyKilled(1);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerEnemyInactive(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound)	{
		//player collision with Enemies <- Enemies are set inactive if collision appeares
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objList.size(); i++)		{
			if (objList[i].active)
			{
				if (objList[i].sprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					objList[i].active = false;
					pPlayer.reduceHealth(objList[i].getDamage());
					sound.PlaySound("playerCollision");
					if (pPlayer.getHealth() <= 0){
						pPlayer.active = false;
						sound.PlaySound("playerDeath");
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerEnemyActive(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound){
		//player collision with Enemies which shall not be set inactive after collision
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (objList[i].sprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					pPlayer.reduceHealth(objList[i].getDamage());
					sound.PlaySound("playerCollision");
					if (pPlayer.getHealth() <= 0){
						pPlayer.active = false;
						sound.PlaySound("playerDeath");
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerHealthGet(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound){
		//HealthDrop Collision
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (objList[i].healthDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					objList[i].active = false;
					sound.PlaySound("healthDrop");
					pPlayer.increaseHealth(20);
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerUnlockPew(std::vector<ObjectList> &objectList, Object &pPlayer, IngameSound &sound, bool &gotPew, bool &pewOnCooldown){
		//Player Collision to unlock the third weapon
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (int i = 0; i < objectList.size(); i++)	{
			if (objectList[i].active){
				if (objectList[i].pewDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					objectList[i].active = false;
					sound.PlaySound("healthDrop");
					gotPew = true;
					pewOnCooldown = true;

					if (pPlayer.getHealth() <= 100)
						pPlayer.increaseHealth(100);
				}
			}
		}
	}
	template <class Object>
	void Boss3Collision(std::vector<Boss3> &boss3v, Object &obj, IngameSound &sound, HighscoreManager &highscore, int &points, bool &boss3dead){
		//boss3 collision weapon to boss3
		for (unsigned int i = 0; i < boss3v.size(); i++){
			//collision for first state
			if (boss3v[i].getCurrentState() == 1.5){
				//collision for left Spawner
				if (boss3v[i].getHead1Active()){
					if (obj->sprite.getGlobalBounds().intersects(boss3v[i].headSprite1.getGlobalBounds())){
						obj->active = false;
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						boss3v[i].setHead1Position(boss3v[i].getHead1XPosition(), boss3v[i].getHead1YPosition() - 2);
					}
				}

				//collision for right spawner
				if (boss3v[i].getHead2Active()){
					if (obj->sprite.getGlobalBounds().intersects(boss3v[i].headSprite2.getGlobalBounds()))
					{
						obj->active = false;
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						boss3v[i].setHead2Position(boss3v[i].getHead2XPosition(), boss3v[i].getHead2YPosition() -2);
					}
				}
			}
//_____________________________________________________________________________________________________________________________________
			if (boss3v[i].getCurrentState() == 2.5){
				//collision for cow spawner
				if (boss3v[i].getCowMActive()){
					if (obj->sprite.getGlobalBounds().intersects(boss3v[i].cowSprite.getGlobalBounds())){
						obj->active = false;
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						boss3v[i].setCowMPosition(boss3v[i].getCowMXPosition(), boss3v[i].getCowMYPosition() -2);
					}
				}
			}
//_____________________________________________________________________________________________________________________________________
			if (boss3v[i].getCurrentState() >= 3 && boss3v[i].getCurrentState() <= 4){
				if (boss3v[i].active){
					if (obj->sprite.getGlobalBounds().intersects(boss3v[i].sprite.getGlobalBounds())){
						obj->active = false;
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						boss3v[i].reduceHealth(obj->getDamage());
						if (boss3v[i].getGoneDead()){
							sound.PlaySound("boss3death");
							boss3dead = false;
							points += 150;
						}
					}
				}
			}
		}
	}

	//Test if Mouse pos intersects with enemy sprite to set it as target
	template <class ObjectList>
	void TargetTest(std::vector<ObjectList> &objList, sf::Vector2i pMouse){
		for (int i = 0; i < objList.size(); i++){
			if (objList[i].active){
				if (objList[i].sprite.getGlobalBounds().intersects(pMouse->getPosition()))
					objList[i]setTarget(true);
				
				else 
					objList[i].setTarget(false);
			}
		}
	}

}

#endif