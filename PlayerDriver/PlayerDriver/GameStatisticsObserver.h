#pragma once
class GameStatisticsObserver
{
public:
	~GameStatisticsObserver();
	virtual void Update() = 0;
protected:
	GameStatisticsObserver();
};

