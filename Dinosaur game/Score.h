#pragma once
#include "Entity.h"

class Score : public Entity
{
	int score_, HIScore_;
	std::vector<sf::Sprite> numSprites_;
	std::vector<std::pair<int, sf::Vector2f>> numbers_;
public:
	Score();
	~Score();
	void Init();
	int GetScore() const;
	void Update(sf::Time elapsed) override;
	void Render(sf::RenderWindow& window) override;
};

