#pragma once
#include "GameSprite.h"
#include "Input.h"
#include "Animation.h"
#include "Beach.h"


class Player :
	public GameSprite
{
public:
	Player();
	~Player();
	
	void initialize(Input* in);
	void inputControl(DIRECTION direcion, Map* beach);
	void update(float deltaTime);
	void render();
	void onExit();

private:

	Input* input;

	sf::Texture playerSprite;
	sf::Texture playerSpiteSheet;

	Animation standLookUp;
	Animation standLookDown;
	Animation standLookLeft;
	Animation standLookRight;

	Animation walkUp;
	Animation walkDown;
	Animation walkLeft;
	Animation walkRight;

	
};

