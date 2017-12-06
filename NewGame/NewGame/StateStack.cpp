#include "StateStack.h"

StateStack::StateStack()
	: mStack()
{
}

StateStack::~StateStack()
{
}

void StateStack::update(sf::Time dt)
{
	for (auto it = mStack.rbegin(); it != mStack.rend(); it++)
		if (!(*it)->update(dt))
			break;
}

void StateStack::pushState(States::ID stateID)
{
	
}