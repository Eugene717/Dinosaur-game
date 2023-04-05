#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class BitmaskManager
{
	std::map<const sf::Texture*, sf::Uint8*> Bitmasks_;
public:
	~BitmaskManager();
	sf::Uint8 GetPixel(const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y);
	sf::Uint8* GetMask(const sf::Texture* tex);
	sf::Uint8* CreateMask(const sf::Texture* tex, const sf::Image& img);
};

bool CheckCollisions(const sf::Sprite* sprite1, const sf::Sprite* sprite2, sf::Uint8 alphaLimit = 0);
