#pragma once
#include <SFML/Graphics.hpp>

class Dinosaur;

class DinoState
{
	Dinosaur* dino_;
protected:
	sf::Clock clock_;
	bool firstFrame_;

	void NextFrame(sf::IntRect rect);
	void Move(sf::Vector2f pos);
public:
	DinoState(Dinosaur* dino);
	DinoState(DinoState* other);
	virtual DinoState* Input(sf::Event& event) = 0;
	virtual void Update() = 0;
};

class RunState : public DinoState
{

public:
	RunState(Dinosaur* dino);
	RunState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	void Update() override;
};

class JumpState : public DinoState
{

public:
	JumpState(Dinosaur* dino);
	JumpState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	void Update() override;
};

class CrouchState : public DinoState
{

public:
	CrouchState(Dinosaur* dino);
	CrouchState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	void Update() override;
};