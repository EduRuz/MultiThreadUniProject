/**
	2D Rpg game using a 2D array grid to test parallelisation in CPU with multiple threads.
	Testing the algorithim that sets the location for rendering.
	@Author Ruaraidh Canaway.
	The Game Loop in Main, Animation Class and Input class is Paul Robertsons code.
*/

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Game.h"

int WINDOW_WIDTH = 750;
int WINDOW_HEIGHT = 750;
int NUM_OF_SQUARES = 15;
int SQUARE_SIZE = 50;

void main()
{
	// Create window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	window.setPosition(sf::Vector2i(400, 0));
	window.setFramerateLimit(60);

	//Input Control
	Input input;

	//Game State
	Game game;
	game.initialize(&window, &input);

	//For Delta time
	sf::Clock clock;
	float deltaTime;

	//Game Loop
	while (window.isOpen())
	{
		//Calculate delta time. How much time has passed and since last calculated. Restart clock. 
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0.f, 0.f,
					(float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x,
					event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(false);
				}
				break;
			default:
				// don't handle other events
				break;
			}
		}

		if (input.isKeyDown(sf::Keyboard::Escape)) {
			input.setKeyUp(sf::Keyboard::Escape);
			window.close();
		}
	

		game.inputControl(deltaTime);
		game.update(deltaTime);

		window.clear();
		game.render(deltaTime);
		window.display();
	}

	
}