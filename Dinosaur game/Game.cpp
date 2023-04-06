#include "Game.h"
#include "Entity.h"
#include "Dinosaur.h"
#include "World.h"
#include "Cloud.h"
#include "Star.h"
#include "Moon.h"

Game::Game()
{
	started_ = ended_ = false;

	Entity* dino = new Dinosaur;

	objects_.push_back(dino); 
	
	Entity* world = new World;

	objects_.push_back(world);
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
	dynamic_cast<Dinosaur*>(objects_[0])->Init();
	dynamic_cast<World*>(objects_[1])->Init();
}

void Game::Input(sf::Event& event)
{
	if (!started_)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up)
			{
				Init();
				started_ = true;
				ended_ = false;
			}
		}
	}
	else
		objects_[0]->Input(event);
}

void Game::Update(double elapsed)
{
	if (started_)
	{
		for (int i = 0; i < objects_.size(); i++)
		{
			objects_[i]->Update(elapsed);
		}
		if (objects_[1]->CheckCollision(dynamic_cast<Dinosaur*>(objects_[0])->GetSprite()))
		{
			dynamic_cast<Dinosaur*>(objects_[0])->SetDeadStatus();
			ended_ = true;
			started_ = false;
		}
	}
}

void Game::Render(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);

	if (started_ || ended_)
	{
		objects_[1]->Render(window);

		sf::RectangleShape border;
		border.setFillColor(sf::Color::White);
		border.setSize(sf::Vector2f(10, 200));

		window.draw(border);

		border.setPosition(790, 0);

		window.draw(border);
	}

	objects_[0]->Render(window);

	window.display();
}
