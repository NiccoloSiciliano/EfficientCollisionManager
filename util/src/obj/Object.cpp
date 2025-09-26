#include "../../Object.hpp"

Object::Object()
{

	this->drawble = NULL;
	this->trans = NULL;
}
Object::Object(sf::Drawable *drawble, sf::Transformable* trans, sf::FloatRect bounds,sf::Vector2f position)
{
	this->drawble = drawble;
	this->trans = trans;
	this->trans->setPosition(position);
	this->original_bounds = bounds;
	this->bounds = bounds;
}

void Object::set_position(sf::Vector2f position)
{
	this->trans->setPosition(position);
}

sf::Vector2f Object::get_position()
{
	return this->trans->getPosition();
}

sf::FloatRect Object::get_local_bounds()
{
	return bounds;
}

void Object::set_shape(sf::Drawable *drawble, sf::Transformable* trans)
{
	sf::Vector2f position = trans->getPosition();
	if (this->trans)
		position = this->trans->getPosition();
	this->drawble = drawble;
	this->trans = trans;
	this->trans->setPosition(position);
}
void Object::set_scale(sf::Vector2f scale)
{
	this->bounds.height = original_bounds.height *scale.y;
	this->bounds.width = original_bounds.width *scale.x;

	this->trans->setScale(scale.x, scale.y); 
}

sf::Transformable* Object::get_transformable()
{
	return this->trans;
}

sf::Drawable* Object::get_drawable()
{
	return this->drawble;
}

void Object::draw(sf::RenderWindow * win)
{
	win->draw(*drawble);
}

int Object::get_health()
{
	return 1;
}


Object::~Object()
{
	delete drawble;
}