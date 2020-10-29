#include "WaterSprite.h"



WaterSprite::WaterSprite()
{
}


WaterSprite::~WaterSprite()
{
}

/**
	Initializes the water sprites for animating.
	@param the icon value for what part of the sprite sheet to take the animation frames from.
*/
void WaterSprite::initialize(int icon)
{
	waterSpriteSheet.loadFromFile("Gfx/WaterSpriteSheet.png");
	setTexture(&waterSpriteSheet);
	setSize(sf::Vector2f(50, 50));

	switch (icon) {
	case 00:
		flow.addFrame(sf::IntRect(0, 0, 50, 50));
		flow.addFrame(sf::IntRect(55, 0, 50, 50));
		flow.addFrame(sf::IntRect(110, 0, 50, 50));
		flow.addFrame(sf::IntRect(165, 0, 50, 50));
		flow.addFrame(sf::IntRect(220, 0, 50, 50));
		flow.addFrame(sf::IntRect(275, 0, 50, 50));
		flow.addFrame(sf::IntRect(330, 0, 50, 50));
		flow.addFrame(sf::IntRect(385, 0, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
	break;
	case 18:
		flow.addFrame(sf::IntRect(0,55, 50, 50));
		flow.addFrame(sf::IntRect(55, 55, 50, 50));
		flow.addFrame(sf::IntRect(110, 55, 50, 50));
		flow.addFrame(sf::IntRect(165, 55, 50, 50));
		flow.addFrame(sf::IntRect(220, 55, 50, 50));
		flow.addFrame(sf::IntRect(275, 55, 50, 50));
		flow.addFrame(sf::IntRect(330, 55, 50, 50));
		flow.addFrame(sf::IntRect(385, 55, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 14:
		flow.addFrame(sf::IntRect(0, 110, 50, 50));
		flow.addFrame(sf::IntRect(55, 110, 50, 50));
		flow.addFrame(sf::IntRect(110, 110, 50, 50));
		flow.addFrame(sf::IntRect(165, 110, 50, 50));
		flow.addFrame(sf::IntRect(220, 110, 50, 50));
		flow.addFrame(sf::IntRect(275, 110, 50, 50));
		flow.addFrame(sf::IntRect(330, 110, 50, 50));
		flow.addFrame(sf::IntRect(385, 110, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 12:
		flow.addFrame(sf::IntRect(0, 165, 50, 50));
		flow.addFrame(sf::IntRect(55, 165, 50, 50));
		flow.addFrame(sf::IntRect(110, 165, 50, 50));
		flow.addFrame(sf::IntRect(165, 165, 50, 50));
		flow.addFrame(sf::IntRect(220, 165, 50, 50));
		flow.addFrame(sf::IntRect(275, 165, 50, 50));
		flow.addFrame(sf::IntRect(330, 165, 50, 50));
		flow.addFrame(sf::IntRect(385, 165, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 16:
		flow.addFrame(sf::IntRect(0, 220, 50, 50));
		flow.addFrame(sf::IntRect(55, 220, 50, 50));
		flow.addFrame(sf::IntRect(110, 220, 50, 50));
		flow.addFrame(sf::IntRect(165, 220, 50, 50));
		flow.addFrame(sf::IntRect(220, 220, 50, 50));
		flow.addFrame(sf::IntRect(275, 220, 50, 50));
		flow.addFrame(sf::IntRect(330, 220, 50, 50));
		flow.addFrame(sf::IntRect(385, 220, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 17:
		flow.addFrame(sf::IntRect(0, 275, 50, 50));
		flow.addFrame(sf::IntRect(55, 275, 50, 50));
		flow.addFrame(sf::IntRect(110, 275, 50, 50));
		flow.addFrame(sf::IntRect(165, 275, 50, 50));
		flow.addFrame(sf::IntRect(220, 275, 50, 50));
		flow.addFrame(sf::IntRect(275, 275, 50, 50));
		flow.addFrame(sf::IntRect(330, 275, 50, 50));
		flow.addFrame(sf::IntRect(385, 275, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 11:
		flow.addFrame(sf::IntRect(0, 330, 50, 50));
		flow.addFrame(sf::IntRect(55, 330, 50, 50));
		flow.addFrame(sf::IntRect(110, 330, 50, 50));
		flow.addFrame(sf::IntRect(165, 330, 50, 50));
		flow.addFrame(sf::IntRect(220, 330, 50, 50));
		flow.addFrame(sf::IntRect(275, 330, 50, 50));
		flow.addFrame(sf::IntRect(330, 330, 50, 50));
		flow.addFrame(sf::IntRect(385, 330, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 13:
		flow.addFrame(sf::IntRect(0, 385, 50, 50));
		flow.addFrame(sf::IntRect(55, 385, 50, 50));
		flow.addFrame(sf::IntRect(110, 385, 50, 50));
		flow.addFrame(sf::IntRect(165, 385, 50, 50));
		flow.addFrame(sf::IntRect(220, 385, 50, 50));
		flow.addFrame(sf::IntRect(275, 385, 50, 50));
		flow.addFrame(sf::IntRect(330, 385, 50, 50));
		flow.addFrame(sf::IntRect(385, 385, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	case 15:
		flow.addFrame(sf::IntRect(0, 441, 50, 50));
		flow.addFrame(sf::IntRect(55, 441, 50, 50));
		flow.addFrame(sf::IntRect(110, 441, 50, 50));
		flow.addFrame(sf::IntRect(165, 441, 50, 50));
		flow.addFrame(sf::IntRect(220, 441, 50, 50));
		flow.addFrame(sf::IntRect(275, 441, 50, 50));
		flow.addFrame(sf::IntRect(330, 441, 50, 50));
		flow.addFrame(sf::IntRect(385, 441, 50, 50));
		flow.setFrameSpeed(1.f / 3.f);
		break;
	}

	currentAnimation = &flow;
	setTextureRect(currentAnimation->getCurrentFrame());
	isAnimated = true;

}
