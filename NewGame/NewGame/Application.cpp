#include "Application.h"
#include "Constant.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.0 / 60);

Application::Application()
	: window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "New Game")
{
	mWorld = new World(window);
	mWorld->init();
}

Application::~Application()
{
	delete mWorld;
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		if (timeSinceLastUpdate >= TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			update(TimePerFrame);
			render();
		}

		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
	}

}

void Application::update(sf::Time dt)
{
	mWorld->update(dt);
}

void Application::render()
{
	window.clear(sf::Color::Black);
	mWorld->draw();
	window.display();
}