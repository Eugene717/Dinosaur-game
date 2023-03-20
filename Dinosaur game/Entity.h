#pragma once
#include <SFML/Graphics.hpp>

class Entity
{

public:
	virtual void Input(sf::Keyboard::Key key);
	virtual void Update() = 0;
	void Render(sf::RenderWindow& window);
};

