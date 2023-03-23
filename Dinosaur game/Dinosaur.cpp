#include "Dinosaur.h"

Dinosaur::Dinosaur()
{
	init_ = jump_ = crouch_ = false;

	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(40, 4, 43, 44));
	sprite_.setPosition(50, 100);
}

Dinosaur::~Dinosaur()
{ }

void Dinosaur::Init()
{
	jump_ = true;
	
	init_ = true;
}

void Dinosaur::Input(sf::Event& event)
{	
	if (event.type == sf::Event::KeyPressed)
	{
		if (init_ == false)
		{
			if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
				Init();
		}
		else
		{
			if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
				jump_ = true;
			if (event.key.code == sf::Keyboard::Down)
				crouch_ = true;
		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
			jump_ = false;
		if (event.key.code == sf::Keyboard::Down)
			crouch_ = false;
	}
}

void Dinosaur::Update()
{
	if (init_)
	{

	}
}

void Dinosaur::Jump()
{

}
