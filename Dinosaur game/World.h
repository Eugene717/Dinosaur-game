#pragma once
#include "Entity.h"

class World : public Entity
{
	sf::Sprite sprite2_;  //for cycled animation
public:
	World();
	~World(); 
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};

