#pragma once
#include "Entity.h"

class Cloud : public Entity
{
public:
	Cloud(int heightPos);
	~Cloud();
	void Update(double elapsed) override;
};

