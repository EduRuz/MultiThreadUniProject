#include "Beach.h"



Beach::Beach()
{
}



Beach::~Beach()
{
}

/**
	Initializes the varables needed for the Beach Map.
	@param pointer to the Window so the class can draw to it.
*/
void Beach::initialize(sf::RenderWindow* wind)
{
	window = wind;

	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			grid[j][i].icon = map[j][i];

			switch (map[j][i]) {
			case(00) : {
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &waterSprite;
				break;
			}
			case(11) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &bottomLeftWaterCornerSprite;
				break;
			case(12) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &leftWaterWallSprite;
				break;
			case(13) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &topLeftWaterCornerSprite;
				break;
			case(14) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &topWaterWallSprite;
				break;
			case(15) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &topRightWaterCornerSprite;
				break;
			case(16) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &rightWaterWallSprite;
				break;
			case(17) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &bottomRightWaterCornerSprite;
				break;
			case(18) :
				grid[j][i].solid = true;
				grid[j][i].center = false;
				grid[j][i].sprite = &BottomWaterWallSprite;
				break;
			case(10) :
				grid[j][i].solid = false;
				grid[j][i].center = false;
				grid[j][i].sprite = &grassSprite;
				break;
			case(21) :
				grid[j][i].solid = false;
				grid[j][i].center = false;
				grid[j][i].sprite = &flowerSprite;
				break;
			}
		}
	}

	start = false;
	isMoving = false;
	grid[13][13].center = true;
	centerXLocation = 13;
	centerYLocation = 13;
	renderGridValue = 7;

	seg1PositionTrackers.x = 0;
	seg1PositionTrackers.y = 0;
	seg1Position.x = 0;
	seg1Position.y = 0;

	seg2PositionTrackers.x = 0;
	seg2PositionTrackers.y = 0;
	seg2Position.x = 0;
	seg2Position.y = 0;

	seg3PositionTrackers.x = 0;
	seg3PositionTrackers.y = 0;
	seg3Position.y = 0;
	seg3Position.x = 0;

	waterSprite.initialize(00);
	bottomLeftWaterCornerSprite.initialize(11);
	leftWaterWallSprite.initialize(12);
	topLeftWaterCornerSprite.initialize(13);
	topWaterWallSprite.initialize(14);
	topRightWaterCornerSprite.initialize(15);
	rightWaterWallSprite.initialize(16);
	bottomRightWaterCornerSprite.initialize(17);
	BottomWaterWallSprite.initialize(18);
	flowerSprite.initialize();

	grassTexture.loadFromFile("Gfx/Grass.png");
	grassSprite.setTexture(&grassTexture);
	grassSprite.setSize(sf::Vector2f(50, 50));

	testing = false;
	numOfThreads = 0;
}

/**
	Input control for the beach.
	@param The direction the player is attempting to move.
*/
void Beach::inputControl(DIRECTION direction)
{

	switch (direction) {
	case LEFT:
		if (grid[centerXLocation - 1][centerYLocation].solid != true) {
			if (isMoving == false) {
				dir = LEFT;
				start = true;
				isMoving = true;
			}
		}
		break;
	case RIGHT:
		if (grid[centerXLocation + 1][centerYLocation].solid != true) {
			if (isMoving == false) {
				dir = RIGHT;
				start = true;
				isMoving = true;
			}
		}
		break;
	case UP:
		if (grid[centerXLocation][centerYLocation - 1].solid != true) {
			if (isMoving == false) {
				dir = UP;
				start = true;
				isMoving = true;
			}
		}
		break;
	case DOWN:
		if (grid[centerXLocation][centerYLocation + 1].solid != true) {
			if (isMoving == false) {
				dir = DOWN;
				start = true;
				isMoving = true;
			}
		}
		break;

	
	}
	
}

/**
	Updates the variables needed for the beach map.
	@param daltaTime for Animation.
*/
void Beach::update(float deltaTime)
{
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			if (grid[j][i].center == true) {

				upperXLimit = j + renderGridValue;
				lowerXLimit = j - renderGridValue;
				upperYLimit = i + renderGridValue;
				lowerYLimit = i - renderGridValue;

				centerXLocation = j;
				centerYLocation = i;
				
				
			}
		}
	}
	if (!testing) {
		animations(deltaTime);
	}
	
	leftSolid = grid[centerXLocation - 1][centerYLocation].solid;
	rightSolid = grid[centerXLocation + 1][centerYLocation].solid;
	upSolid = grid[centerXLocation][centerYLocation - 1].solid;
	downSolid = grid[centerXLocation][centerYLocation + 1].solid;
}

