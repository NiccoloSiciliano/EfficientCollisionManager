#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "LinkedList.hpp"
#include "Object.hpp"
#include "Button.hpp"
#include "Timer.hpp"
class Window
{
	protected:
		Object *stc_objs[2];
		LinkedList<Button> button_objs;
		LinkedList<DynamicObj> volatile_obj;
		int button_objs_count, stc_objs_count;
		sf::Vector2f position, size;
		void mouse_interact(sf::Event event, sf::Vector2i mouse_position);
		int* out_signal;
		char* out_buff;
		bool prev_mouse;
	public:
		Window();
		Window* set_position(sf::Vector2f position);
		void update(sf::Event event, sf::Vector2i mouse_position);
		void draw(sf::RenderWindow *on);
		void insert_button_obj(Button* obj);
		void insert_volatile_obj(DynamicObj* obj);
		void clear();
		~Window();

};