#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Star : public Entity
{
public:
	Star(int n, int heightPos);
	~Star();
	void Update(double elapsed) override;
};

