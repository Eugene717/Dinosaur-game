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
	Entity* dino = new Dinosaur();

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

void Game::Input(sf::Keyboard::Key key)
{

}

void Game::Update()
{

}

void Game::Render(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);

	for (int i = 0; i < objects_.size(); i++)
	{
		objects_[i]->Render();
	}

	window.display();
}
