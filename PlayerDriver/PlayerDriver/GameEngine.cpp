#include "GameEngine.h"
#include "Player.h"
#include "Map.h"
#include <string>

GameEngine::GameEngine()
{
	this->isTournament = false;
}

GameEngine::~GameEngine()
{
}

bool GameEngine::getIsTournament() const
{
	return this->isTournament;
}

void GameEngine::setIsTournament(bool indicator)
{
	this->isTournament = indicator;
}

bool GameEngine::isUser(Player& somePlayer)
{
	std::string playerType;
	playerType = typeid(*somePlayer.getPlayerType()).name();

	if (playerType.at(12) != 'U')
		return false;
	else
		return true;
}

void GameEngine::chooseGameMode()
{
}

void GameEngine::displayResults(Player players[], Map* gameMap, int numOfPlayers ){
	int* scores = new int[numOfPlayers];

	cout << "\nPlayer \tCards \tVictory Points \tCoins" <<endl;

	for (int i = 0; i < numOfPlayers; i++) {
		cout << endl;
		scores[i] = players[i].computeScore();
		scores[i] += gameMap->computePlayerScores(players[i].GetId());

		cout <<i << "\t"<<players[i].GetNumOfCards()<< "\t"<<scores[i]<< "\t"<< players[i].GetGoldenCoins() << endl;

	}
}
