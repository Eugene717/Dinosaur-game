#include "World.h"

World::World()
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(2, 54, 782, 11));  //1199 - width
    sprite_.setPosition(10, 135);

    sprite2_.setTexture(texture_);
    sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
    sprite2_.setPosition(1209, 135);
}

World::~World()
{ }

void World::Update(sf::Time elapsed)
{
    double time = elapsed.asMilliseconds() * 0.30;

    sf::IntRect rect = sprite_.getTextureRect();

    sprite2_.setPosition(sprite2_.getPosition().x - (int)time, 135);
    if (sprite2_.getPosition().x < 790)
        sprite2_.setTextureRect(sf::IntRect(2, 54, sprite2_.getTextureRect().width + time, 11));

    rect.left += time; //move to next frame

    if (rect.left >= 1201)
    {
        sprite2_.setPosition(1209, 135);
        sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
        rect.left = 2; //move to texture begin
    }

    sprite_.setTextureRect(rect);
}

void World::Render(sf::RenderWindow& window)
{
    window.draw(sprite_);
    window.draw(sprite2_);
}