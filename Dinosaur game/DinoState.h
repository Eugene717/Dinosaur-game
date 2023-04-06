#pragma once
#include <SFML/Graphics.hpp>

class Dinosaur;

class DinoState
{
	Dinosaur* dino_;
protected:
	static bool firstFrame_;
	static double last_;  //for changing frame

	void NextFrame(sf::IntRect rect);
	void Move(sf::Vector2f pos);
	sf::Vector2f GetPos() const;
public:
	DinoState(Dinosaur* dino);
	DinoState(DinoState* other);
	virtual ~DinoState();
	virtual DinoState* Input(sf::Event& event) = 0;
	virtual DinoState* Update(double elapsed) = 0;
};

class RunState : public DinoState
{
public:
	RunState(Dinosaur* dino);
	RunState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	DinoState* Update(double elapsed) override;
};

class JumpState : public DinoState
{
	bool keyPressed_;
	bool onGround_;
	sf::Vector2f velocity_;
public:
	JumpState(Dinosaur* dino);
	JumpState(DinoState* other);
	DinoState* Input(sf::Event& event) override;
	DinoState* Update(double elapsed) override;
};

class CrouchState : public DinoState
{
public:
	CrouchState(DinoState* other);
	~CrouchState();
	DinoState* Input(sf::Event& event) override;
	DinoState* Update(double elapsed) override;
};

class DeadState : public DinoState
{
public:
	DeadState(Dinosaur* dino);
	DinoState* Input(sf::Event& event) override;
	DinoState* Update(double elapsed) override;
};
