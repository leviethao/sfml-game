#ifndef STATE_H
#define STATE_H

#include "SFML\System\Time.hpp"
#include "SFML\Window\Event.hpp"
#include "Identifier.h"

class StateStack;

class State
{
public:
						State(StateStack &stack);
						~State();

	virtual void		draw() = 0;
	virtual bool		update(sf::Time) = 0;
	virtual bool		handleEvent(sf::Event e) = 0;

protected:
	void				requestStackPush(States::ID stateID);
	void				requestStackPop();
	void				requestStackClear();

private:
	StateStack			*mStack;
};

#endif //STATE_H