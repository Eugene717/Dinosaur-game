#include "Star.h"

Star::Star(int n, int heightPos)
{
	sprite_.setTexture(texture_);

	if (n == 0)
		sprite_.setTextureRect(sf::IntRect(644, 2, 9, 9));
	else if (n == 1)
		sprite_.setTextureRect(sf::IntRect(644, 11, 9, 9));
	else if (n == 2)
		sprite_.setTextureRect(sf::IntRect(644, 20, 9, 9));

	if (heightPos == 0)
		heightPos = 10;
	else if (heightPos == 1)
		heightPos = 20;
	else if (heightPos == 2)
		heightPos = 25;
	else if (heightPos == 3)
		heightPos = 35;
	else if (heightPos == 4)
		heightPos = 50;

	sprite_.setPosition(810, heightPos);
}

Star::~Star()
{ }

void Star::Update(double elapsed)
{
	elapsed *= 0.050;

	sprite_.move(-elapsed, 0);
}
