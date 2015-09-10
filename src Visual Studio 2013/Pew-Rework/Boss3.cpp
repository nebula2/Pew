//boss3.cpp

#include "Boss3.h"

sf::Texture Boss3::enemyTex;
sf::Texture Boss3::headSpawnerTex;
sf::Texture Boss3::cowSpawnerTex;

Boss3::Boss3(){
	IOdiff   diff;
	IOsmooth smooth;
	hasTargetTexture = false;
	speed =		   0.5;
	health =	   50 * diff.ReadDiffSettings();
	startHealth =  50 * diff.ReadDiffSettings();
	damage =	   10;
	bossRotation = 0;
	currentState = 0; 
	active =        true;
	head1Active =   false;
	head2Active =   false;
	cowMActive =    false; 
	shootHeads1 =   false; //shoot heads on left side
	shootHeads2 =   false; //shoot heads on right side
	state1Dead =    false; //do not jump into state 2	
	shootCows =     false; //shoot cows or not
	moveLeft =      true;  //movement indicator
	moveDown =      false;
	moveUp =        false;
	state3Pos =     false;
	goneDead =      false; //indicator for death
	topAfterDeath = false;
	fallToGround =  false;
	startColor = sprite.getColor();

	enemyTex.loadFromFile       ("graphics/enemies/cowmashine.jpg");
	headSpawnerTex.loadFromFile("graphics/enemies/motor.png");
	cowSpawnerTex.loadFromFile  ("graphics/enemies/cowspawner.png");
	
	enemyTex.setSmooth(smooth.ReadSmoothSettings());
	headSpawnerTex.setSmooth(smooth.ReadSmoothSettings());
	cowSpawnerTex.setSmooth(smooth.ReadSmoothSettings());

	sprite.setTexture(enemyTex);
	headSprite1.setTexture(headSpawnerTex);
	headSprite2.setTexture(headSpawnerTex);
	cowSprite.setTexture(cowSpawnerTex);
	
	//set start positions for all parts
	sprite.setPosition(150, -300);
	headSprite1.setPosition(sprite.getPosition().x, sprite.getPosition().y + 150);
	headSprite2.setPosition(sprite.getPosition().x + 400, sprite.getPosition().y + 150);
	cowSprite.setPosition(sprite.getPosition().x + 100, sprite.getPosition().y + 150);

	/*
	currentState:
	0 = nothing (boss comes in, transparent)		    //dont draw other parts
	1 = heads   (boss is there and mashines drive out)  //dont draw cow spawn
	1.5 mashines active
	2 = cow (mashines dead, cow spawn thing drives out) //dont draw mashines
	2.5 active
	3 = body (cow spawn dead, body attacks by movement) //just body again
	4 = death animation
	*/
}

