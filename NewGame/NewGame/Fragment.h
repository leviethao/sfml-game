#ifndef FRAGMENT_H
#define FRAGMENT_H

#include "Entity.h"
#include "SFML\Graphics.hpp"
#include <vector>

class Fragment : public Entity
{
public:
										Fragment(sf::Vector2f position, sf::Time lifeTime, sf::Color color);
										~Fragment();
	virtual void						updateCurrent(sf::Time dt);
	virtual void						drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Time							getLifeTime() const;

private:
	void								spawn(sf::Vector2f position);

private:
	std::vector<sf::CircleShape*>		mFragments;	
	sf::Time							mLifeTime;
	sf::Color							mColor;
};

#endif //FRAGMENT_H