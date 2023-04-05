#pragma once
#include "Entity.h"
#include <list>

class Score;

class World : public Entity
{
	sf::Sprite sprite2_;  //for cycled animation
	Score* score_;   //works like timer

	std::list<Entity*> objects_;

	std::vector<int> timers_;  //old time to respawn objects after time

	void SpawnNewObjects();
	void DeleteOldObjects();
public:
	World();
	~World();
	void Init();
	void Update(sf::Time elapsed) override;
	void Render(sf::RenderWindow& window) override;
	bool CheckCollision(sf::Sprite* otherSprite) const override;
};

