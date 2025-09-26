#include "../../WinBuilder.hpp"

WinBuilder* WinBuilder::set_size(sf::Vector2f win_size)
{
	this->size = win_size;
	return this;
}
WinBuilder* WinBuilder::set_static_obj_count(int count)
{
	this->stc_objs_count = count;
	return this;
}
WinBuilder* WinBuilder::add_static_obj(Object *obj, sf::Vector2f ratio)
{
	if (stc_objs_count == 0)
	{
		std::cerr<<"Size of static objects is 0"<<std::endl;
		return this;
	}
	if (current_stc_obj >= stc_objs_count)
	{
		std::cerr<<"Maximum static objects reached"<<std::endl;
		return this;
	}
	obj->set_scale(sf::Vector2f(screen_size.x*ratio.x/obj->get_local_bounds().width,screen_size.y*ratio.y/obj->get_local_bounds().height));
	obj->set_position(obj->get_position()+this->position);
	this->stc_objs[current_stc_obj] = obj;
	current_stc_obj++;
	return this;
}

WinBuilder* WinBuilder::set_position(sf::Vector2f position) 
{
	Window::set_position(position);
	return this;
}

WinBuilder* WinBuilder::add_button_obj(Button *obj, sf::Vector2f ratio)
{
	//obj->set_scale(sf::Vector2f(screen_size.x*ratio.x/obj->get_local_bounds().width,screen_size.y*ratio.y/obj->get_local_bounds().height));
	obj->set_position(obj->get_position()+this->position);
	Window::insert_button_obj(obj);
	return this;
}

WinBuilder* WinBuilder::add_volatile_obj(DynamicObj* obj)
{
	//obj->set_scale(sf::Vector2f(screen_size.x*ratio.x/obj->get_local_bounds().width,screen_size.y*ratio.y/obj->get_local_bounds().height));
	obj->set_position(obj->get_position()+this->position);
	Window::insert_volatile_obj(obj);
	return this;
}

Window* WinBuilder::build()
{
	return this;
}
