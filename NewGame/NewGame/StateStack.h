#ifndef STATESTACK_H
#define STATESTACK_H

#include "State.h"
#include "SFML\System\Time.hpp"
#include "SFML\Window\Event.hpp"
#include <vector>

class StateStack
{
public:
	StateStack();
	~StateStack();

	enum Action
	{
		Push,
		Pop,
		Clear
	};

	void					update(sf::Time dt);
	void					draw();
	void					handleEvent(const sf::Event &e);

	void					pushState(States::ID stateID);
	void					popState();
	void					clearStates();
	bool					isEmpty() const;

private:
	std::vector<State*>		mStack;
};

#endif // STATESTACK_H