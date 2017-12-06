#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{

}

void Entity::setVelocity(sf::Vector2f velocity)
{
	this->mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	this->mVelocity.x = vx;
	this->mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity()
{
	return this->mVelocity;
}

void Entity::updateCurrent(sf::Time dt)
{
	//do not thing by default
}

void Entity::accelerate(sf::Vector2f velocity)
{
	this->mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
	this->mVelocity.x = vx;
	this->mVelocity.y = vy;
}
