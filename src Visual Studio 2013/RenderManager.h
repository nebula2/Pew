//RenderManager.h

#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

//SFML and windows header
#include <vector>
//own header
#include "Entity.h"
#include "HighscoreManager.h"
#include "IngameSfx.h"
#include "Collision.h"

namespace Rm
{
	//Render for Vector, Time, Window
	template <class C>
	void StdDraw(std::vector<C> &vector, float &elapsedTime, sf::RenderWindow &window)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			if (vector[i].active)
			{
				vector[i].Update(window, elapsedTime);
				vector[i].Render(window);
			}
			else
				vector.erase(vector.begin() + i);
		}
	}

	template <class C, class CC>
	void EnemyStdWeapon(std::vector<C> &vector, CC &iterator, sf::RenderWindow &window, float &elapsedTime)
	{
		for (iterator = vector.begin(); iterator != vector.end();)
		{
			if (!iterator->active)
			{
				iterator = vector.erase(iterator);
			}
			else
			{
				iterator->Update(window, elapsedTime);
				iterator->Render(window);
				++iterator;
			}
		}
	}
}

class RenderManager
{
public:
	void Boss2WeaponDraw(std::vector<Boss2Weapon> &vector, std::vector<Boss2Weapon>::iterator &iterator, float &elapsedTime, Player &pPlayer, sf::RenderWindow &window);
	void EnemyDraw(std::vector<Enemy> &vector, float &elapsedTime, HighscoreManager &highscore, sf::RenderWindow &window);
	
	void BulletDraw(std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, sf::RenderWindow &window, float &elapsedTime);
	void DoubleShotDraw(std::vector<DoubleShot> &vector, std::vector<DoubleShot>::iterator &iterator, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, std::vector<Boss2Weapon> &boss2weaponv, sf::RenderWindow &window, float &elapsedTime);
	void PewShotDraw(std::vector<Pew> &vector, std::vector<Pew>::iterator &iterator, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, std::vector<Boss2> &boss2v, std::vector<Boss2Weapon> &boss2weaponv, sf::RenderWindow &window, float &elapsedTime);
};

#endif