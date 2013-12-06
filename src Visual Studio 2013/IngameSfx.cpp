//IngameSfx.cpp

#include "IngameSfx.h"

void IngameMusic::LoadMusic()
{
	gameTheme.openFromFile("audio//ingamesong.ogg");

}

void IngameMusic::PlayMusic(std::string music)
{
	if (music == "ingamesong")
	{
		gameTheme.play();
		gameTheme.setVolume(40);
		gameTheme.setLoop(true);
	}
}

void IngameMusic::getCurrentPosition()
{
	gameTheme.getPlayingOffset();
}
void IngameMusic::Stop()
{
	gameTheme.stop();
}

void IngameSound::LoadSoundBuffer()
{

	bossDeathBuffer.loadFromFile("audio//bossDeath.ogg");
	bulletShotBuffer.loadFromFile("audio//bulletShot.ogg");
	enemyCollisionBuffer.loadFromFile("audio//enemyCollision.ogg");
	healthDropBuffer.loadFromFile("audio//healthDrop.ogg");
	playerCollisionBuffer.loadFromFile("audio//playerCollision.ogg");
	playerDeathBuffer.loadFromFile("audio//playerDeath.ogg");
	monkeyFartBuffer.loadFromFile("audio//fart.ogg");
	pewBuffer.loadFromFile("audio//pew.ogg");
	boss1HitBuffer.loadFromFile("audio//boss1Hit.ogg");
}
void IngameSound::SetBuffer()
{
	bossDeathSound.setBuffer(bossDeathBuffer);
	bulletShotSound.setBuffer(bulletShotBuffer);
	enemyCollisionSound.setBuffer(enemyCollisionBuffer);
	healthDropSound.setBuffer(healthDropBuffer);
	playerCollisionSound.setBuffer(playerCollisionBuffer);
	playerDeathSound.setBuffer(playerDeathBuffer);
	monkeyFartSound.setBuffer(monkeyFartBuffer);
	pewSound.setBuffer(pewBuffer);
	boss1HitSound.setBuffer(boss1HitBuffer);
}

void IngameSound::PlaySound(std::string sound)
{
	if (sound == "bulletShot")
	{
		bulletShotSound.play();
	}
	if (sound == "fart")
	{
		monkeyFartSound.play();
	}
	if (sound == "enemyCollision")
	{
		enemyCollisionSound.play();
	}
	if (sound == "playerCollision")
	{
		playerCollisionSound.play();
	}
	if (sound == "bossDeath")
	{
		bossDeathSound.play();
	}
	if (sound == "healthDrop")
	{
		healthDropSound.play();
	}
	if (sound == "playerDeath")
	{
		playerDeathSound.play();
	}
	if (sound == "pew")
	{
		pewSound.play();
	}
	if (sound == "boss1Hit")
	{
		boss1HitSound.play();
	}
}
