#include "World.h"


World::World()
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(0, 54, 780, 11));  //1202
    sprite_.setPosition(10, 133);

    sprite2_.setTexture(texture_);
    sprite2_.setTextureRect(sf::IntRect(0, 54, 0, 11));
    sprite2_.setPosition(1212, 133);
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
        sprite2_.setPosition(sprite2_.getPosition().x - 5, 133);
        if (sprite2_.getPosition().x <= 790)
            sprite2_.setTextureRect(sf::IntRect(0, 54, sprite2_.getTextureRect().width + 5, 11));
        rect.left += 5; //move to next frame

        if (rect.left >= texture_.getSize().x) 
        {
            sprite2_.setPosition(1212, 133);
            sprite2_.setTextureRect(sf::IntRect(0, 54, 0, 11));
            rect.left = 0; //move to texture begin
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