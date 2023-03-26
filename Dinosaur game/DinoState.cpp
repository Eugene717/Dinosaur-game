#include "DinoState.h"
#include "Dinosaur.h"

DinoState::DinoState(Dinosaur* dino) :dino_(dino), firstFrame_(true)
{ }

DinoState::DinoState(DinoState* other) : dino_(other->dino_), firstFrame_(other->firstFrame_)
{ }

RunState::RunState(Dinosaur* dino) : DinoState(dino)
{ }

JumpState::JumpState(Dinosaur* dino) : DinoState(dino)
{
	NextFrame(sf::IntRect(848, 2, 43, 46));
}

CrouchState::CrouchState(Dinosaur* dino) : DinoState(dino)
{
	NextFrame(sf::IntRect(980, 2, 43, 46));
	Move(sf::Vector2f(0, 17));
}

RunState::RunState(DinoState* other) : DinoState(other)
{ }

JumpState::JumpState(DinoState* other) : DinoState(other)
{
	NextFrame(sf::IntRect(848, 2, 43, 46));
}

CrouchState::CrouchState(DinoState* other) : DinoState(other)
{
	NextFrame(sf::IntRect(980, 2, 43, 46));
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

void RunState::Update()
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
}

DinoState* JumpState::Input(sf::Event& event)
{
	return nullptr;
}

void JumpState::Update()
{

}

DinoState* CrouchState::Input(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Down)
		{
			Move(sf::Vector2f(0, -17));
			return new RunState(this); 
		}
	}

	return nullptr;
}

void CrouchState::Update()
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
}
