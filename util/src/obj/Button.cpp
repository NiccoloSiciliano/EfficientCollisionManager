#include "../../Button.hpp"

Button::Button()
{
	this->drawble = NULL;
	this->trans = NULL;
}
Button::Button(sf::Drawable *drawble, sf::Transformable* trans, sf::FloatRect bounds,sf::Vector2f position)
{
	this->drawble = drawble;
	this->trans = trans;
	this->trans->setPosition(position);
	this->original_bounds = bounds;
	this->bounds = bounds;

}

bool Button::mouse_on(sf::Vector2i mouse_position)
{
	float my_x = get_position().x, my_y = get_position().y;
	float x_m = mouse_position.x, y_m = mouse_position.y;
	int dist = sqrt(pow(my_x- x_m,2) + pow(my_y - y_m, 2));
	float width = bounds.width, height = bounds.height;
	return (x_m > my_x && x_m < my_x+width  && y_m > my_y && y_m < my_y+height);
}
void Button::press()
{
	pressed = true;
}

void Button::unpress()
{
	pressed = false;
}

int Button::interact(sf::Vector2i mouse_position)
{
	return mouse_on(mouse_position);

}