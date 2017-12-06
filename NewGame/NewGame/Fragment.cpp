#include "Fragment.h"

const int NUM_INSTANCE = 5;
const float SPEED = 50.0f;
const int MIN_RADIUS = 3;
sf::Time LIFE_TIME_MAX;

Fragment::Fragment(sf::Vector2f position, sf::Time lifeTime, sf::Color color)
{
	mLifeTime = lifeTime;
	LIFE_TIME_MAX = lifeTime;
	mColor = color;
	spawn(position);
}

Fragment::~Fragment()
{
	for (auto fragment : mFragments)
		delete fragment;
}

void Fragment::updateCurrent(sf::Time dt)
{
	//Entity::updateCurrent(dt);

	mLifeTime -= dt;

	for (auto shape : mFragments)
	{
		shape->setPosition(shape->getPosition().x, shape->getPosition().y + SPEED * dt.asSeconds());
		shape->setFillColor(sf::Color(mColor.r, mColor.g, mColor.b, mColor.a * (mLifeTime.asSeconds() / LIFE_TIME_MAX.asSeconds())));
	}

}

void Fragment::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (auto shape : mFragments)
		target.draw(*shape, states);
}

void Fragment::spawn(sf::Vector2f position)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < NUM_INSTANCE; i++)
	{
		sf::CircleShape *shape =  new sf::CircleShape(MIN_RADIUS + rand() % (MIN_RADIUS + 5));
		shape->setPosition(position.x -20 + rand() % 41, position.y -20 + rand() % 41);
		shape->setFillColor(mColor);
		mFragments.push_back(shape);
	}
}

sf::Time Fragment::getLifeTime() const
{
	return mLifeTime;
}