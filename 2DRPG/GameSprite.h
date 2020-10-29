#pragma once
#include "SFML\Graphics.hpp"
#include "Animation.h"

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

class GameSprite :
	public sf::RectangleShape
{
public:
	GameSprite();
	~GameSprite();

	void animate(float deltaTime);

protected:

	float xPosition;
	float yPosition;
	bool isMoving;
	DIRECTION dir;

	Animation* currentAnimation;
	bool isAnimated = false;
};

