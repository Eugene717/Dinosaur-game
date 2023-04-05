#include "pterodactyl.h"
#include "BitmaskManager.h"

Pterodactyl::Pterodactyl(int heightPos) : firstFrame_(false), last_(0)
{ 
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(134, 8, 45, 33));

	if (heightPos == 0)
		heightPos = 30;
	else if (heightPos == 1)
		heightPos = 50;
	else
		heightPos = 80;

	sprite_.setPosition(1300, heightPos);
}

Pterodactyl::~Pterodactyl()
{ }

void Pterodactyl::Update(double elapsed)
{
	if ((last_ += elapsed) >= 200)
	{
		if (firstFrame_)
		{
			sprite_.move(0, 6);
			sprite_.setTextureRect(sf::IntRect(134, 8, 45, 33));
			firstFrame_ = false;
		}
		else
		{
			sprite_.move(0, -6);
			sprite_.setTextureRect(sf::IntRect(180, 2, 45, 29));
			firstFrame_ = true;
		}
		last_ = 0;
	}

	elapsed *= 0.30;

	sprite_.move(-elapsed, 0);
}

bool Pterodactyl::CheckCollision(sf::Sprite* otherSprite) const
{
	return CheckCollisions(otherSprite, &sprite_);
}
