#include "../../DynamicObj.hpp"

int DynamicObj::interact(int (*func)(DynamicObj *current))
{
	return func(this);
}

void DynamicObj::update(sf::Event event)
{
}