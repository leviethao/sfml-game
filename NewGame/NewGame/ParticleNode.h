#ifndef PARTICLE_NODE_H
#define PARTICLE_NODE_H

#include "Entity.h"
#include "Particle.h"

class ParticleNode : public Entity
{
public:
							ParticleNode(sf::Texture &texture);
	void					addParticle(sf::Vector2f position);
	void					setParticlesVelocity(sf::Vector2f velocity);
	sf::Vector2f			getParticlesVelocity();
	void					setColor(sf::Color color);
	sf::Color				getColor() const;
	sf::Time				getLifeTime() const;
	void					setLifeTime(sf::Time lifeTime);

protected:
	virtual void			updateCurrent(sf::Time dt);
	virtual void			drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

	void					addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color &color) const;
	void					computerVertices() const;
	std::vector<Particle*>&	getParticles();

private:
	std::vector<Particle*>	mParticles;
	const sf::Texture		&mTexture;
	mutable sf::VertexArray	mVertexArray;
	mutable bool			mNeedVertexUpdate;
	sf::Color				mColor;
	sf::Time				mLifeTime;
};


#endif //PARTICLE_NODE_H