/**
	Controls the rendering of the beach map to screen.
	@param deltatIme for Animation Thread.
*/
void Beach::render(float deltaTime)
{
	int tempLowerY1 = lowerYLimit - 1;
	int tempUpperY1 = upperYLimit + 1;

	
	if (testing) {
		if (isMoving == false) {
			
			window->setActive(false);

			std::thread threadAnimate([&](Beach* beach) {beach->animations(deltaTime);}, this);
			std::unique_lock<std::mutex> lk(CVM);
			cv.wait(lk, [&] {return ready;});
			threadAnimate.join();

		//	clock.restart();
			switch (numOfThreads) {
			case 1: {

				std::thread thread1([&](Beach* beach) {beach->threadBeach(lowerYLimit, upperYLimit - 8, 0);}, this);
				threadBeach(lowerYLimit + 7, upperYLimit, 350);
				thread1.join();
				break;
			}
			case 2: {
				std::thread thread1([&](Beach* beach) {beach->threadBeach(lowerYLimit, upperYLimit - 10, 0);}, this);
				std::thread thread2([&](Beach* beach) {beach->threadBeach(lowerYLimit + 5, upperYLimit - 5, 250);}, this);
				threadBeach(lowerYLimit + 10, upperYLimit, 500);
				thread1.join();
				thread2.join();
					break;
			}
			case 3:
			{
				std::thread thread1([&](Beach* beach) {beach->threadBeach(lowerYLimit, upperYLimit - 12, 0);}, this);
				std::thread thread2([&](Beach* beach) {beach->threadBeach(lowerYLimit + 3, upperYLimit - 8, 150);}, this);
				std::thread thread3([&](Beach* beach) {beach->threadBeach(lowerYLimit + 7, upperYLimit - 4, 350);}, this);
				threadBeach(lowerYLimit + 11, upperYLimit, 550);
 				thread1.join();
				thread2.join();
				thread3.join();
				break;
			}
			}
	
			window->setActive(true);
		}
		else {
			window->setActive(false);
			std::thread threadAnimate([&](Beach* beach) {beach->animations(deltaTime);}, this);
			std::unique_lock<std::mutex> lk(CVM);
			cv.wait(lk, [&] {return ready;});
			threadAnimate.join();

			switch (numOfThreads) {
			case 1: {
				threadCompleteCounter = 2;
				std::thread thread1([&](Beach* beach) {beach->threadMovingBeach(tempLowerY1, tempUpperY1 - 9, -50, 350, &seg1Position, &seg1PositionTrackers, 1);}, this);
				threadMovingBeach(tempLowerY1 + 8, tempUpperY1, 350, 800, &seg2Position, &seg2PositionTrackers, 2);
				thread1.join();
				break;
			}
			case 2: {
				threadCompleteCounter = 1;
				std::thread thread1([&](Beach* beach) {beach->threadMovingBeach(tempLowerY1, tempUpperY1 - 11, -50, 250, &seg1Position, &seg1PositionTrackers, 1);}, this);
				std::thread thread2([&](Beach* beach) {beach->threadMovingBeach(tempLowerY1 + 6, tempUpperY1 - 6, 250, 500, &seg2Position, &seg2PositionTrackers, 2);}, this);
				threadMovingBeach(tempLowerY1 + 11, tempUpperY1, 500, 800, &seg3Position, &seg3PositionTrackers, 3);
				thread1.join();
				thread2.join();
				break;
			}
			case 3:
			{
				std::thread thread1([&](Beach* beach) {beach->threadMovingBeach(tempLowerY1, tempUpperY1 - 13, -50, 150, &seg1Position, &seg1PositionTrackers, 1);}, this);
				std::thread thread2([&](Beach* beach) {beach->threadMovingBeach(tempLowerY1 + 4, tempUpperY1 - 9, 150, 350, &seg2Position, &seg2PositionTrackers, 2);}, this);
				std::thread thread3([&](Beach* beach) {beach->threadMovingBeach(tempLowerY1 + 8, tempUpperY1 - 5, 350, 550, &seg3Position, &seg3PositionTrackers, 3);}, this);
				threadMovingBeach(tempLowerY1 + 12, tempUpperY1, 550, 800, &seg4Position, &seg4PositionTrackers, 4);
				thread1.join();
				thread2.join();
				thread3.join();
				break;
			}
			}
			window->setActive(true);
			movingThreadCheck();
			
		}
	}
	else {
		if (isMoving == false) {
			threadBeach(lowerYLimit, upperYLimit, 0);
		}
		else {

			threadMovingBeach(tempLowerY1, tempUpperY1, -50, 800, &seg1Position, &seg1PositionTrackers, 0);
			movingThreadCheck();

		}
	}

	

	threadRenderBeach();
}

