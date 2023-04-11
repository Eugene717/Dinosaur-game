#include "Cloud.h"

Cloud::Cloud(int heightPos)
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(86, 2, 46, 13));

	if (heightPos == 0)
		heightPos = 10;
	else if (heightPos == 1)
		heightPos = 25;
	else if (heightPos == 2)
		heightPos = 30;
	else if (heightPos == 3)
		heightPos = 40;
	else if (heightPos == 4)
		heightPos = 55;

	sprite_.setPosition(810, heightPos);
}

Cloud::~Cloud()
{ }

void Cloud::Update(double elapsed)
{
	elapsed *= 0.075;

	sprite_.move(-elapsed, 0);
}
