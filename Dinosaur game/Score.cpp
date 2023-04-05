#include "Score.h"

Score::Score() : score_(0), HIScore_(0)
{
	if (numbers_.empty())
	{
		sf::Sprite zero;
		zero.setTexture(texture_);
		zero.setTextureRect(sf::IntRect(655, 2, 8, 10));
		zero.setPosition(-100, 0);
		
		sf::Sprite one;
		one.setTexture(texture_);
		one.setTextureRect(sf::IntRect(665, 2, 9, 10));
		one.setPosition(-100, 0);
		
		sf::Sprite two;
		two.setTexture(texture_);
		two.setTextureRect(sf::IntRect(675, 2, 9, 10));
		two.setPosition(-100, 0);
		
		sf::Sprite three;
		three.setTexture(texture_);
		three.setTextureRect(sf::IntRect(685, 2, 9, 10));
		three.setPosition(-100, 0);
		
		sf::Sprite four;
		four.setTexture(texture_);
		four.setTextureRect(sf::IntRect(695, 2, 9, 10));
		four.setPosition(-100, 0);
		
		sf::Sprite five;
		five.setTexture(texture_);
		five.setTextureRect(sf::IntRect(705, 2, 9, 10));
		five.setPosition(-100, 0);
		
		sf::Sprite six;
		six.setTexture(texture_);
		six.setTextureRect(sf::IntRect(715, 2, 9, 10));
		six.setPosition(-100, 0);
		
		sf::Sprite seven;
		seven.setTexture(texture_);
		seven.setTextureRect(sf::IntRect(725, 2, 9, 10));
		seven.setPosition(-100, 0);
		
		sf::Sprite eight;
		eight.setTexture(texture_);
		eight.setTextureRect(sf::IntRect(735, 2, 9, 10));
		eight.setPosition(-100, 0);
		
		sf::Sprite nine;
		nine.setTexture(texture_);
		nine.setTextureRect(sf::IntRect(745, 2, 9, 10));
		nine.setPosition(-100, 0);


		numSprites_.push_back(zero);
		numSprites_.push_back(one);
		numSprites_.push_back(two);
		numSprites_.push_back(three);
		numSprites_.push_back(four);
		numSprites_.push_back(five);
		numSprites_.push_back(six);
		numSprites_.push_back(seven);
		numSprites_.push_back(eight);
		numSprites_.push_back(nine);
	}

	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(755, 2, 19, 10));
	sprite_.setPosition(650, 10);

	Init();	
}

void Score::Init()
{
	HIScore_ = score_;
	score_ = 0;

	numbers_.clear();

	numbers_.push_back(std::make_pair<int, sf::Vector2f>(HIScore_ / 10000, sf::Vector2f(680, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(HIScore_ % 10000 / 1000, sf::Vector2f(690, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(HIScore_ % 1000 / 100, sf::Vector2f(700, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(HIScore_ % 100 / 10, sf::Vector2f(710, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(HIScore_ % 10, sf::Vector2f(720, 10)));

	numbers_.push_back(std::make_pair<int, sf::Vector2f>(score_ / 10000, sf::Vector2f(740, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(score_ % 10000 / 1000, sf::Vector2f(750, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(score_ % 1000 / 100, sf::Vector2f(760, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(score_ % 100 / 10, sf::Vector2f(770, 10)));
	numbers_.push_back(std::make_pair<int, sf::Vector2f>(score_ % 10, sf::Vector2f(780, 10)));
}

Score::~Score()
{ }

int Score::GetScore() const
{
	return score_;
}

void Score::Update(double elapsed)
{
	static double last;
	last += elapsed;

	if (last < 90)
		return;

	last = 0;

	++score_;
	
	numbers_[5].first = score_ / 10000;
	numbers_[6].first = score_ % 10000 / 1000;
	numbers_[7].first = score_ % 1000 / 100;
	numbers_[8].first = score_ % 100 / 10;
	numbers_[9].first = score_ % 10;
}

void Score::Render(sf::RenderWindow& window)
{
	window.draw(sprite_);

	for (int i = 0; i < numbers_.size(); i++)
	{
		numSprites_[numbers_[i].first].setPosition(numbers_[i].second);
		window.draw(numSprites_[numbers_[i].first]);
	}
}
