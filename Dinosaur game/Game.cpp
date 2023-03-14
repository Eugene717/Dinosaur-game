#include "Game.h"

void Game::Input(sf::Keyboard::Key key)
{

}

void Game::Update()
{

}

void Game::Render(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);

	for (int i = 0; i < objects_.size(); i++)
	{
		window.draw(*objects_[i]);
	}

	window.display();
}
