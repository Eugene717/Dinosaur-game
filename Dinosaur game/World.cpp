#include "World.h"
#include "Score.h"
#include <random>

World::World()
{
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(2, 54, 782, 11));  //1200 - width
    sprite_.setPosition(10, 135);

    sprite2_.setTexture(texture_);
    sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
    sprite2_.setPosition(1210, 135);

    spawnTimer_ == sf::Time::Zero;

    Score* score = new Score();
    objects_.push_back(score);
}

World::~World()
{ }

void World::SpawnNewObjects()
{
    std::random_device rd;


}

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
        sprite2_.setPosition(1210, 135);
        sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
        rect.left = 2; //move to texture begin
    }

    sprite_.setTextureRect(rect);

    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
		(*i)->Update(elapsed);
    }

    spawnTimer_ += elapsed;
    SpawnNewObjects();
}

void World::Render(sf::RenderWindow& window)
{
    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
        (*i)->Render(window);
    }

    window.draw(sprite_);
    window.draw(sprite2_);
}