//IngameSfx.h

#ifndef INGAMESFX_H
#define INGAMESFX_H

#include <SFML/Audio.hpp>
#include <string>

class IngameMusic
{
public:
	void LoadMusic(int &volume);
	void PlayMusic(std::string music);
	void getCurrentPosition();
	void Stop();
private:
	sf::Music gameTheme;
};

class IngameSound
{
public:

	void LoadSoundBuffer();
	void setBuffer(int &volume);
	void PlaySound(std::string sound);

private:

	sf::SoundBuffer bossDeathBuffer;
	sf::SoundBuffer bulletShotBuffer;
	sf::SoundBuffer enemyCollisionBuffer;
	sf::SoundBuffer healthDropBuffer;
	sf::SoundBuffer playerCollisionBuffer;
	sf::SoundBuffer playerDeathBuffer;
	sf::SoundBuffer monkeyFartBuffer;
	sf::SoundBuffer pewBuffer;
	sf::SoundBuffer boss1HitBuffer;
	sf::SoundBuffer cowBuffer;

	sf::Sound bossDeathSound;
	sf::Sound bulletShotSound;
	sf::Sound enemyCollisionSound;
	sf::Sound healthDropSound;
	sf::Sound playerCollisionSound;
	sf::Sound playerDeathSound;
	sf::Sound monkeyFartSound;
	sf::Sound pewSound;
	sf::Sound boss1HitSound;
	sf::Sound cowSound;
};

#endif