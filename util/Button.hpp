#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "DynamicObj.hpp"

class Button: public DynamicObj
{
	protected:
		bool pressed = false;
		bool mouse_on(sf::Vector2i mouse_position);
		void press();
		void unpress();
	public:
		Button();
		Button(sf::Drawable *drawble, sf::Transformable* trans, sf::FloatRect bounds,sf::Vector2f position);
		virtual int interact(sf::Vector2i mouse_position);
};