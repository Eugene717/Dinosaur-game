#include "Dinosaur.h"
#include "DinoState.h"

Dinosaur::Dinosaur()
{
	init_ = false;
	state_ = nullptr;

	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(40, 2, 43, 46));
	sprite_.setPosition(50, 100);
}

Dinosaur::~Dinosaur()
{ }

sf::FloatRect Dinosaur::GetGlobalBounds() const
{
	return sprite_.getGlobalBounds();
}

void Dinosaur::Init()
{
	state_ = new JumpState(this);
	
	init_ = true;
}

void Dinosaur::Input(sf::Event& event)
{	
	if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
	{
		if (init_ == false)
		{
			if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
				Init();
		}
		else
		{
			DinoState* state = state_->Input(event);
			if (state != nullptr)
			{
				delete state_;
				state_ = state;
			}			
		}
	}
}

void Dinosaur::Update(sf::Time elapsed)
{
	if (!init_)
		return;

	DinoState* state = state_->Update(elapsed);
	if (state != nullptr)
	{
		delete state_;
		state_ = state;
	}
}

