#pragma once
#include <random>

class Entity;

class WorldFactory
{
	std::default_random_engine rd_;
	std::vector<int> timers_;  //old time to respawn objects after time

	Entity* CreateCactus(const int elapsed);
	Entity* CreatePterodactyl(const int elapsed);
	Entity* CreateCloud(const int elapsed);
	Entity* CreateStar(const int elapsed);
	Entity* CreateMoon(const int elapsed);
public:
	WorldFactory();

	Entity* CreateObject(const int elapsed);
};

