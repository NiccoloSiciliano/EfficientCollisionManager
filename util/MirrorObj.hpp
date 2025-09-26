#pragma once
#include "DynamicObj.hpp"

class MirrorObj: public DynamicObj
{
	protected:
		float* x;
		float* y;
		float* angle;
		float* scale_x;
		float* scale_y;
	public:
		MirrorObj(){};
		MirrorObj(sf::Drawable *drawble, sf::Transformable* trans, float* scale_x,float* scale_y, float* x, float* y, float* angle, int* health);
		virtual void update(sf::Event event) override;
		int get_health() override;
};