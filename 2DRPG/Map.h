#pragma once
#include <SFML/Graphics.hpp>
#include "GameSprite.h"
#include "FlowerSprite.h"
#include "WaterSprite.h"
#include <vector>


class Map
{
public:
	Map();
	~Map();

	bool getIsMoving() { return isMoving; }
	void setIsMoving(bool flag) { isMoving = flag; }
	bool getIsSolid(DIRECTION direction);

private:


protected:

	bool testing;
	bool upSolid;
	bool downSolid;
	bool leftSolid;
	bool rightSolid;

	bool isMoving;
	bool start;
	int xPosition;
	int yPosition;
	int yPos;
	int xPositionTracker = 0;
	int yPositionTracker = 0;
	sf::Vector2i positionTrackers[3];

	bool noThreadFinished;

	//Thread segments Variables
	int numOfThreads;
	int threadCompleteCounter;
	//Thread1
	sf::Vector2i seg1PositionTrackers;
	sf::Vector2i seg1Position;
	//Thread2
	sf::Vector2i seg2PositionTrackers;
	sf::Vector2i seg2Position;
	//Thread3
	sf::Vector2i seg3PositionTrackers;
	sf::Vector2i seg3Position;
	//Thread 4 
	sf::Vector2i seg4PositionTrackers;
	sf::Vector2i seg4Position;

	int upperXLimit = 0;
	int lowerXLimit = 0;
	int upperYLimit = 0;
	int lowerYLimit = 0;

	int renderGridValue;
	int squzreSize = 50;

	DIRECTION dir;
	int centerXLocation;
	int centerYLocation;

	sf::Texture dirtTexture;
	sf::Texture grassTexture;
	sf::Texture sandTexture;

	std::vector<WaterSprite> spriteList;

	WaterSprite waterSprite;
	WaterSprite bottomLeftWaterCornerSprite;
	WaterSprite leftWaterWallSprite;
	WaterSprite topLeftWaterCornerSprite;
	WaterSprite topWaterWallSprite;
	WaterSprite topRightWaterCornerSprite;
	WaterSprite rightWaterWallSprite;
	WaterSprite bottomRightWaterCornerSprite;
	WaterSprite BottomWaterWallSprite;
	GameSprite dirtSprite;
	GameSprite grassSprite;
	FlowerSprite flowerSprite;
	GameSprite sandSprite;
};

