#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

/**
	Initializes the variables needed for the game state.
	@param Pointer to the window needing rendered too.
	@param Pointer to the Input class for input control.
*/
void Game::initialize(sf::RenderWindow* wind, Input* in)
{
	window = wind;
	input = in;

	ArielFont.loadFromFile("font/arial.ttf");
	fpsText.setFont(ArielFont);
	fpsText.setCharacterSize(20);
	fpsText.setFillColor(sf::Color::White);
	fpsText.setStyle(sf::Text::Bold);
	fpsText.setPosition(window->getSize().x*0.8, window->getSize().y*0.95);
	
	loadingTexture.loadFromFile("Gfx/Loading.png");
	loadingsprite.setTexture(&loadingTexture);
	loadingsprite.setSize(sf::Vector2f(750,750));
	loadingsprite.setPosition(0,0);

	window->clear();
	window->draw(loadingsprite);
	window->display();
	
	beach.initialize(window);
	player.initialize(input);
}

/**
	Controls input for the game state.
	@param Delta time.
*/
void Game::inputControl(float deltaTime)
{

	if (input->isKeyDown(sf::Keyboard::Left)) {
		
		player.inputControl(LEFT, &beach);
		beach.inputControl(LEFT);

		input->setKeyUp(sf::Keyboard::Left);
	}

	if (input->isKeyDown(sf::Keyboard::Right)) {

		player.inputControl(RIGHT, &beach);
		beach.inputControl(RIGHT);
		
		input->setKeyUp(sf::Keyboard::Right);
	}

	if (input->isKeyDown(sf::Keyboard::Up)) {

		player.inputControl(UP, &beach);
		beach.inputControl(UP);

		input->setKeyUp(sf::Keyboard::Up);
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {

		player.inputControl(DOWN, &beach);
		beach.inputControl(DOWN);

		input->setKeyUp(sf::Keyboard::Down);
	}
}

/**
	Updates variables for the game state.
	@param Delta time.
*/
void Game::update(float deltaTime)
{
	fps = 1.0f / deltaTime;

	ss.str("");
	ss.clear();
	ss << "FPS: " << fps;
	fpsText.setString(ss.str());

	beach.update(deltaTime);
	player.update(deltaTime);
}

/**
	Renders the gamestate.
	@param deltaTime for rendering the beach.
*/
void Game::render(float deltaTime)
{

	beach.render(deltaTime);
	//drawGrid();
	window->draw(player);
	window->draw(fpsText);

}

/**
	Cleans up the variables for the gamestate,
	Called when the gamestate closes.
*/
void Game::onExit()
{
	delete window;
	window = NULL;
}

/**
	Method to draw the game grid on screen.
*/
void Game::drawGrid()
{
	int horizontalTemp = 50;
	int verticalTemp = 50;
	for (int i = 0; i < 14; i++){

		line[0] = sf::Vector2f(0, horizontalTemp);
		line[1] = sf::Vector2f(window->getSize().x, horizontalTemp);

		window->draw(line, 2, sf::Lines);

		horizontalTemp += 50;
	}

	for (int i = 0; i < 14; i++) {

		line[0] = sf::Vector2f(verticalTemp, 0);
		line[1] = sf::Vector2f(verticalTemp, window->getSize().y);

		window->draw(line, 2, sf::Lines);

		verticalTemp += 50;
	}
}
