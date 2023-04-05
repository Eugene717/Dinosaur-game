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
	virtual ~Entity();
	virtual void Input(sf::Event& event);
	virtual void Update(double elapsed) = 0;
	virtual void Render(sf::RenderWindow& window);
	const sf::Vector2f GetSpritePos() const;
	virtual bool CheckCollision(sf::Sprite* otherSprite) const;
};

