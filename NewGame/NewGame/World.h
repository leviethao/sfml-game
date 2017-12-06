#ifndef WORLD_H
#define WORLD_H

#include "SceneNode.h"
#include "Ball.h"
#include "Fragment.h"

class World
{
public:
								World(sf::RenderTarget &target);
								~World();
	void						init();
	void						update(sf::Time dt);
	void						draw();
	//void						spawnFragment();
private:
	SceneNode					*mSceneGraph;
	sf::FloatRect				*mWorldBound;
	sf::Font					*mFont;
	sf::Text					*mTxtScore;
	sf::Texture					*mTopEdge;
	sf::Sprite					*mSpriteTop;
	sf::RenderTarget			&mTarget;
	sf::Texture					*mBgTexture;
	sf::Sprite					*mBackground;
	Ball						*ball;
	std::vector<Fragment*>		mFragments;
};

#endif //WORLD_H