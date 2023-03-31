#include "World.h"
#include "Score.h"
#include "Cactus.h"
#include <random>

const int CHANGE_TO_SPAWN_CACTUS = 25;

World::World()
{
	sprite_.setTexture(texture_);
    sprite2_.setTexture(texture_);

    score_ = new Score();

    Init();
}

World::~World()
{
    delete score_;

    for (auto* i : objects_)
    {
        delete i;
    }

    objects_.clear();
}

void World::Init()
{
    score_->Init();

    for (auto it = objects_.begin(); it != objects_.end(); ++it)
    {
		delete (*it);
    }
    objects_.clear();

    sprite_.setPosition(0, 135);
    sprite_.setTextureRect(sf::IntRect(2, 54, 800, 11));
    sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
    sprite2_.setPosition(1200, 135);

    timerToSpawnCactuses_ = 0;
}

void World::SpawnNewObjects()
{
    std::random_device rd;

    static int oldTimeToSpawnCactuses = 0;
    timerToSpawnCactuses_ = score_->GetScore();

    if ((float)(timerToSpawnCactuses_ - oldTimeToSpawnCactuses) / 10.0f > 1.1f)
    {
        if ((rd() % 100) < CHANGE_TO_SPAWN_CACTUS)
        {
            oldTimeToSpawnCactuses = timerToSpawnCactuses_;

            Cactus* c = new Cactus(rd() % 6);
            objects_.push_back(c);
        }
    }
}

void World::DeleteOldObjects()
{
    for (auto it = objects_.begin(); it != objects_.end();)
    {
        if ((*it)->GetSpritePos().x < -100)
        {
            delete (*it);
            it = objects_.erase(it);
        }
        else
            ++it;
    }
}

bool World::CheckCollision(sf::FloatRect rect) const
{
    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
        if ((*i)->CheckCollision(rect))
            return true;
    }

    return false;
}

void World::Update(sf::Time elapsed)
{
    double time = elapsed.asMilliseconds() * 0.30;

    sf::IntRect rect = sprite_.getTextureRect();

    sprite2_.setPosition(sprite2_.getPosition().x - (int)time, 135);
    if (sprite2_.getPosition().x < 800)
        sprite2_.setTextureRect(sf::IntRect(2, 54, sprite2_.getTextureRect().width + time, 11));

    rect.left += time; //move to next frame

    if (rect.left >= 1201)
    {
        sprite2_.setPosition(1200, 135);
        sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
        rect.left = 2; //move to texture begin
    }

    sprite_.setTextureRect(rect);

    score_->Update(elapsed);
    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
		(*i)->Update(elapsed);
    }

    SpawnNewObjects();
    DeleteOldObjects();
}

void World::Render(sf::RenderWindow& window)
{
    score_->Render(window);

    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
        (*i)->Render(window);
    }

    window.draw(sprite_);
    window.draw(sprite2_);
}