#include "Game.h"
#include "Entity.h"
#include "Dinosaur.h"
#include "World.h"
#include "Cactus.h"
#include "Pterodactyl.h"
#include "Score.h"
#include "Cloud.h"
#include "Star.h"
#include "Moon.h"

Game::Game()
{
	started_ = false;

	Entity* dino = new Dinosaur;

	objects_.push_back(dino);
}

Game::~Game()
{
	while (objects_.size() != 0)
	{
		delete objects_.back();
		objects_.pop_back();
	}
}

void Game::Init()
{
	Entity* world = new World;
	objects_.push_back(world);
}

void Game::Input(sf::Event& event)
{
	if (!started_)
		if (event.type == sf::Event::KeyPressed)
		{
			started_ = true;
			Init();
		}

	objects_[0]->Input(event);
}

void Game::Update()
{
	if (started_)
		for (int i = 0; i < objects_.size(); i++)
		{
			objects_[i]->Update();
		}
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);

	for (int i = 0; i < objects_.size(); i++)
	{
		objects_[i]->Render(window);
	}

	window.display();
}
