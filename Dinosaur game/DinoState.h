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
	sf::Vector2f GetPos() const;
public:
	DinoState(Dinosaur* dino);
	DinoState(DinoState* other);
	virtual DinoState* Input(sf::Event& event) = 0;
	virtual DinoState* Update() = 0;
};

class RunState : public DinoState
{

public:
	RunState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	DinoState* Update() override;
};

class JumpState : public DinoState
{
	bool keyPressed_;
	bool onGround_;
	bool jumpedTop_;
public:
	JumpState(Dinosaur* dino);
	JumpState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	DinoState* Update() override;
};

class CrouchState : public DinoState
{

public:
	CrouchState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	DinoState* Update() override;
};