void Boss3::Update(sf::RenderWindow &window, float elapsedTime){
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;
	float h1y = headSprite1.getPosition().y;
	float h2y = headSprite2.getPosition().y;
	float cmy = cowSprite.getPosition().y;

	if (Boss3::active)	{

		if (health <= 0)
			goneDead = true;

		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++-MOVEMENT-+++++++++++++++++++++++++++++++++++++++++
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		/*
		from 1 to 2.5 simple left to right as seen before 
		3 = move from corner to corner in a square
		4 = move to the top from where it is, then sink to the bottom 
		*/

		//______________________________________________________________________________________
		if (currentState >= 1 && currentState <= 2.5)		{
			if (moveLeft && x > - 100)
				x -= speed * elapsedTime;
			else
				moveLeft = false;

			if (!moveLeft && x < window.getSize().x - 400)
				x += speed * elapsedTime;

			else
				moveLeft = true;
			
			sprite.setPosition(x, y);
		}

		//______________________________________________________________________________________
		if (currentState == 3){
			//move fast to the start position
			if (!state3Pos){
				if (x < window.getSize().x / 2){
					x += speed * elapsedTime * 2;
					moveLeft = false;
					state3Pos = true;
				}
				if (x >= window.getSize().x / 2){
					x -= speed * elapsedTime * 2;
					moveLeft = false;
					state3Pos = true;
				}
			}
			//RIGHT
			if (!moveLeft && !moveDown && !moveUp){
				if (x < window.getSize().x -200){
					if (health > startHealth / 2)
						x += speed * elapsedTime;
					
					else 
						x += speed * elapsedTime * 1.5;
				}

				if (x >= window.getSize().x -200){
					x = window.getSize().x -200;
					moveLeft = true;
					moveDown = true;
				}
			}

			//DOWN
			if (moveLeft && moveDown && !moveUp){
				if (y < window.getSize().y -200){
					if (health > startHealth / 2)
						y += speed * elapsedTime;

					else
						y += speed * elapsedTime * 1.5;
				}
				
				if (y >= window.getSize().y -200){
					y = window.getSize().y -200;
					moveDown = false;
				}
			}

			//LEFT
			if (moveLeft && !moveDown && !moveUp){
				if (x > 200){
					if (health > startHealth / 2)
						x -= speed * elapsedTime;
					
					else
						x -= speed * elapsedTime * 1.5;
				}
				if (x <= 200){
					x = 200;
					moveLeft = false;
					moveUp = true;
				}
			}

			//UP
			if (!moveLeft && !moveDown && moveUp){
				if (y > 200){
					if (health > startHealth / 2)
						y -= speed * elapsedTime;

					else
						y -= speed * elapsedTime * 1.5;
					
				}
				if (y <= 200){
					y = 200;
					moveUp = false;
				}
			}
			sprite.setPosition(x, y);
		}
		//______________________________________________________________________________________
		if (currentState == 4){
			//DIE Motherf***er
			if (!topAfterDeath){
				if (y > -600)
					y -= speed * elapsedTime;
				
				if (y <= -590 && y > -600){
					topAfterDeath = true;
					sprite.setRotation(0);
				}
				sprite.setPosition(x, y);
			}
			if (topAfterDeath)
				fallToGround = true;
			
			if (fallToGround){
				if (y < 700){
					y += speed * elapsedTime * 2;
					sprite.setPosition(x, y);
				}
				if (y >= 700)
					active = false;
			}
		}
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//++++++++++++++++++++++++++++++++-INITIALIZATION-++++++++++++++++++++++++++++++++++++++
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		//______________________________________________________________________________________
		//state 0
		if (currentState == 0){
			sprite.setColor(transColor);
			if (y < 0){
				y += speed * elapsedTime / 7;
				sprite.setPosition(x, y);
			}

			//care that the other parts are behind boss
			headSprite1.setPosition(x, y + 150);
			headSprite2.setPosition(x + 400, y + 150);
			cowSprite.setPosition(x + 100, y + 150);

			if (y >= 0 && y < 2){
				sprite.setColor(startColor);
				sprite.setPosition(sprite.getPosition().x, 0);
				currentState = 1; 
			}
		}

		//______________________________________________________________________________________
		//state 1
		if (currentState == 1){
			//activate heads
			if (!head1Active || !head2Active){
				head1Active = true;
				head2Active = true;
			}

			//positioning
			if (h1y < 200)
				headSprite1.setPosition(x, h1y += speed * elapsedTime / 6);
			
			else 
				headSprite1.setPosition(x, y + 200);

			if (h2y < 200)
				headSprite2.setPosition(x + 400, h2y += speed * elapsedTime / 6);
			
			else
				headSprite2.setPosition(x + 400, y + 200);

			if ((h1y >= 199 && h1y <= 201) || (h2y >= y + 199 && h2y <= y + 201))
				currentState = 1.5;
		}
		
		//______________________________________________________________________________________
		//state 1.5 (collision movement for the mashines controlled by collision)
		if (currentState == 1.5){
			shootHeads1 = true;
			shootHeads2 = true;

			headSprite1.setPosition(sprite.getPosition().x, h1y);
			headSprite2.setPosition(sprite.getPosition().x + 400, h2y);

			if (h1y <= y + 150){
				shootHeads1 = false;
				head1Active = false;
				state1Dead = true;
			}
			if (h2y <= y + 150){
				shootHeads2 = false;
				head2Active = false;
				state1Dead = true;
			}
			if (!shootHeads1 && !shootHeads2 && state1Dead){
				currentState = 2;
				cowSprite.setPosition(x + 100, y + 150);
				cowMActive = true;
			}
		}
		//______________________________________________________________________________________
		//state2
		if (currentState == 2){
			if (cmy <= y + 200){
				cowSprite.setPosition(x + 100, cmy += speed * elapsedTime / 4);
			}
			else{
				cowSprite.setPosition(x + 100, y + 200);
			}
			if (cmy >= 199 && cmy < 201){
				cowSprite.setPosition(sprite.getPosition().x + 100, cmy);
				currentState = 2.5;
				shootCows = true;
			}
		}
		//______________________________________________________________________________________
		//state 2.5
		if (currentState == 2.5){
			cowSprite.setPosition(sprite.getPosition().x + 100, cmy);

			if (cmy <= y + 150){
				shootCows = false;
				cowMActive = false;
			}
			if (!cowMActive)
				currentState = 3;
		}
		//______________________________________________________________________________________
		//state 3
		if (currentState == 3){
			//get good position to rotate
			if (y <= 175 && sprite.getOrigin().x != enemyTex.getSize().x / 2){
				y += speed * elapsedTime / 2;
			}

			//get dat thing to rotate :D
			sprite.setOrigin(enemyTex.getSize().x / 2, enemyTex.getSize().y / 2);
		
			sprite.rotate(5);

			if (health <= 0)
				currentState = 4;
		}
	}
}

