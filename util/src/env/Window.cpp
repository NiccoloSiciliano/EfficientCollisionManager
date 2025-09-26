#include "../../Window.hpp"

Window::Window()
{
	position.x = 0;
	position.y = 0;
	button_objs_count = 0;
	std::cout<<"Initializing Window."<<std::endl;
	prev_mouse = false;
}

void Window::draw(sf::RenderWindow *on)
{
	
	for (int i = 0; i < stc_objs_count; i++)
		stc_objs[i]->draw(on);
	button_objs.reset_iterate();
	Timer::obj_count = button_objs.get_count();
	for (int i = 0; i < button_objs.get_count(); i++)
	{
		DynamicObj* d = button_objs.iterate();
		d->draw(on);
	}
	volatile_obj.reset_iterate();
	Timer::obj_count += volatile_obj.get_count();
	
	for (int i = 0; i < volatile_obj.get_count(); i++)
	{
		DynamicObj* d = volatile_obj.iterate();
		d->draw(on);
	}


}

Window* Window::set_position(sf::Vector2f position)
{
	this->position = position;
	for (int i = 0;i < this->stc_objs_count; i++)
		stc_objs[i]->set_position(position+stc_objs[i]->get_position());
	button_objs.reset_iterate();
	for (int i = 0; i < button_objs.get_count(); i++)
	{
		DynamicObj* d = button_objs.iterate();
		d->set_position(position+stc_objs[i]->get_position());
	}
	return this;
}

void Window::update(sf::Event event, sf::Vector2i mouse_position)
{
	if (event.type == sf::Event::MouseButtonPressed || sf::Joystick::isButtonPressed(0, 0))
	{
		mouse_interact(event, mouse_position);
	}
	else
		prev_mouse = false;
	volatile_obj.reset_iterate();
	for (int i = 0; i < volatile_obj.get_count(); i++)
	{
		DynamicObj* d = volatile_obj.iterate();
		d->update(event);
		if (d->get_health() <= 0)
			volatile_obj.tag();

	}

	if (volatile_obj.get_deleted()> 0)
	{
		volatile_obj.reset_iterate();
		volatile_obj.remove_tagged();
	}

}
void Window::mouse_interact(sf::Event event, sf::Vector2i mouse_position)
{
	if (event.mouseButton.button == sf::Mouse::Left || sf::Joystick::isButtonPressed(0, 0))
	{	
		if(!prev_mouse)
		{
			prev_mouse = true;
			button_objs.reset_iterate();
			for (int i = 0; i < button_objs.get_count(); i++)
			{
				Button* d = button_objs.iterate();
				d->interact(mouse_position);
			}
		}
	}

}

void Window::insert_button_obj(Button* obj)
{
	button_objs.insert_node(new node<Button>(obj, true));
	button_objs_count++;
}

void Window::insert_volatile_obj(DynamicObj* obj)
{

	volatile_obj.insert_node(new node<DynamicObj>(obj, true));
}


void Window::clear()
{
	volatile_obj.clear();
}

Window::~Window()
{
	for (int i = 0;i < this->stc_objs_count; i++)
		delete stc_objs[i];
}
