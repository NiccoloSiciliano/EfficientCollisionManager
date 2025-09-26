#pragma once

#include <SFML/Graphics.hpp>
#include "LinkedList.hpp"

#include <SFML/Graphics/Export.hpp>

#include <SFML/Graphics/Shape.hpp>

class MultiShapeButton : public Button, public LinkedList<Object> 
{
	public:
	    MultiShapeButton(sf::Drawable *drawble, sf::Transformable* trans,sf::FloatRect bounds,sf::Vector2f position)
		{
			this->drawble = drawble;
			this->trans = trans;

			this->trans->setPosition(position);
			this->original_bounds = bounds;
			this->bounds = bounds;
		}

		~MultiShapeButton()
		{
			clear();
		}
	private:
	    // Override the pure virtual function from sf::Drawable
	    void draw(sf::RenderWindow * win)
	    {
	    	reset_iterate();
	    	win->draw(*(this->drawble));
	        for (int i = 0; i < get_count(); i++)
	        {

	        	Object* d = iterate();
	        	d->draw(win);
	        }
	    }
};

/*
	class Drawable;
class SFML_GRAPHICS_API MultiShape: public Drawable, public LinkedList<const Drawable>, public RenderTarget
{

protected:
	void draw(RenderTarget& target, const RenderStates& states)
		{
			node<const Drawable> *hold = get_list();
			while(hold != NULL)
			{
				const Drawable *d = (hold->data);
				d->draw(target, states);
				hold = hold->next;
			}
		}
	public:
		MultiShape()
		{

		}
		
};
*/
