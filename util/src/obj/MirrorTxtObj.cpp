#include "../../MirrorTxtObj.hpp"

MirrorTxtObj::MirrorTxtObj(sf::Text *text_sp, float* scale_x,float* scale_y, float* x, float* y, float* angle, int* health, char* text)
{
	this->drawble = text_sp;
	this->trans = text_sp;
	this->x = x;
	this->y = y;
	this->angle = angle;
	this->scale_x = scale_x;
	this->scale_y = scale_y;
	this->health = health;
	this->trans->setScale(*scale_x, *scale_y);
	this->text_sp = text_sp;
	this->text = text;
}

void MirrorTxtObj::update(sf::Event event)
{
	trans->setPosition(sf::Vector2f(*x, *y));
	trans->setRotation(*angle);
	trans->setScale(*scale_x, *scale_y);
	text_sp->setString(this->text);
}