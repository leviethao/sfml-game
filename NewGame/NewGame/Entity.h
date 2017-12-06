#ifndef ENTITY_H
#define ENTITY_H

#include "SceneNode.h"

class Entity : public SceneNode
{
public:
						Entity();
						~Entity();
	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity();
	void				accelerate(sf::Vector2f velocity);
	void				accelerate(float vx, float vy);

protected:
	virtual void		updateCurrent(sf::Time dt);

private:
	sf::Vector2f		mVelocity;
};

#endif //ENTITY_H