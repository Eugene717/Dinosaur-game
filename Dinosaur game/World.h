#pragma once
#include "Entity.h"
#include <list>

class Score;
class WorldFactory;

class World : public Entity
{
	sf::Sprite sprite2_;  //for cycled animation
	Score* score_;   //works like timer
	float speedUp_;

	WorldFactory* factory_;
	std::list<Entity*> objects_;

	void SpawnNewObjects();
	void DeleteOldObjects();
public:
	World();
	~World();
	void Init();
	void Update(double elapsed) override;
	void Render(sf::RenderWindow& window) override;
	bool CheckCollision(sf::Sprite* otherSprite) const override;
};

