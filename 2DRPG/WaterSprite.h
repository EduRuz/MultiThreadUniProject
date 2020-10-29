#pragma once
#include "GameSprite.h"
#include "Animation.h"

class WaterSprite :
	public GameSprite
{
public:
	WaterSprite();
	~WaterSprite();

	void initialize(int icon);

private:
	sf::Texture waterSpriteSheet;
	Animation flow;
};

