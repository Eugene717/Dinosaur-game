#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Moon : public Entity
{
public:
	Moon(int n);
	~Moon();
	void Update(double elapsed) override;
};