/**
	Renders the viewable part of the map to screen when the player is not moving.
	@param The lower limit to start searching through the 2d grid at for the Y Axis.
	@param The upper limit to start searching through the 2d grid at for the Y Axis.
	@param The Y Position for the algorithim to start drawing.
*/
void Beach::renderBeach(int lower, int upper, int yPos)
{
	xPosition = 0;
	yPosition = yPos;
	

	for (int i = lower; i <= upper; i++) {
		xPosition = 0;
		for (int j = lowerXLimit; j <= upperXLimit; j++) {

			switch (grid[i][j].icon) {
			case(00) :
				//spriteIterator->setPosition(xPosition, yPosition);
				waterSprite.setPosition(xPosition, yPosition);
				window->draw(waterSprite);
				//window->draw(*spriteIterator);
				//spriteIterator++;
				break;
			case(11) :
				bottomLeftWaterCornerSprite.setPosition(xPosition, yPosition);
				window->draw(bottomLeftWaterCornerSprite);
				break;
			case(12) :
				leftWaterWallSprite.setPosition(xPosition, yPosition);
				window->draw(leftWaterWallSprite);
				break;
			case(13) :
				topLeftWaterCornerSprite.setPosition(xPosition, yPosition);
				window->draw(topLeftWaterCornerSprite);
				break;
			case(14) :
				topWaterWallSprite.setPosition(xPosition, yPosition);
				window->draw(topWaterWallSprite);
				break;
			case(15) :
				topRightWaterCornerSprite.setPosition(xPosition, yPosition);
				window->draw(topRightWaterCornerSprite);
				break;
			case(16) :
				rightWaterWallSprite.setPosition(xPosition, yPosition);
				window->draw(rightWaterWallSprite);
				break;
			case(17) :
				bottomRightWaterCornerSprite.setPosition(xPosition, yPosition);
				window->draw(bottomRightWaterCornerSprite);
				break;
			case(18) :
				BottomWaterWallSprite.setPosition(xPosition, yPosition);
				window->draw(BottomWaterWallSprite);
				break;
			case(10) :
				grassSprite.setPosition(xPosition, yPosition);
				window->draw(grassSprite);
				break;
			case(21) :
				flowerSprite.setPosition(xPosition, yPosition);
				window->draw(flowerSprite);	
				break;
			}
			xPosition += 50;
		}
		yPosition += 50;
	}
}

