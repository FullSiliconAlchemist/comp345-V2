#include "GameEngine.h"
#include "Player.h"
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

void GameEngine::displayResults()
{
}
