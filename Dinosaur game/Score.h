#pragma once
#include "Entity.h"

class Score : public Entity
{
	int score_, HIScore_;
	bool gameEnded_;
	std::vector<sf::Sprite> numSprites_;
	std::vector<std::pair<int, sf::Vector2f>> numbers_;
	sf::Sprite gameOver_;
public:
	Score();
	~Score();
	int GetScore() const;
	void SetGameOver();
	void Init();
	void Update(double elapsed) override;
	void Render(sf::RenderWindow& window) override;
};

