#ifndef FIREPARTICLE_H
#define FIREPARTICLE_H

#include "ParticleNode.h"

class FireParticle : public ParticleNode
{
public:
							FireParticle(sf::Texture &texture);

protected:
	virtual void			updateCurrent(sf::Time dt);
};

#endif //FIREPARTICLE_H