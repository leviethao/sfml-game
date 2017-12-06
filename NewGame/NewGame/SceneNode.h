#ifndef SCENENODE_H
#define SCENENODE_H

#include "SFML\Graphics\Drawable.hpp"
#include "SFML\Graphics\Transformable.hpp"
#include "SFML\Graphics.hpp"
#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable
{
public:
								SceneNode();
								~SceneNode();
	void						attachChild(SceneNode *child);
	SceneNode*					detachChild(SceneNode *node);
	void						update(sf::Time dt);
protected:
	virtual void				updateCurrent(sf::Time dt);
	void						updateChildren(sf::Time dt);

	virtual void				draw(sf::RenderTarget &target, sf::RenderStates states) const;
	virtual void				drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
	void						drawChildren(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	SceneNode					*mParent;
	std::vector<SceneNode*>		mChildrens;
};

#endif //SCENENODE_H