#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
	static bool loadedTexture_;
protected:
	static sf::Texture texture_;
	sf::Sprite sprite_;
public:
	Entity();
	~Entity();
	virtual void Input(sf::Event& event);
	virtual void Update(sf::Time elapsed) = 0;
	virtual void Render(sf::RenderWindow& window);
};

