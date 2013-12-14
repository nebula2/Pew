//IngameSfx.cpp

#include "IngameSfx.h"

//Music
void IngameMusic::LoadMusic(int &volume)
{
	gameTheme.openFromFile("audio//ingamesong.ogg");
	gameTheme.setVolume(volume);
}

void IngameMusic::PlayMusic(std::string music)
{
	if (music == "ingamesong")
	{
		gameTheme.play();
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
	pewBuffer.loadFromFile("audio//pew.ogg");
	boss1HitBuffer.loadFromFile("audio//boss1Hit.ogg");
	cowBuffer.loadFromFile("audio//cow.ogg");
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
	if (sound == "cow")
	{
		cowSound.play();
	}
}
