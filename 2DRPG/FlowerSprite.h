#pragma once
#include "GameSprite.h"
class FlowerSprite :
	public GameSprite
{
public:
	FlowerSprite();
	~FlowerSprite();

	void initialize();


private:
	sf::Texture flowerSpriteSheet;
	Animation flow;
};

