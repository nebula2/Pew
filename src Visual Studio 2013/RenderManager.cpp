//RenderManager.cpp

#include "RenderManager.h"


//Render for enemy Stuff 

void RenderManager::Boss2WeaponDraw(std::vector<Boss2Weapon> &vector, std::vector<Boss2Weapon>::iterator &iterator, float &elapsedTime, Player &pPlayer, sf::RenderWindow &window)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}
		else
		{
			iterator->Update(window, elapsedTime, pPlayer);
			iterator->Render(window);
			++iterator;
		}
	}
}

void RenderManager::EnemyDraw(std::vector<Enemy> &vector, float &elapsedTime, HighscoreManager &highscore, sf::RenderWindow &window)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i].active)
		{
			vector[i].Update(window, elapsedTime, highscore);
			vector[i].Render(window);
		}
		else
			vector.erase(vector.begin() + i);
	}
}


//Player Weapons

void RenderManager::BulletDraw(std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv,std::vector<EnemyFormation> &enemyFormationv, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}
		else
		{
			coll::ProjectileToList(iterator, enemyv, points, sound, highscore);//enemy
			coll::ProjectileToMonkey(iterator, monkeyv, points, sound, highscore);//monkey
			coll::ProjectileToListNoHealth(iterator, shitv, points, sound, highscore);//shit
			coll::ProjectileToListNoHealth(iterator, boss2weaponv, points, sound, highscore);//boss2Weapon
			coll::BossCollision(iterator, boss1v, points, sound, highscore, boss1Dead);//boss1
			coll::ProjectileToList(iterator, enemyFormationv, points, sound, highscore);//enemyFormation

			iterator->Update(window, elapsedTime);
			iterator->Render(window);
			++iterator;
		}
	}
}

void RenderManager::DoubleShotDraw(std::vector<DoubleShot> &vector, std::vector<DoubleShot>::iterator &iterator, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}
		else
		{
			coll::ProjectileToList(iterator, enemyv, points, sound, highscore);//enemy
			coll::ProjectileToMonkey(iterator, monkeyv, points, sound, highscore);//monkey
			coll::ProjectileToListNoHealth(iterator, shitv, points, sound, highscore);//shit
			coll::ProjectileToListNoHealth(iterator, boss2weaponv, points, sound, highscore);//boss2Weapon
			coll::BossCollision(iterator, boss1v, points, sound, highscore, boss1Dead);//boss1
			coll::ProjectileToList(iterator, enemyFormationv, points, sound, highscore);//enemyFormation

			iterator->Update(window, elapsedTime);
			iterator->Render(window);
			++iterator;
		}
	}
}

void RenderManager::PewShotDraw(std::vector<Pew> &vector, std::vector<Pew>::iterator &iterator, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, std::vector<Boss2> &boss2v, std::vector<Boss2Weapon> &boss2weaponv, std::vector<EnemyFormation> &enemyFormationv, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}
		else
		{
			coll::ProjectileToList(iterator, enemyv, points, sound, highscore);//enemy
			coll::ProjectileToMonkey(iterator, monkeyv, points, sound, highscore);//monkey
			coll::ProjectileToListNoHealth(iterator, shitv, points, sound, highscore);//shit
			coll::ProjectileToListNoHealth(iterator, boss2weaponv, points, sound, highscore);//boss2Weapon
			coll::Boss2Collision(iterator, boss2v, points, sound, highscore);//boss2
			coll::ProjectileToList(iterator, enemyFormationv, points, sound, highscore);//enemyFormation
			
			iterator->Update(window, elapsedTime);
			iterator->Render(window);
			++iterator;
		}
	}
}