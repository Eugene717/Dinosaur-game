#pragma once
#include <SFML/Graphics.hpp>

class Game
{
	std::vector<sf::Drawable*> objects_;
public:
	void Input(sf::Keyboard::Key key);
	void Update();
	void Render(sf::RenderWindow& window);
};

