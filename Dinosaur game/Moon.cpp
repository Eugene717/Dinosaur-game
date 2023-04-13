#include "Moon.h"

Moon::Moon(int n)
{
	sprite_.setTexture(texture_);

	if (n == 0)
		sprite_.setTextureRect(sf::IntRect(484, 2, 20, 40));
	else if (n == 1)
		sprite_.setTextureRect(sf::IntRect(504, 2, 20, 40));
	else if (n == 2)
		sprite_.setTextureRect(sf::IntRect(524, 2, 20, 40));
	else if (n == 3)
		sprite_.setTextureRect(sf::IntRect(544, 2, 20, 40));
	else if (n == 4)
		sprite_.setTextureRect(sf::IntRect(564, 2, 20, 40));
	else if (n == 5)
		sprite_.setTextureRect(sf::IntRect(584, 2, 20, 40));
	else if (n == 6)
		sprite_.setTextureRect(sf::IntRect(604, 2, 20, 40));
	else if (n == 7)
		sprite_.setTextureRect(sf::IntRect(624, 2, 20, 40));

	sprite_.setPosition(810, 5);
}

Moon::~Moon()
{ }

void Moon::Update(double elapsed)
{
	elapsed *= 0.025;

	sprite_.move(-elapsed, 0);
}
