#include "../../TextInputBar.hpp"
#include <stdio.h>
TextInputBar::TextInputBar(sf::Vector2f position)
{
	
	font.loadFromFile("OpenSans-Light.ttf");
	search_bar= new sf::RectangleShape(sf::Vector2f(7*screen_size.x/9.f, screen_size.y/11));
	search_bar->setFillColor(sf::Color(195,154,233.2));
	search_bar->setOutlineColor(sf::Color(255,255,255));
	search_bar->setOutlineThickness(screen_size.x/100.f);
	set_shape(search_bar, search_bar);
	text = sf::Text(" ", font);
	text.setCharacterSize(20);
	original_bounds = search_bar->getLocalBounds();
	bounds = original_bounds;
	text.setPosition(7*screen_size.x/9.f/15, screen_size.y/11/2 - 10);
	text.setString(input);
	text.setFillColor(sf::Color(255, 255, 255));
	text.setPosition(sf::Vector2f(position.x + text.getPosition().x, position.y + text.getPosition().y));
	
	set_position(sf::Vector2f(position.x, position.y));
	cursor = new sf::RectangleShape(sf::Vector2f(3, 20));
	cursor->setPosition(text.findCharacterPos(0));
	cursor->setFillColor(sf::Color(255, 255, 255));
	str = (char*)calloc(1,1);
}
void TextInputBar::set_cursor_to(int index)
{
	this->index = index;
	cursor->setPosition(text.findCharacterPos(index+1));

}
int TextInputBar::interact(sf::Vector2i mouse_position)
{
	if (mouse_on(mouse_position))
	{
		press();
		search_bar->setOutlineColor(sf::Color(138,43,226));
		if (pressed)
		{
			sf::Vector2f relative_pos = sf::Vector2f(mouse_position.x - text.getPosition().x, mouse_position.y - text.getPosition().y);
			if (relative_pos.x < 0)
				set_cursor_to(0);
			else
			if ((int)relative_pos.x/10 > input.getSize())
				set_cursor_to(input.getSize());
			else
				set_cursor_to((int)relative_pos.x/10);

		}
	}
	else
	{
		unpress();
		search_bar->setOutlineColor(sf::Color(255,255,255));
		
	}
	return 0;
}

sf::String* TextInputBar::get_text()
{
	return &input;
}

void TextInputBar::update(sf::Event event)
{
	if (pressed)
	{

		if (event.type == sf::Event::TextEntered)
		{
			current_char = event.text.unicode;
			if ((pre_event != 1  || last_char != current_char))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					free(str);
					pre_event = 1;
					str = (char*)calloc(input.getSize(),1);
					for (int i = 0; i < input.getSize(); i++)
						str[i] = (char)input.getData()[i];
					send(4, str);
				}
				else if (event.text.unicode == '\b')
				{
					if (this->index >= 0)
					{
						input.erase(this->index);
						text.setString(input);
				    	set_cursor_to(this->index-1);
						pre_event = 1;
					}

				}
				else
				{
					
					pre_event = 1;
			    	input +=event.text.unicode;
			    	text.setString(input);
			    	set_cursor_to(input.getSize()-1);
		    	}
			}
			last_char = current_char;
		}
		else
			pre_event = 0;
			
	}
}	
void TextInputBar::draw(sf::RenderWindow *win)
{
	Object::draw(win);
	win->draw(text);
	if (pressed)
		win->draw(*cursor);
}


void TextInputBar::set_position(sf::Vector2f position)
{
	Object::set_position(position);
}