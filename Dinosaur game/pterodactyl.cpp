#include "pterodactyl.h"
#include "BitmaskManager.h"

Pterodactyl::Pterodactyl(int heightPos) : firstFrame_(false)
{ 
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(134, 8, 45, 33));

	int y;
	if (heightPos == 0)
		y = 30;
	else if (heightPos == 1)
		y = 50;
	else
		heightPos = 80;

	sprite_.setPosition(1300, heightPos);
}

Pterodactyl::~Pterodactyl()
{ }

void Pterodactyl::Update(sf::Time elapsed)
{
	double time = elapsed.asMilliseconds() * 0.30;

	sprite_.move(-time, 0);

	if (last_.asMilliseconds() + elapsed.asMilliseconds() >= 100)
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
		last_ = sf::Time::Zero;
	}
	else
		last_ += elapsed;
}

bool Pterodactyl::CheckCollision(sf::Sprite* otherSprite) const
{
	return CheckCollisions(otherSprite, &sprite_);
}
