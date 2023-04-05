#include "DinoState.h"
#include "Dinosaur.h"

double DinoState::last_;
bool DinoState::firstFrame_;
const float GRAVITY = 2.0f;  //free fall
const float JUMP_VELOCITY = -0.65f;  //initial speed

DinoState::DinoState(Dinosaur* dino) :dino_(dino)
{
	firstFrame_ = true;
}

DinoState::DinoState(DinoState* other) : dino_(other->dino_)
{ }

DinoState::~DinoState()
{ }

JumpState::JumpState(Dinosaur* dino) : DinoState(dino), keyPressed_(true), onGround_(false), velocity_(0, JUMP_VELOCITY)
{
	NextFrame(sf::IntRect(848, 2, 44, 46));
}

RunState::RunState(DinoState* other) : DinoState(other)
{
	if (firstFrame_)
		NextFrame(sf::IntRect(936, 2, 44, 46));
	else
		NextFrame(sf::IntRect(980, 2, 44, 46));
}

JumpState::JumpState(DinoState* other) : DinoState(other), keyPressed_(true), onGround_(false), velocity_(0, JUMP_VELOCITY)
{
	NextFrame(sf::IntRect(848, 2, 44, 46));
}

CrouchState::CrouchState(DinoState* other) : DinoState(other)
{
	if (firstFrame_)
		NextFrame(sf::IntRect(1171, 19, 59, 29));
	else
		NextFrame(sf::IntRect(1112, 19, 59, 29));

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

DinoState* RunState::Update(double elapsed)
{
	if (last_ + elapsed >= 100)
	{
		if (firstFrame_)
		{
			NextFrame(sf::IntRect(936, 2, 44, 46));
			firstFrame_ = false;
		}
		else
		{
			NextFrame(sf::IntRect(980, 2, 44, 46));
			firstFrame_ = true;
		}
		last_ = 0;
	}
	else
		last_ += elapsed;

	return nullptr;
}

DinoState* JumpState::Input(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
		if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
			keyPressed_ = false;

	return nullptr;
}

DinoState* JumpState::Update(double elapsed)
{
	float moveDown = 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown = 2.5f;
	}

	velocity_.y += GRAVITY * moveDown * (elapsed / 1000);
	Move(sf::Vector2f(0, velocity_.y * elapsed));

	if (GetPos().y >= 100)
	{
		onGround_ = true;
		Move(sf::Vector2f(0, 100 - GetPos().y));
	}

	if (!keyPressed_ && onGround_)
		return new RunState(this);
	else if (onGround_ && keyPressed_)
	{
		velocity_.y = JUMP_VELOCITY;
		onGround_ = false;
	}

	return nullptr;
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

DinoState* CrouchState::Update(double elapsed)
{
	if (last_ + elapsed >= 100)
	{
		if (firstFrame_)
		{
			NextFrame(sf::IntRect(1171, 19, 59, 29));
			firstFrame_ = false;
		}
		else
		{
			NextFrame(sf::IntRect(1112, 19, 59, 29));
			firstFrame_ = true;
		}
		last_ = 0;
	}
	else
		last_ += elapsed;

	return nullptr;
}
