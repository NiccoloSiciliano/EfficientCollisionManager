#pragma once
#include "./Object.hpp"
#include <SFML/Graphics.hpp>

class DynamicObj: public Object
{
	public:
		int interact(int (*func)(DynamicObj *current));
		virtual void update(sf::Event event);
};