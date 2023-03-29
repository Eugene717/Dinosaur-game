#pragma once
#include "Entity.h"

class DinoState;

class Dinosaur : public Entity
{
	DinoState* state_;
	bool init_;
public:
	Dinosaur();
	~Dinosaur();
	sf::IntRect GetSpriteRect() const;
	void Init();
	void Input(sf::Event& event) override;
	void Update() override;

	friend DinoState;
};