void Boss3::Render(sf::RenderWindow &window)
{
	if (active){
		if (cowMActive)
			window.draw(cowSprite);
		
		if (head1Active)
			window.draw(headSprite1);
		
		if (head2Active)
			window.draw(headSprite2);

		window.draw(sprite);
	}
}

//for collision stuff
void Boss3::setBossPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Boss3::setHead1Position(float x, float y){
	headSprite1.setPosition(x, y);
}

float Boss3::getHead1XPosition(){
	return headSprite1.getPosition().x;
}

float Boss3::getHead1YPosition(){
	return headSprite1.getPosition().y;
}

void Boss3::setHead2Position(float x, float y){
	headSprite2.setPosition(x, y);
}

float Boss3::getHead2XPosition(){
	return headSprite2.getPosition().x;
}

float Boss3::getHead2YPosition(){
	return headSprite2.getPosition().y;
}

void Boss3::setCowMPosition(float x, float y){
	cowSprite.setPosition(x, y);
}

float Boss3::getCowMXPosition(){
	return cowSprite.getPosition().x;
}

float Boss3::getCowMYPosition(){
	return cowSprite.getPosition().y;
}

int Boss3::getDamage(){
	return damage;
}

int Boss3::getHealth(){
	return health;
}

void Boss3::reduceHealth(int pDamage){
	int newhealth = health - pDamage;
	health = newhealth;
}

//weaponspawning indicator
float Boss3::getCurrentState(){
	return currentState;
}

bool Boss3::getCowMActive(){
	return cowMActive;
}
bool Boss3::getHead1Active(){
	return head1Active;
}

bool Boss3::getHead2Active(){
	return head2Active;
}

bool Boss3::getShootCows(){
	return shootCows;
}

bool Boss3::getShootHeads1(){
	return shootHeads1;
}

bool Boss3::getShootHeads2(){
	return shootHeads2;
}

bool Boss3::getGoneDead(){
	return goneDead;
}