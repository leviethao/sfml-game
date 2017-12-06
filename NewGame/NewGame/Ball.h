#ifndef BALL_H
#define BALL_H

#include "Entity.h"
#include "Utilities.h"
#include "ParticleNode.h"

class Ball : public Entity
{
public:
									Ball();
									~Ball();
	virtual void					drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual void					updateCurrent(sf::Time dt);
	void							boundWall();
	void							setWorldBound(sf::FloatRect worldBound);
	bool							isCollision;
	sf::Color						getColor() const;

private:
	sf::CircleShape					*mShape;
	sf::SoundBuffer					mSoundBuffer;
	int								mColorIndex;
	ParticleNode					*mParticleSystem;
	sf::Texture						*mParticleTexture;
	float							mParticlesSpeed;
	sf::FloatRect					mWorldBound;
};

#endif //BALL_H