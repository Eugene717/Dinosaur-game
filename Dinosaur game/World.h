#pragma once
#include "Entity.h"
#include <list>

class World : public Entity
{
	sf::Sprite sprite2_;  //for cycled animation
	std::list<Entity*> objects_;
	sf::Time spawnTimer_;

	void SpawnNewObjects();
public:
	World();
	~World(); 
	void Update(sf::Time elapsed) override;
	void Render(sf::RenderWindow& window) override;
};

