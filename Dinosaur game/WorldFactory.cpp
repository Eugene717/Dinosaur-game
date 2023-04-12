#include "WorldFactory.h"
#include "Entity.h"
#include "Cactus.h"
#include "Pterodactyl.h"
#include "Cloud.h"
#include "Star.h"
#include "Moon.h"

enum Timers
{
	cactus,
	pterodactyl,
	cloud,
	star,
	moon
};

const int CHANGE_TO_SPAWN_CACTUS = 95;
const int CHANGE_TO_SPAWN_PTERODACTYL = 5;
const int CHANGE_TO_SPAWN_CLOUD = 10;
const int CHANGE_TO_SPAWN_STAR = 5;

WorldFactory::WorldFactory()
{
    std::random_device rd;
    rd_.seed(rd());

	for (int i = 0; i < 5; i++)
	{
		timers_.push_back(0);
	}
}

Entity* WorldFactory::CreateCactus(const int elapsed)
{
    if ((elapsed - timers_[pterodactyl] > 30 || timers_[pterodactyl] == 0) && (elapsed - timers_[cactus]) > 10 )
        if ((rd_() % 100) < CHANGE_TO_SPAWN_CACTUS)
        {
            timers_[cactus] = elapsed;

            int random = rd_() % 100;

            if (random < 30)
                return new Cactus(0);
            else if (random >= 30 && random < 55)
                return new Cactus(1);
            else if (random >= 55 && random < 60)
                return new Cactus(2);
            else if (random >= 60 && random < 75)
                return new Cactus(3);
            else if (random >= 75 && random < 90)
                return new Cactus(4);
            else if (random >= 90 && random < 100)
                return new Cactus(5);
        }

    return nullptr;
}

Entity* WorldFactory::CreatePterodactyl(const int elapsed)
{
    if (elapsed > 0)
        if (elapsed - timers_[pterodactyl] > 30 && elapsed - timers_[cactus] > 10)
            if ((rd_() % 100) < CHANGE_TO_SPAWN_PTERODACTYL)
            {
                timers_[pterodactyl] = elapsed;

                return new Pterodactyl(rd_() % 3);
            }

    return nullptr;
}

Entity* WorldFactory::CreateCloud(const int elapsed)
{
    if (elapsed - timers_[cloud] > 70)
        if ((rd_() % 100) < CHANGE_TO_SPAWN_CLOUD)
        {
            timers_[cloud] = elapsed;

            return new Cloud(rd_() % 5);
        }

	return nullptr;
}

Entity* WorldFactory::CreateStar(const int elapsed)
{


	return nullptr;
}

Entity* WorldFactory::CreateMoon(const int elapsed)
{


	return nullptr;
}

Entity* WorldFactory::CreateObject(const int elapsed)
{
    if (Entity* object = CreatePterodactyl(elapsed); object != nullptr)
        return object;
    if (Entity* object = CreateCactus(elapsed); object != nullptr)
        return object;
    if (Entity* object = CreateCloud(elapsed); object != nullptr)
        return object;
    if (Entity* object = CreateStar(elapsed); object != nullptr)
        return object;
    if (Entity* object = CreateMoon(elapsed); object != nullptr)
        return object;   

    return nullptr;
}
