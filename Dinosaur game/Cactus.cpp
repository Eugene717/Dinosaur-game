#include "Cactus.h"

std::vector<sf::IntRect> Cactus::cactuses_;

Cactus::Cactus(int n)
{
	if (cactuses_.empty())
	{
		cactuses_.push_back(sf::IntRect(332, 2, 25, 49));  //one big cactus
		cactuses_.push_back(sf::IntRect(357, 2, 50, 49));  //two big cactuses
		cactuses_.push_back(sf::IntRect(407, 2, 75, 49));  //four big cactuses
		cactuses_.push_back(sf::IntRect(228, 2, 16, 34));  //one small cactus
		cactuses_.push_back(sf::IntRect(245, 2, 34, 34));  //two small cactuses
		cactuses_.push_back(sf::IntRect(279, 2, 51, 34));  //three small cactuses
	}

	if (n < cactuses_.size())
	{
		sprite_.setTexture(texture_);
		sprite_.setTextureRect(cactuses_[n]);
		if (n < 3)
			sprite_.setPosition(810, 100);
		else
			sprite_.setPosition(810, 113);
	}
}

Cactus::~Cactus()
{ }

void Cactus::Update(sf::Time elapsed)
{
	double time = elapsed.asMilliseconds() * 0.30;

	sprite_.move((int)-time, 0);
}

bool Cactus::CheckCollision(sf::FloatRect rect) const
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
