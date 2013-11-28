#include "RenderManager.h"

void RenderManager::EnemyDraw(std::vector<Enemy> &vector, float &elapsedTime, HighscoreManager &highscore, sf::RenderWindow &window)
{
	for (int i = 0; i < vector.size(); i++)
	{	
		if (vector[i].active)
		{
			vector[i].Update(window, elapsedTime, highscore);
			vector[i].Render(window);
		}else
			vector.erase(vector.begin() + i);
	}
}

void RenderManager::HealthDraw(std::vector<HealthDrop> &vector, float &elapsedTime, sf::RenderWindow &window)
{
	for (int i = 0; i < vector.size(); i++)
	{	
		if (vector[i].active)
		{
			vector[i].Update(window, elapsedTime);
			vector[i].Render(window);
		}else
			vector.erase(vector.begin() + i);
	}
}

void RenderManager::UnlockPewDraw(std::vector<UnlockPew> &vector, float &elapsedTime, sf::RenderWindow &window)
{
	for (int i = 0; i < vector.size(); i++)
	{	
		if (vector[i].active)
		{
			vector[i].Update(window, elapsedTime);
			vector[i].Render(window);
		}else
			vector.erase(vector.begin() + i);
	}
}

void RenderManager::SpaceMonkeyDraw(std::vector<SpaceMonkey> &vector, float &elapsedTime, sf::RenderWindow &window)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i].active)
		{
			vector[i].Update(window, elapsedTime);
			vector[i].Render(window);
		}else
			vector.erase(vector.begin() + i);
	}
}

void RenderManager::Boss1Draw(std::vector<Boss1> &vector, float &elapsedTime, sf::RenderWindow &window)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i].active)
		{
			vector[i].Update(window, elapsedTime);
			vector[i].Render(window);
		}else
			vector.erase(vector.begin() + i);
	}
}

void RenderManager::BulletDraw(std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator, Collision &collision, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end(); )
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}else
		{
			collision.BulletEnemy		   (iterator, enemyv, points, sound, highscore);
			collision.MonkeyBullet		  (iterator, monkeyv, points, sound, highscore);
			collision.BulletShit		    (iterator, shitv, points, sound, highscore);
			collision.BulletBoss1  (iterator, boss1v, points, sound, highscore, boss1Dead);
			iterator->Update(window, elapsedTime);
			iterator->Render(window);
			++iterator;
		}
	}
}

void RenderManager::DoubleShotDraw(std::vector<DoubleShot> &vector, std::vector<DoubleShot>::iterator &iterator, Collision &collision, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end(); )
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}else
		{
			collision.DoubleEnemy		   (iterator, enemyv, points, sound, highscore);
			collision.DoubleMonkey		  (iterator, monkeyv, points, sound, highscore);
			collision.DoubleShit		    (iterator, shitv, points, sound, highscore);
			collision.DoubleBoss1  (iterator, boss1v, points, sound, highscore, boss1Dead);
			iterator->Update(window, elapsedTime);
			iterator->Render(window);
			++iterator;
		}
	}
}

void RenderManager::PewShotDraw(std::vector<Pew> &vector, std::vector<Pew>::iterator &iterator, Collision &collision, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end(); )
	{
		if (!iterator->active)
		{
			iterator = vector.erase(iterator);
		}else
		{
			collision.PewEnemy  (iterator, enemyv, points, sound, highscore);
			collision.PewMonkey(iterator, monkeyv, points, sound, highscore);
			collision.PewShit	 (iterator, shitv, points, sound, highscore);
			iterator->Update(window, elapsedTime);
			iterator->Render(window);
			++iterator;
		}
	}
}

void RenderManager::ShitDraw(std::vector<ShitBullets> &vector, std::vector<ShitBullets>::iterator &iterator, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if(!iterator->active)
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

void RenderManager::Boss1WeaponDraw(std::vector<Boss1Weapon> &vector, std::vector<Boss1Weapon>::iterator &iterator, sf::RenderWindow &window, float &elapsedTime)
{
	for (iterator = vector.begin(); iterator != vector.end();)
	{
		if(!iterator->active)
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