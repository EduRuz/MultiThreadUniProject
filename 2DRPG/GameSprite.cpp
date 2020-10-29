#include "GameSprite.h"



GameSprite::GameSprite()
{
}


GameSprite::~GameSprite()
{
}

/**
	Animation for the child classes.
	@param deltaTime for controlling the animations.
*/
void GameSprite::animate(float deltaTime)
{
	if (isAnimated) {
		currentAnimation->animate(deltaTime);
		setTextureRect(currentAnimation->getCurrentFrame());
	}
}

