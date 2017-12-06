#include "SceneNode.h"

SceneNode::SceneNode()
	: mChildrens()
	, mParent(nullptr)
{
}

SceneNode::~SceneNode()
{
	if (mParent)
		mParent->detachChild(this);
	for (SceneNode *node : mChildrens)
		delete node;
}

void SceneNode::attachChild(SceneNode *child)
{
	child->mParent = this;
	this->mChildrens.push_back(child);
}

SceneNode* SceneNode::detachChild(SceneNode *node)
{
	std::vector<SceneNode*>::iterator found = mChildrens.end();
	for (std::vector<SceneNode*>::iterator it = mChildrens.begin(); it != mChildrens.end(); it++)
		if (*it == node)
			found = it;

	if (found != mChildrens.end())
		mChildrens.erase(found);
	return *found;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
	//do not thing by default
}

void SceneNode::updateChildren(sf::Time dt)
{
	for (SceneNode *node : mChildrens)
		node->update(dt);
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
	// do not thing by default
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
	for (SceneNode *node : mChildrens)
		node->draw(target, states);
}