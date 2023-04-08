#include "World.h"
#include "Score.h"
#include "WorldFactory.h"

World::World()
{
	sprite_.setTexture(texture_);
    sprite2_.setTexture(texture_);

    score_ = new Score();
    speedUp_ = 1;
    
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
    speedUp_ = 1;
    if (factory_ != nullptr)
        delete factory_;
    factory_ = new WorldFactory();

    for (auto it = objects_.begin(); it != objects_.end(); ++it)
    {
		delete (*it);
    }
    objects_.clear();

    sprite_.setPosition(0, 135);
    sprite_.setTextureRect(sf::IntRect(2, 54, 800, 11));
    sprite2_.setTextureRect(sf::IntRect(2, 54, 0, 11));
    sprite2_.setPosition(1200, 135);    
}

void World::SpawnNewObjects()
{
    if (Entity* object = factory_->CreateObject(score_->GetScore()); object != nullptr)
        objects_.push_back(object);
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

bool World::CheckCollision(sf::Sprite* OtherSprite) const
{
    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
        if ((*i)->CheckCollision(OtherSprite))
        {
            score_->SetGameOver();
            return true;
        }
    }

    return false;
}

void World::Update(double elapsed)
{
    score_->Update(elapsed);

    if (score_->GetScore() > 250)
        if (speedUp_ < 2)
            speedUp_ += 0.0005;

    elapsed *= speedUp_;

    double time = elapsed * 0.30;

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

    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
		(*i)->Update(elapsed);
    }

    SpawnNewObjects();
    DeleteOldObjects();
}

void World::Render(sf::RenderWindow& window)
{
    for (auto i = objects_.begin(); i != objects_.end(); i++)
    {
        (*i)->Render(window);
    }

    window.draw(sprite_);
    window.draw(sprite2_);

    score_->Render(window);
}