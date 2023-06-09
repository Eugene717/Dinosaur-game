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
	sf::Sprite* GetSprite() const;
	void SetDeadStatus();
	void Init();
	void Input(sf::Event& event) override;
	void Update(double elapsed) override;

	friend DinoState;
};

