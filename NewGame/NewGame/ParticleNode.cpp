#include "ParticleNode.h"

ParticleNode::ParticleNode(sf::Texture &texture)
	: mTexture(texture)
	, mParticles()
	, mVertexArray(sf::Quads)
	, mNeedVertexUpdate(true)
	, mColor(sf::Color::Yellow)
	, mLifeTime(sf::seconds(0.5f))
{
}

void ParticleNode::setColor(sf::Color color)
{
	this->mColor = color;
}

sf::Color ParticleNode::getColor() const
{
	return this->mColor;
}

void ParticleNode::setLifeTime(sf::Time lifeTime)
{
	this->mLifeTime = lifeTime;
}

sf::Time ParticleNode::getLifeTime() const
{
	return this->mLifeTime;
}

void ParticleNode::addParticle(sf::Vector2f position)
{
	Particle *particle = new Particle();
	particle->setPosition(position);
	particle->setColor(mColor);
	particle->setLifeTime(mLifeTime);
	mParticles.push_back(particle);
}

void ParticleNode::setParticlesVelocity(sf::Vector2f velocity)
{
	for (Particle *particle : mParticles)
		particle->setVelocity(velocity);
}

sf::Vector2f ParticleNode::getParticlesVelocity()
{
	return mParticles.empty() ? sf::Vector2f() : mParticles[0]->getVelocity();
}

std::vector<Particle*>& ParticleNode::getParticles()
{
	return this->mParticles;
}

void ParticleNode::updateCurrent(sf::Time dt)
{
	//remove particle at beginning
	while (!mParticles.empty() && mParticles.front()->getLifeTime() <= sf::Time::Zero)
	{
		Particle *temp = *(mParticles.begin());
		mParticles.erase(mParticles.begin());
		delete temp;
	}

	for (Particle *particle : mParticles)
	{
		//descrease life time of existing particle
		particle->setLifeTime(particle->getLifeTime() - dt);

		//update particle
		particle->update(dt);
	}

	mNeedVertexUpdate = true;
}

void ParticleNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (mNeedVertexUpdate)
	{
		computerVertices();
		mNeedVertexUpdate = false;
	}

	states.texture = &mTexture;

	target.draw(mVertexArray, states);
}

void ParticleNode::addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color &color) const
{
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(worldX, worldY);
	vertex.color = color;
	vertex.texCoords = sf::Vector2f(texCoordX, texCoordY);
	mVertexArray.append(vertex);
}

void ParticleNode::computerVertices() const
{
	sf::Vector2f size(mTexture.getSize());
	sf::Vector2f half = size / 2.f;
	mVertexArray.clear();

	for (const Particle *particle : mParticles)
	{
		sf::Vector2f pos = particle->getPosition();
		sf::Color color = particle->getColor();

		float ratio = particle->getLifeTime().asSeconds() / 1.f;

		color.a = static_cast<sf::Uint8> (255 * std::max(ratio, 0.f));

		addVertex(pos.x - half.x, pos.y - half.y, 0, 0, color);
		addVertex(pos.x + half.x, pos.y - half.y, size.x, 0, color);
		addVertex(pos.x + half.x, pos.y + half.y, size.x, size.y, color);
		addVertex(pos.x - half.x, pos.y + half.y, 0, size.y, color);
	}
}