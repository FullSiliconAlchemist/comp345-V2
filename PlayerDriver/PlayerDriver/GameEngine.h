#pragma once

#include "Player.h"

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
	void displayResults();
};

