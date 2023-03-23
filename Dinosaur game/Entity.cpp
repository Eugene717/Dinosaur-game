#include "Entity.h"

bool Entity::loadedTexture_ = false;
sf::Texture Entity::texture_;

Entity::Entity()
{
	if (!loadedTexture_)
	{
		loadedTexture_ = true;
		texture_.loadFromFile("Resourses/dinosaur_game_sprites.png");
	}
}

Entity::~Entity()
{ }

void Entity::Input(sf::Event& event)
{ }

void Entity::Render(sf::RenderWindow& window)
{
	window.draw(sprite_);
}
