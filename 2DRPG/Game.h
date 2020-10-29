#pragma once
#include  <SFML/Graphics.hpp>
#include "GameSprite.h"
#include "Player.h"
#include "Input.h"
#include "Beach.h"
#include <vector>
#include <sstream>

class Game
{
public:
	Game();
	~Game();

	void initialize(sf::RenderWindow* wind, Input* in);
	void inputControl(float deltaTime);
	void update(float deltaTime);
	void render(float deltaTime);
	void onExit();
	void drawGrid();

private:
	sf::RenderWindow* window;
	Input* input;

	sf::Texture loadingTexture;
	GameSprite loadingsprite;


	float fps;
	sf::Font ArielFont;
	sf::Text fpsText;
	std::ostringstream ss;

	sf::Vertex line[2];

	Beach beach;
	Player player;
	
protected:

	
};

