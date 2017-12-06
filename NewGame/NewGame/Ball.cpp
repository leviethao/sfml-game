#include "Ball.h"
#include "Constant.h"
#include <iostream>
#include "Utilities.h"

sf::Sound sound;
sf::Color colors[] = {sf::Color::Blue, sf::Color::Red, sf::Color::Cyan, sf::Color::Green, sf::Color::Magenta, sf::Color::White, sf::Color::Yellow};
extern int score;

Ball::Ball()
	: mColorIndex(0)
	, mParticlesSpeed(100)
	, isCollision(false)
{
	mShape = new sf::CircleShape(20);
	mShape->setFillColor(sf::Color::Yellow);
	mShape->setOrigin(mShape->getLocalBounds().width / 2, mShape->getLocalBounds().height / 2);

	if (!mSoundBuffer.loadFromFile("ballhit.wav"))
		printf("load sound fail\n");

	sound.setBuffer(mSoundBuffer);

	// attach particle system
	mParticleTexture = new	sf::Texture();
	if (!mParticleTexture->loadFromFile("images/Particle.png"))
		std::cout << "particle image not found!" << std::endl;
	mParticleSystem = new ParticleNode(*mParticleTexture);

	this->attachChild(mParticleSystem);
}


Ball::~Ball() 
{
	delete mShape;
	delete mParticleSystem;
	delete mParticleTexture;
}


void Ball::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*mShape, states);
}


void Ball::updateCurrent(sf::Time dt)
{
	Entity::updateCurrent(dt); //

	//move ball and change color
	this->move(getVelocity() * dt.asSeconds());
	boundWall();
	mShape->setFillColor(colors[mColorIndex]);

	//spaw particle
	for (int i = 0; i < 5; i++)
		mParticleSystem->addParticle(sf::Vector2f());

	//update velocity of particles
	sf::Vector2f particleVector = Normalize(this->getVelocity());
	mParticleSystem->setParticlesVelocity(sf::Vector2f(particleVector.x * -1 * mParticlesSpeed, particleVector.y * -1 * mParticlesSpeed));

	//update color particle system
	mParticleSystem->setColor(mShape->getFillColor());
}


void Ball::boundWall()
{
	isCollision = false;

	sf::Vector2f position = this->getPosition();
	float radius = this->mShape->getRadius();
	
	//collision verticle edge
	if (position.x - radius <= mWorldBound.left || position.x + radius >= mWorldBound.width)
	{
		int positionX = position.x - radius <= mWorldBound.left ? mWorldBound.left + mShape->getRadius() + 1 : mWorldBound.width - 1 - mShape->getRadius();
		this->setPosition(positionX, getPosition().y);
		this->setVelocity(-1 * this->getVelocity().x, this->getVelocity().y);
		isCollision = true;
	}
	
	//collision horizontal edge
	if (position.y - radius <= mWorldBound.top || position.y + radius >= mWorldBound.height)
	{
		int positionY = position.y - radius <= mWorldBound.top ? mWorldBound.top + mShape->getRadius() + 1 : mWorldBound.height - 1 - mShape->getRadius();
		this->setPosition(getPosition().x, positionY);
		this->setVelocity(this->getVelocity().x, -1 * this->getVelocity().y);
		isCollision = true;
	}

	//
	if (isCollision)
	{
		sound.play();
		mColorIndex = (mColorIndex + 1) % (sizeof(colors) / sizeof(sf::Color));
		score++;
	}
}

void Ball::setWorldBound(sf::FloatRect worldBound)
{
	mWorldBound = worldBound;
}


sf::Color Ball::getColor() const
{
	return mShape->getFillColor();
}