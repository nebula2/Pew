//HighscoreManager.h

#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H


class HighscoreManager
{
public:
	HighscoreManager();
	void setPoints(int points);
	void setEnemyMissed(int missed);
	void setEnemyKilled(int ekilled);
	void setMonkeyKilled(int mkilled);
	void setShotsFired(int sfired);
	void setShotsGot(int sgot);

	int getPoints();
	int getEnemyMissed();
	int getEnemyKilled();
	int getMonkeyKilled();
	int getShotsFired();
	int getShotsGot();
private:
	int hPoints;
	int hMissed;
	int hEkilled;
	int hMkilled;
	int hSfired;
	int hSgot;
};
#endif