#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

/**
	Initialize the variables required to draw and animate the player sprite.
	@param The Input variable for controlling key presses int he player class.
*/
void Player::initialize(Input* in)
{
	input = in;
	playerSprite.loadFromFile("Gfx/player.png");
	setTexture(&playerSprite);
	playerSpiteSheet.loadFromFile("Gfx/Protaginist Sprite Sheet.png");
	setTexture(&playerSpiteSheet);
	setSize(sf::Vector2f(50, 50));
	xPosition = 350;
	yPosition = 350;

	standLookUp.addFrame(sf::IntRect(7, 1037, 50, 50));
	standLookUp.addFrame(sf::IntRect(71, 1037, 50, 50));
	standLookUp.setFrameSpeed(0.5f / 0.5f);

	standLookLeft.addFrame(sf::IntRect(7, 845, 50, 50));
	standLookLeft.addFrame(sf::IntRect(71, 845, 50, 50));
	standLookLeft.setFrameSpeed(0.5f / 0.5f);

	standLookDown.addFrame(sf::IntRect(7, 909, 50, 50));
	standLookDown.addFrame(sf::IntRect(71, 909, 50, 50));
	standLookDown.setFrameSpeed(0.5f / 0.5f);

	standLookRight.addFrame(sf::IntRect(7, 974, 50, 50));
	standLookRight.addFrame(sf::IntRect(71, 974, 50, 50));
	standLookRight.setFrameSpeed(0.5f / 0.5f);
	
	// Setup walk animation.
	walkUp.addFrame(sf::IntRect(7, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(71, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(135, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(199, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(264, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(327, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(391, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(456, 523, 50, 50));
	walkUp.addFrame(sf::IntRect(519, 523, 50, 50));
	walkUp.setFrameSpeed(1.f / 10.f);

	// Setup walk animation.
	walkLeft.addFrame(sf::IntRect(7, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(71, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(135, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(199, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(264, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(327, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(391, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(456, 589, 50, 50));
	walkLeft.addFrame(sf::IntRect(519, 589, 50, 50));
	walkLeft.setFrameSpeed(1.f / 10.f);

	// Setup walk animation.
	walkDown.addFrame(sf::IntRect(7, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(71, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(135, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(199, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(264, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(327, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(391, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(456, 653, 50, 50));
	walkDown.addFrame(sf::IntRect(519, 653, 50, 50));
	walkDown.setFrameSpeed(1.f / 10.f);

	// Setup walk animation.
	walkRight.addFrame(sf::IntRect(7, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(71, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(135, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(199, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(264, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(327, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(391, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(456, 717, 50, 50));
	walkRight.addFrame(sf::IntRect(519, 717, 50, 50));
	walkRight.setFrameSpeed(1.f / 10.f);

	currentAnimation = &standLookDown;
	setTextureRect(currentAnimation->getCurrentFrame());
}

/**
	Controls the input required to control the player.
	@param direction enum value for what way the player is attempting to move.
	@param The Map the player is currently moving on to control wether animation 
	should happen when player cant move.
*/
void Player::inputControl(DIRECTION direcion, Map* beach)
{
	switch (direcion) {
	case LEFT:
		if (beach->getIsSolid(LEFT) == false) {
			if (beach->getIsMoving() == false) {
				currentAnimation = &walkLeft;
				currentAnimation->reset();
				currentAnimation->setLooping(false);
				setTextureRect(currentAnimation->getCurrentFrame());
				dir = LEFT;
				
			}
		}
		break;
	case RIGHT:
		if (beach->getIsSolid(RIGHT) == false) {
			if (beach->getIsMoving() == false) {
				currentAnimation = &walkRight;
				currentAnimation->reset();
				currentAnimation->setLooping(false);
				setTextureRect(currentAnimation->getCurrentFrame());
				dir = RIGHT;
			}
		}
		break;
	case UP:
		if (beach->getIsSolid(UP) == false) {
			if (beach->getIsMoving() == false) {
				currentAnimation = &walkUp;
				currentAnimation->reset();
				currentAnimation->setLooping(false);
				setTextureRect(currentAnimation->getCurrentFrame());
				dir = UP;
			}
		}
		break;
	case DOWN:
		if (beach->getIsSolid(DOWN) == false) {
			if (beach->getIsMoving() == false) {
				currentAnimation = &walkDown;
				currentAnimation->reset();
				currentAnimation->setLooping(false);
				setTextureRect(currentAnimation->getCurrentFrame());
				dir = DOWN;
			}
		}
		break;


	}

}

/**
	Player Update method, controls animation.
	@param deltaTime for animation.
*/
void Player::update(float deltaTime)
{
	currentAnimation->animate(deltaTime);
	setTextureRect(currentAnimation->getCurrentFrame());

	setPosition(xPosition, yPosition);
}

/**
	Player Render Method. (Potentially get rid of it)
*/
void Player::render()
{
}

/**
	On exit to clean up variables.
*/
void Player::onExit()
{
}
