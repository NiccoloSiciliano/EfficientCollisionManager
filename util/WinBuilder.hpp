#pragma once
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Object.hpp"
extern sf::Vector2f screen_size;
class WinBuilder : public Window
{
	int current_stc_obj = 0;
	public:
		WinBuilder* set_size(sf::Vector2f win_size);
		WinBuilder* set_position(sf::Vector2f position);
		WinBuilder* set_static_obj_count(int count);
		WinBuilder* add_static_obj(Object *obj, sf::Vector2f ratio);
		WinBuilder* add_button_obj(Button *obj, sf::Vector2f ratio);
		WinBuilder* add_volatile_obj(DynamicObj* obj);
		Window* build();
};