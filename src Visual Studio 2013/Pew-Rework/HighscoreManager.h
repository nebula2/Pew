//HighscoreManager.h

#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H


class HighscoreManager{
public:
	HighscoreManager();

	//setter
	void setPoints(int points);
	void setEnemyMissed(int missed);
	void setEnemyKilled(int ekilled);
	void setMonkeyKilled(int mkilled);
	void setShotsFired(int sfired);
	void setShotsGot(int sgot);

	//getter

	//returns earned points
	int getPoints() const { return hPoints; };
	//returns missed enemies
	int getEnemyMissed() const { return hMissed; };
	//returns killed enemies
	int getEnemyKilled() const { return hEkilled; };
	//returns killed monkeys
	int getMonkeyKilled() const { return hMkilled; };
	//returns fired shots
	int getShotsFired() const {	return hSfired;	};
	//returns collided shots
	int getShotsGot() const { return hSgot; };

private:
	int hPoints;
	int hMissed;
	int hEkilled;
	int hMkilled;
	int hSfired;
	int hSgot;
};
#endif