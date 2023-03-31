#pragma once
#include "Entity.h"
#include <list>

class Score;

class World : public Entity
{
	sf::Sprite sprite2_;  //for cycled animation
	Score* score_;

	std::list<Entity*> objects_;

	int timerToSpawnCactuses_;

	void SpawnNewObjects();
	void DeleteOldObjects();
public:
	World();
	~World();
	void Init();
	void Update(sf::Time elapsed) override;
	void Render(sf::RenderWindow& window) override;
	bool CheckCollision(sf::FloatRect rect) const override;
};

