#include "DinoState.h"
#include "Dinosaur.h"

DinoState::DinoState(Dinosaur* dino) :dino_(dino), firstFrame_(true)
{ }

DinoState::DinoState(DinoState* other) : dino_(other->dino_), firstFrame_(other->firstFrame_)
{ }

JumpState::JumpState(Dinosaur* dino) : DinoState(dino), keyPressed_(true), onGround_(false), jumpedTop_(false)
{
	NextFrame(sf::IntRect(848, 2, 43, 46));
	Move(sf::Vector2f(0, -5));
}

RunState::RunState(DinoState* other) : DinoState(other)
{ }

JumpState::JumpState(DinoState* other) : DinoState(other), keyPressed_(true), onGround_(false), jumpedTop_(false)
{
	NextFrame(sf::IntRect(848, 2, 43, 46));
	Move(sf::Vector2f(0, -5));
}

CrouchState::CrouchState(DinoState* other) : DinoState(other)
{
	if (firstFrame_)
		NextFrame(sf::IntRect(1171, 19, 58, 29));
	else
		NextFrame(sf::IntRect(1112, 19, 58, 29));

	Move(sf::Vector2f(0, 17));
}

void DinoState::NextFrame(sf::IntRect rect)
{
	dino_->sprite_.setTextureRect(rect);
}

void DinoState::Move(sf::Vector2f pos)
{
	dino_->sprite_.move(pos);
}

sf::Vector2f DinoState::GetPos() const
{
	return dino_->sprite_.getPosition();
}

DinoState* RunState::Input(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
			return new JumpState(this);
		if (event.key.code == sf::Keyboard::Down)
			return new CrouchState(this);
	}

	return nullptr;
}

DinoState* RunState::Update()
{
	if (clock_.getElapsedTime().asMilliseconds() >= 100)
	{
		if (firstFrame_)
		{
			NextFrame(sf::IntRect(936, 2, 43, 46));
			firstFrame_ = false;
		}
		else
		{
			NextFrame(sf::IntRect(980, 2, 43, 46));
			firstFrame_ = true;
		}
		clock_.restart();
	}
	return nullptr;
}

DinoState* JumpState::Input(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
		if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
			keyPressed_ = false;

	return nullptr;
}

DinoState* JumpState::Update()
{
	int moveDown = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		jumpedTop_ = true;
		moveDown = 5;
	}

	if (clock_.getElapsedTime().asMilliseconds() >= 10)
	{
		if (jumpedTop_)
			Move(sf::Vector2f(0, moveDown));
		else
			Move(sf::Vector2f(0, -5));

		clock_.restart();
	}

	if (GetPos().y <= 30)
		jumpedTop_ = true;

	if (GetPos().y >= 100)
	{
		onGround_ = true;
		Move(sf::Vector2f(0, 100 - GetPos().y));
	}

	if (!keyPressed_ && onGround_)
		return new RunState(this);
	else if (onGround_ && keyPressed_)
	{
		jumpedTop_ = false;
		onGround_ = false;
		Move(sf::Vector2f(0, -5));
	}

	return nullptr;
}

DinoState* CrouchState::Input(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Down)
		{
			NextFrame(sf::IntRect(936, 2, 43, 46));
			Move(sf::Vector2f(0, -17));
			return new RunState(this); 
		}
	}

	return nullptr;
}

DinoState* CrouchState::Update()
{
	if (clock_.getElapsedTime().asMilliseconds() >= 100)
	{
		if (firstFrame_)
		{
			NextFrame(sf::IntRect(1171, 19, 58, 29));
			firstFrame_ = false;
		}
		else
		{
			NextFrame(sf::IntRect(1112, 19, 58, 29));
			firstFrame_ = true;
		}
		clock_.restart();
	}
	return nullptr;
}
