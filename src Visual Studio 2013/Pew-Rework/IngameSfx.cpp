//IngameSfx.cpp

#include "IngameSfx.h"

//Sound
void IngameSound::LoadSoundBuffer()
{

	bossDeathBuffer.loadFromFile("audio//bossDeath.ogg");
	bulletShotBuffer.loadFromFile("audio//bulletShot.ogg");
	enemyCollisionBuffer.loadFromFile("audio//enemyCollision.ogg");
	healthDropBuffer.loadFromFile("audio//healthDrop.ogg");
	playerCollisionBuffer.loadFromFile("audio//playerCollision.ogg");
	playerDeathBuffer.loadFromFile("audio//playerDeath.ogg");
	monkeyFartBuffer.loadFromFile("audio//fart.ogg");
	pewBuffer.loadFromFile("audio//pew.wav");
	boss1HitBuffer.loadFromFile("audio//boss1hit.ogg");
	cowBuffer.loadFromFile("audio//cow.wav");
	boss3spawn.loadFromFile("audio//boss3spawn.ogg");
	boss3death.loadFromFile("audio//boss3death.wav");
}

void IngameSound::setBuffer(int &volume)
{
	bossDeathSound.setBuffer(bossDeathBuffer);
		bossDeathSound.setVolume(volume);
	bulletShotSound.setBuffer(bulletShotBuffer);
		bulletShotSound.setVolume(volume);
	enemyCollisionSound.setBuffer(enemyCollisionBuffer);
		enemyCollisionSound.setVolume(volume);
	healthDropSound.setBuffer(healthDropBuffer);
		healthDropSound.setVolume(volume);
	playerCollisionSound.setBuffer(playerCollisionBuffer);
		playerCollisionSound.setVolume(volume);
	playerDeathSound.setBuffer(playerDeathBuffer);
		playerDeathSound.setVolume(volume);
	monkeyFartSound.setBuffer(monkeyFartBuffer);
		monkeyFartSound.setVolume(volume);
	pewSound.setBuffer(pewBuffer);
		pewSound.setVolume(volume);
	boss1HitSound.setBuffer(boss1HitBuffer);
		boss1HitSound.setVolume(volume);
	cowSound.setBuffer(cowBuffer);
		cowSound.setVolume(volume);
	boss3spawnSound.setBuffer(boss3spawn);
		boss3spawnSound.setVolume(volume);
	boss3deathSound.setBuffer(boss3death);
		boss3deathSound.setVolume(volume);
}

void IngameSound::PlaySound(std::string sound)
{
	if (sound == "bulletShot")
	{
		bulletShotSound.play();
	}
	else if (sound == "fart")
	{
		monkeyFartSound.play();
	}
	else if (sound == "enemyCollision")
	{
		enemyCollisionSound.play();
	}
	else if (sound == "playerCollision")
	{
		playerCollisionSound.play();
	}
	else if (sound == "bossDeath")
	{
		bossDeathSound.play();
	}
	else if (sound == "healthDrop")
	{
		healthDropSound.play();
	}
	else if (sound == "playerDeath")
	{
		playerDeathSound.play();
	}
	else if (sound == "pew")
	{
		pewSound.play();
	}
	else if (sound == "boss1Hit")
	{
		boss1HitSound.play();
	}
	else if (sound == "cow")
	{
		cowSound.play();
	}
	else if (sound == "boss3spawn")
	{
		boss3spawnSound.play();
	}
	else
	{
		boss3deathSound.play();
	}
}
