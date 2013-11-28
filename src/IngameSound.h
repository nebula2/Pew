#ifndef INGAMESOUND_H
#define INGAMESOUND_H

//sfml and windows header
#include <SFML\Audio.hpp>
#include <string>

class IngameSound
{
public:
	
	void LoadSoundBuffer();
	void SetBuffer();
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
	
	sf::Sound bossDeathSound;
	sf::Sound bulletShotSound;
	sf::Sound enemyCollisionSound;
	sf::Sound healthDropSound;
	sf::Sound playerCollisionSound;
	sf::Sound playerDeathSound;
	sf::Sound monkeyFartSound;
	sf::Sound pewSound;
	sf::Sound boss1HitSound;
};

#endif