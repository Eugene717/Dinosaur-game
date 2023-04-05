#include "BitmaskManager.h"

BitmaskManager::~BitmaskManager()
{
	std::map<const sf::Texture*, sf::Uint8*>::const_iterator end = Bitmasks_.end();
	for (std::map<const sf::Texture*,sf::Uint8*>::const_iterator iter = Bitmasks_.begin(); iter != end; iter++)
	{
		delete[] iter->second;
	}
}

sf::Uint8 BitmaskManager::GetPixel(const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y) 
{
	if (x > tex->getSize().x || y > tex->getSize().y)
		return 0;

	return mask[x + y * tex->getSize().x];
}

sf::Uint8* BitmaskManager::GetMask(const sf::Texture* tex)
{
	sf::Uint8* mask;
	std::map<const sf::Texture*, sf::Uint8*>::iterator pair = Bitmasks_.find(tex);
	if (pair == Bitmasks_.end())
	{
		sf::Image img = tex->copyToImage();
		mask = CreateMask(tex, img);
	}
	else
		mask = pair->second;

	return mask;
}

sf::Uint8* BitmaskManager::CreateMask(const sf::Texture* tex, const sf::Image& img) 
{
	sf::Uint8* mask = new sf::Uint8[tex->getSize().y * tex->getSize().x];

	for (unsigned int y = 0; y < tex->getSize().y; y++)
	{
		for (unsigned int x = 0; x < tex->getSize().x; x++)
			mask[x + y * tex->getSize().x] = img.getPixel(x, y).a;
	}

	Bitmasks_.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex, mask));

	return mask;
}

BitmaskManager Bitmasks;

bool CheckCollisions(const sf::Sprite* sprite1, const sf::Sprite* sprite2, sf::Uint8 alphaLimit)
{
	sf::FloatRect Intersection;
	if (sprite1->getGlobalBounds().intersects(sprite2->getGlobalBounds(), Intersection)) {
		sf::IntRect O1SubRect = sprite1->getTextureRect();
		sf::IntRect O2SubRect = sprite2->getTextureRect();

		sf::Uint8* mask1 = Bitmasks.GetMask(sprite1->getTexture());
		sf::Uint8* mask2 = Bitmasks.GetMask(sprite2->getTexture());

		// Loop through our pixels
		for (int i = Intersection.left; i < Intersection.left + Intersection.width; i++) 
		{
			for (int j = Intersection.top; j < Intersection.top + Intersection.height; j++)
			{

				sf::Vector2f o1v = sprite1->getInverseTransform().transformPoint(i, j);
				sf::Vector2f o2v = sprite2->getInverseTransform().transformPoint(i, j);

				// Make sure pixels fall within the sprite's subrect
				if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
					o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
					o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

					if (Bitmasks.GetPixel(mask1, sprite1->getTexture(), (int)(o1v.x) + O1SubRect.left, (int)(o1v.y) + O1SubRect.top) > alphaLimit &&
						Bitmasks.GetPixel(mask2, sprite2->getTexture(), (int)(o2v.x) + O2SubRect.left, (int)(o2v.y) + O2SubRect.top) > alphaLimit)
						return true;

				}
			}
		}
	}
	return false;
}
