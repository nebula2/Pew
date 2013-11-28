#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

//SFML and windows header
#include <vector>
//own header
#include "Entity.h"
#include "HighscoreManager.h"
#include "IngameSound.h"
#include "Collision.h"

class RenderManager
{
public:
	void EnemyDraw(std::vector<Enemy> &vector, float &elapsedTime, HighscoreManager &highscore, sf::RenderWindow &window);
	void HealthDraw(std::vector<HealthDrop> &vector, float &elapsedTime, sf::RenderWindow &window);
	void UnlockPewDraw(std::vector<UnlockPew> &vector, float &elapsedTime, sf::RenderWindow &window);
	void SpaceMonkeyDraw(std::vector<SpaceMonkey> &vector, float &elapsedTime, sf::RenderWindow &window);
	void Boss1Draw(std::vector<Boss1> &vector, float &elapsedTime, sf::RenderWindow &window);
	void BulletDraw(std::vector<Bullet> &vector, std::vector<Bullet>::iterator &iterator, Collision &collision, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, sf::RenderWindow &window, float &elapsedTime);
	void DoubleShotDraw(std::vector<DoubleShot> &vector, std::vector<DoubleShot>::iterator &iterator, Collision &collision, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, bool &boss1Dead, sf::RenderWindow &window, float &elapsedTime);
	void PewShotDraw(std::vector<Pew> &vector, std::vector<Pew>::iterator &iterator, Collision &collision, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<SpaceMonkey> &monkeyv, std::vector<ShitBullets> &shitv, std::vector<Boss1> &boss1v, sf::RenderWindow &window, float &elapsedTime);
	void ShitDraw(std::vector<ShitBullets> &vector, std::vector<ShitBullets>::iterator &iterator, sf::RenderWindow &window, float &elapsedTime);
	void Boss1WeaponDraw(std::vector<Boss1Weapon> &vector, std::vector<Boss1Weapon>::iterator &iterator, sf::RenderWindow &window, float &elapsedTime);
};

#endif