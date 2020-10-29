#include "FlowerSprite.h"



FlowerSprite::FlowerSprite()
{
}


FlowerSprite::~FlowerSprite()
{
}

/**
	Initializes the flower sprites for animating.
*/
void FlowerSprite::initialize()
{
	flowerSpriteSheet.loadFromFile("Gfx/FlowerSpriteSheet.png");
	setTexture(&flowerSpriteSheet);
	setSize(sf::Vector2f(50, 50));

	flow.addFrame(sf::IntRect(0, 0, 50, 50));
	flow.addFrame(sf::IntRect(57, 0, 50, 50));
	flow.addFrame(sf::IntRect(115, 0, 50, 50));
	flow.addFrame(sf::IntRect(57, 0, 50, 50));
	flow.setFrameSpeed(1.f / 3.f);

	currentAnimation = &flow;
	setTextureRect(currentAnimation->getCurrentFrame());
	isAnimated = true;
}