/**
	Renders the viewable part of the map to screen when the player is moving and moves the map to give the impression the player is moving.
	@param The lower limit to start searching through the 2d grid at for the Y Axis.
	@param The upper limit to start searching through the 2d grid at for the Y Axis.
	@param The Y Position for the algorithim to start drawing.
	@param The X Position for the algorithim to start drawing.
	@param int for what thread is being run.
*/
void Beach::renderMovingBeachOrig(int lower, int upper, int yPos, int xPos, int threadNum)
{
	

		if (start) {
			xPosition = -50;
			yPosition = yPos;
			xPositionTracker = 0;
			yPositionTracker = 0;
			start = false;
		}
		int segmentSize = ((upper + 1) - (lower - 1)) * squzreSize;

		yPosition = yPos + yPositionTracker;

		for (int i = (lower - 1); i <= (upper + 1); i++) {
			xPosition = -50 + xPositionTracker;
			for (int j = (lowerXLimit - 1); j <= (upperXLimit + 1); j++) {

				switch (grid[i][j].icon) {
				case(00) :
					waterSprite.setPosition(xPosition, yPosition);
					window->draw(waterSprite);
					break;
				case(11) :
					bottomLeftWaterCornerSprite.setPosition(xPosition, yPosition);
					window->draw(bottomLeftWaterCornerSprite);
					break;
				case(12) :
					leftWaterWallSprite.setPosition(xPosition, yPosition);
					window->draw(leftWaterWallSprite);
					break;
				case(13) :
					topLeftWaterCornerSprite.setPosition(xPosition, yPosition);
					window->draw(topLeftWaterCornerSprite);
					break;
				case(14) :
					topWaterWallSprite.setPosition(xPosition, yPosition);
					window->draw(topWaterWallSprite);
					break;
				case(15) :
					topRightWaterCornerSprite.setPosition(xPosition, yPosition);
					window->draw(topRightWaterCornerSprite);
					break;
				case(16) :
					rightWaterWallSprite.setPosition(xPosition, yPosition);
					window->draw(rightWaterWallSprite);
					break;
				case(17) :
					bottomRightWaterCornerSprite.setPosition(xPosition, yPosition);
					window->draw(bottomRightWaterCornerSprite);
					break;
				case(18) :
					BottomWaterWallSprite.setPosition(xPosition, yPosition);
					window->draw(BottomWaterWallSprite);
					break;
				case(10) :
					grassSprite.setPosition(xPosition, yPosition);
					window->draw(grassSprite);
					break;
				case(21) :
					flowerSprite.setPosition(xPosition, yPosition);
					window->draw(flowerSprite);
					break;
				}
				xPosition += 50;
			}
			yPosition += 50;
		}

		switch (dir) {
		case LEFT:
			xPosition++;
			xPositionTracker++;
			break;
		case RIGHT:
			xPosition--;
			xPositionTracker--;
			break;
		case UP:
			yPosition++;
			yPositionTracker++;
			break;
		case DOWN:
			yPosition--;
			yPositionTracker--;
			break;
		}


}

/**
	Cleans up Beach's variables.
*/
void Beach::onExit()
{
	delete window;
	window = NULL;
}

/**
	Checks every frame when the map is moving if moving should stop.
*/
void Beach::movingThreadCheck()
{
	if (testing) {
		if (threadCompleteCounter == 4){
			isMoving = false;

			switch (dir) {
			case LEFT:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation - 1][centerYLocation].center = true;
				break;
			case RIGHT:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation + 1][centerYLocation].center = true;
				break;
			case UP:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation][centerYLocation - 1].center = true;
				break;
			case DOWN:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation][centerYLocation + 1].center = true;
				break;
			}

			//set trackers and such to 0;
			seg1PositionTrackers.x = 0;
			seg1PositionTrackers.y = 0;
			seg1Position.x = 0;
			seg1Position.y = 0;

			seg2PositionTrackers.x = 0;
			seg2PositionTrackers.y = 0;
			seg2Position.x = 0;
			seg2Position.y = 0;

			seg3PositionTrackers.x = 0;
			seg3PositionTrackers.y = 0;
			seg3Position.x = 0;
			seg3Position.y = 0;

			seg4PositionTrackers.x = 0;
			seg4PositionTrackers.y = 0;
			seg4Position.x = 0;
			seg4Position.y = 0;

			threadCompleteCounter = 0;
		}
	}
	else {
		if (noThreadFinished) {
		
			isMoving = false;

			switch (dir) {
			case LEFT:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation - 1][centerYLocation].center = true;
				break;
			case RIGHT:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation + 1][centerYLocation].center = true;
				break;
			case UP:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation][centerYLocation - 1].center = true;
				break;
			case DOWN:
				grid[centerXLocation][centerYLocation].center = false;
				grid[centerXLocation][centerYLocation + 1].center = true;
				break;
			}

			//set trackers and such to 0;
			seg1PositionTrackers.x = 0;
			seg1PositionTrackers.y = 0;
			seg1Position.x = 0;
			seg1Position.y = 0;

			noThreadFinished = false;

		}
	
	}
}

