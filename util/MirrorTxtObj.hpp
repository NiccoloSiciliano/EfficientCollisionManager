#pragma once
#include "./MirrorObj.hpp"

class MirrorTxtObj: public MirrorObj
{
	sf::Text* text_sp;
	char* text;
	public:
		MirrorTxtObj(sf::Text *text_sp, float* scale_x,float* scale_y, float* x, float* y, float* angle, int* health, char* text);
		void update(sf::Event event) override;
};