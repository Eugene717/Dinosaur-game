#pragma once
#include "Entity.h"

class Cactus : public Entity
{
	static std::vector<sf::IntRect> cactuses_;
public:
	Cactus(int n);
	~Cactus();
	void Update(double elapsed) override;
	bool CheckCollision(sf::Sprite* otherSprite) const override;
};

