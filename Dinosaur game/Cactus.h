#pragma once
#include "Entity.h"

class Cactus : public Entity
{

public:
	Cactus();
	~Cactus();
	void Update(sf::Time elapsed) override;
};

