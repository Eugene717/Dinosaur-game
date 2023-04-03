#pragma once
#include "Entity.h"

class Pterodactyl : public Entity
{
	bool firstFrame_;
	sf::Time last_;
public:
	Pterodactyl(int heightPos);
	~Pterodactyl();
	void Update(sf::Time elapsed) override;
	bool CheckCollision(sf::FloatRect rect) const override;
};

