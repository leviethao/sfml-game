#include "Particle.h"

Particle::Particle()
	: mColor(sf::Color::White)
	, mLifeTime(sf::seconds(1.0f))
{
}

Particle::~Particle()
{
}


sf::Color Particle::getColor() const
{
	return this->mColor;
}


sf::Time Particle::getLifeTime() const
{
	return this->mLifeTime;
}


void Particle::setColor(const sf::Color &color)
{
	this->mColor = color;
}


void Particle::setLifeTime(const sf::Time &lifeTime)
{
	this->mLifeTime = lifeTime;
}


void Particle::updateCurrent(sf::Time dt)
{
	Entity::updateCurrent(dt);
	this->move(getVelocity() * dt.asSeconds());
}