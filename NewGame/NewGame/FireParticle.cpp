#include "FireParticle.h"

FireParticle::FireParticle(sf::Texture &texture)
	: ParticleNode(texture)
{
	std::srand(std::time(NULL));

	setLifeTime(sf::seconds(2.0f));
	for (int i = 0; i < 50; i++)
	{
		addParticle(getPosition());

		int angle = rand() % 360;

		float vx = cos(angle);
		float vy = sin(angle);

		getParticles()[i].setVelocity(vx * 100, vy * 100);
	}
}


void FireParticle::updateCurrent(sf::Time dt)
{

	ParticleNode::updateCurrent(dt);

	//descrease particles velocity
	//setParticlesVelocity(sf::Vector2f(getParticlesVelocity().x  * 0.99, getParticlesVelocity().y * 0.99));

	//gravity effect
	for (Particle &particle : getParticles())
		particle.setVelocity(particle.getVelocity().x, particle.getVelocity().y + 1000 * dt.asSeconds());
}