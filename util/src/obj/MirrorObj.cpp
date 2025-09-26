#include "../../MirrorObj.hpp"

MirrorObj::MirrorObj(sf::Drawable *drawble, sf::Transformable* trans, float* scale_x,float* scale_y, float* x, float* y, float* angle, int* health)
{
	this->drawble = drawble;
	this->trans = trans;
	this->x = x;
	this->y = y;
	this->angle = angle;
	this->scale_x = scale_x;
	this->scale_y = scale_y;
	this->health = health;
	this->trans->setScale(*scale_x, *scale_y);
}

void MirrorObj::update(sf::Event event)
{

	trans->setPosition(sf::Vector2f(*x, *y));
	trans->setRotation(*angle);
	trans->setScale(*scale_x, *scale_y);
}

int MirrorObj::get_health()
{
	return *health;
}
