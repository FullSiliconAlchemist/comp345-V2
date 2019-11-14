#pragma once

#include <iostream>
#include "GameStatisticsObserver.h"
#include "Map.h"

// View part of the MVC model, this will update the view and display the scores, etc of the game
class MapViewer : public GameStatisticsObserver
{
public:
	MapViewer();
	MapViewer(Map* s);
	~MapViewer();

	void Update();
	void display();

private:
	Map* _Subject;
};

