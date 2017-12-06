#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML\System\Vector2.hpp"
#include "SFML\System\Time.hpp"
#include "SFML\Graphics\Color.hpp"
#include "Entity.h"

class Particle : public Entity
{
public:
								Particle();
								~Particle();

	sf::Color					getColor() const;
	sf::Time					getLifeTime() const;
	void						setColor(const sf::Color &color);
	void						setLifeTime(const sf::Time &lifeTime);

private:
	virtual void				updateCurrent(sf::Time dt);

private:
	sf::Color					mColor;
	sf::Time					mLifeTime;
};

#endif // PARTICLE_H