/**
	Method for the algorithim to move the map by 1 pixel every frame until it has moved 50 pixels.
	@param The lower limit to start searching through the 2d grid at for the Y Axis.
	@param The upper limit to start searching through the 2d grid at for the Y Axis.
	@param The Y Position for the algorithim to start drawing.
	@param The Y Position for the algorithim to finish drawing.
	@param Vector2i to hold the position set for each frame.
	@param Vector2i to hold the tracker for accurately moving the map eaxch frame.
	@param int for what thread is being run.
*/
void Beach::threadMovingBeach(int lower, int upper, int yPosLower, int yPosLimit, sf::Vector2i * position, sf::Vector2i * tracker, int threadNum)
{

	position->y = yPosLower + tracker->y;

	for (int i = lower; i <= upper; i++) {
		position->x = -50 + tracker->x;
		for (int j = (lowerXLimit - 1); j <= (upperXLimit + 1); j++) {

			grid[i][j].xPos = position->x;
			grid[i][j].yPos = position->y;

			position->x += 50;
		}
		position->y += 50;
	}

	switch (dir) {
	case LEFT:
		tracker->x++;
		break;
	case RIGHT:
		tracker->x--;
		break;
	case UP:
		tracker->y++;
		break;
	case DOWN:
		tracker->y--;
		break;
	}

	if ((position->y) == (yPosLimit + 50) && (position->x) == 800 || (position->y) == (yPosLimit - 50) && (position->x) == 800 || (position->y + tracker->y) == yPosLimit && (position->x) == 850 || (position->y) == yPosLimit && (position->x) == 750) {

		switch (threadNum) {
		case 0:
			noThreadFinished = true;
			break;
		case 1: {
			std::unique_lock<std::mutex> lock(countCheck);
			threadCompleteCounter++;
			break;}
		case 2: {
			std::unique_lock<std::mutex> lock(countCheck);
			threadCompleteCounter++;
			break;}
		case 3: {
			std::unique_lock<std::mutex> lock(countCheck);
			threadCompleteCounter++;
			break;}
		case 4: {
			std::unique_lock<std::mutex> lock(countCheck);
			threadCompleteCounter++;
			break;}
		
		}
	}
}

/**
	Algorithim for calculating the position for drawing the grid when the map isnt moving.
	@param The lower limit to start searching through the 2d grid at for the Y Axis.
	@param The upper limit to start searching through the 2d grid at for the Y Axis.
	@param The Y Position for the algorithim to start drawing.
*/
void Beach::threadBeach(int lower, int upper, int yPos)
{
	xPosition = 0;
	yPosition = yPos;

	for (int i = lower; i <= upper; i++) {
		xPosition = 0;
		for (int j = lowerXLimit; j <= upperXLimit; j++) {
			grid[i][j].xPos = xPosition;
			grid[i][j].yPos = yPosition;

			xPosition += 50;
		}
		yPosition += 50;
	}
}

/**
	Algorithim to render the beach.
*/
void Beach::threadRenderBeach()
{
	if (isMoving) {
		for (int i = lowerYLimit - 1; i <= upperYLimit + 1; i++) {
			for (int j = (lowerXLimit - 1); j <= (upperXLimit + 1); j++) {

				grid[i][j].sprite->setPosition(grid[i][j].xPos, grid[i][j].yPos);
				window->draw((*grid[i][j].sprite));

			}

		}
	}
	else {
		for (int i = lowerYLimit; i <= upperYLimit; i++) {
			for (int j = lowerXLimit; j <= upperXLimit; j++) {

				grid[i][j].sprite->setPosition(grid[i][j].xPos, grid[i][j].yPos);
				window->draw((*grid[i][j].sprite));

			}

		}
	
	}
}

/**
	Method to animate all the sprites.
	@param deltaTime for controlling animations.
*/
void Beach::animations(float deltaTime)
{
	if (testing) {
		waterSprite.animate(deltaTime);
		flowerSprite.animate(deltaTime);
		topWaterWallSprite.animate(deltaTime);
		BottomWaterWallSprite.animate(deltaTime);
		leftWaterWallSprite.animate(deltaTime);
		rightWaterWallSprite.animate(deltaTime);
		topLeftWaterCornerSprite.animate(deltaTime);
		topRightWaterCornerSprite.animate(deltaTime);
		bottomRightWaterCornerSprite.animate(deltaTime);
		bottomLeftWaterCornerSprite.animate(deltaTime);

		ready = true;
		cv.notify_one();
	}
	else {
		waterSprite.animate(deltaTime);
		flowerSprite.animate(deltaTime);
		topWaterWallSprite.animate(deltaTime);
		BottomWaterWallSprite.animate(deltaTime);
		leftWaterWallSprite.animate(deltaTime);
		rightWaterWallSprite.animate(deltaTime);
		topLeftWaterCornerSprite.animate(deltaTime);
		topRightWaterCornerSprite.animate(deltaTime);
		bottomRightWaterCornerSprite.animate(deltaTime);
		bottomLeftWaterCornerSprite.animate(deltaTime);
	
	}
}
