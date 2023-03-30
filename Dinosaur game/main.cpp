#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 200), "Dinosaur");
	window.setVerticalSyncEnabled(true);

	Game game;
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			game.Input(event);
		}

		game.Update(clock.getElapsedTime());
		clock.restart();

		game.Render(window);
	}

	return 0;
}
