#include "World.h"

World::World()
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(2, 54, 782, 11));  //1199
    sprite_.setPosition(10, 135);

    sprite2_.setTexture(texture_);
    sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
    sprite2_.setPosition(1209, 135);
}

World::~World()
{ }

void World::Update()
{
    static sf::Clock clock;
    static sf::Time last;

    sf::Time elapsed = clock.getElapsedTime();

    if ((elapsed - last).asMicroseconds() >= 1)
    {
        sf::IntRect rect = sprite_.getTextureRect();
        sprite2_.setPosition(sprite2_.getPosition().x - 5, 135);
        if (sprite2_.getPosition().x <= 792)
            sprite2_.setTextureRect(sf::IntRect(2, 54, sprite2_.getTextureRect().width + 5, 11));
        rect.left += 5; //move to next frame

        if (rect.left >= 1201) 
        {
            sprite2_.setPosition(1209, 135);
            sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
            rect.left = 2; //move to texture begin
        }

        sprite_.setTextureRect(rect);
        last = elapsed;
    }
}

void World::Render(sf::RenderWindow& window)
{
    window.draw(sprite_);
    window.draw(sprite2_);
}