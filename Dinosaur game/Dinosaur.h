#pragma once
#include "Entity.h"

class Dinosaur : public Entity
{
	bool init_, jump_, crouch_;
	void Jump();
public:
	Dinosaur();
	~Dinosaur();
	void Init();
	void Input(sf::Event& event) override;
	void Update() override;
};

