#pragma once
#include "Entity.h"

class Pterodactyl : public Entity
{
	bool firstFrame_;
	double last_;
public:
	Pterodactyl(int heightPos);
	~Pterodactyl();
	void Update(double elapsed) override;
	bool CheckCollision(sf::Sprite* otherSprite) const override;
};

