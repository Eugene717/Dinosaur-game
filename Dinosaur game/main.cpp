#include <SFML/Graphics.hpp>
#include "Game.h"

const int MS_PER_UPDATE = 16;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 200), "Dinosaur");
	window.setVerticalSyncEnabled(true);

	Game game;
	sf::Clock clock;
	double lag = 0.0;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			game.Input(event);
		}

		sf::Time elapsed = clock.getElapsedTime();
		lag += elapsed.asMilliseconds();
		
		while (lag >= MS_PER_UPDATE)
		{
			game.Update(clock.getElapsedTime());
			lag -= MS_PER_UPDATE;
		}

		clock.restart();

		game.Render(window);
	}

	return 0;
}
