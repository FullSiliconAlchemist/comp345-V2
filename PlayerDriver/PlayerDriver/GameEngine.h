#pragma once

//#include "Player.h"
#include "Map.h"
class Player;

class GameEngine
{
	bool isTournament;
public:
	GameEngine();
	~GameEngine();

	bool getIsTournament() const;
	void setIsTournament(bool indicator);

	bool isUser(Player& somePlayer);

	void chooseGameMode();
	void displayResults(Player players[], Map* gameMap, int numOfPlayer);
};

