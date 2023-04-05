#pragma once
#include <SFML/Graphics.hpp>

class Entity;

class Game
{
	std::vector<Entity*> objects_;
	bool started_, ended_;
public:
	Game();
	~Game();
	void Init();
	void Input(sf::Event& event);
	void Update(double elapsed);
	void Render(sf::RenderWindow& window);
};

