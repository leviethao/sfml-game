#ifndef APPLICATION_H
#define APPLICATION_H

#include "SFML\Graphics.hpp"
#include "World.h"

class Application
{
public:
							Application();
							~Application();
	void					run();
	void					update(sf::Time dt);
	void					render();

private:
	static const sf::Time	TimePerFrame;
	sf::RenderWindow		window;
	World					*mWorld;
};

#endif //APPLICATION_H