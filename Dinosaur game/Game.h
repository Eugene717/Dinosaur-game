#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class Game
{
	std::vector<Entity*> objects_;
public:
	void Input(sf::Keyboard::Key key);
	void Update();
	void Render(sf::RenderWindow& window);
};

