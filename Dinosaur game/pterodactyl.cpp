#include "pterodactyl.h"

Pterodactyl::Pterodactyl(int heightPos) : firstFrame_(false)
{ 
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(134, 8, 45, 33));

	int y;
	if (heightPos == 0)
		y = 20;
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
			sprite_.setTextureRect(sf::IntRect(134, 8, 45, 33));
			firstFrame_ = false;
		}
		else
		{
			sprite_.setTextureRect(sf::IntRect(180, 2, 45, 29));
			firstFrame_ = true;
		}
		last_ = sf::Time::Zero;
	}
	else
		last_ += elapsed;
}

bool Pterodactyl::CheckCollision(sf::FloatRect rect) const
{
	sf::FloatRect sprite = sprite_.getGlobalBounds();
	sprite.left += 4; sprite.width -= 8;
	sprite.top -= 4; sprite.height -= 8;

	for (int i = 0; i < 13; i++)
	{
		if (sprite.contains(rect.left + rect.width - 5, rect.top + i))
			return true;
	}
	for (int i = 10; i < rect.width - 15; i++)
	{
		if (sprite.contains(rect.left + i, rect.top + rect.height - 5))
			return true;
	}

	return false;
}
