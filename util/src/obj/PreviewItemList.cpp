#include "../../PreviewItemList.hpp"


PreviewItemList::PreviewItemList()
{

	font.loadFromFile("OpenSans-Light.ttf");

	this->drawble = NULL;
	this->trans = NULL;
}


PreviewItemList::PreviewItemList(sf::Drawable *drawble, sf::Transformable* trans, sf::FloatRect bounds,sf::Vector2f position, sf::Shape *item_shape)
{

	font.loadFromFile("OpenSans-Light.ttf");
	this->drawble = drawble;
	this->trans = trans;
	this->trans->setPosition(position);
	this->original_bounds = bounds;
	this->bounds = bounds;

	set_item_shape(item_shape);
}

int PreviewItemList::interact(sf::Vector2i mouse_position)
{
	if (mouse_on(mouse_position))
	{
		item_list.reset_iterate();
		for (int i = 0; i < item_list.get_count(); i++)
		{
			Button* b = item_list.iterate();
			if (b->interact(mouse_position))
			{
				send(5, previews[i].url);
				break;
			}

		}
	}
	return 0;
}
void PreviewItemList::update(sf::Event event)
{

	if (index == 1)
	{
		remove_item(-1);
		previews = (Preview*) buff;
		//creates button

		for (int i = 0; i < 5; i++)
		{
			sf::Shape *item_rect = new sf::RectangleShape(sf::Vector2f(10, 10));
			*item_rect = *item_shape;
			MultiShapeButton* b = new MultiShapeButton(item_rect,item_rect,item_rect->getLocalBounds(),get_position()+sf::Vector2f(0,original_bounds.height*i));
			
			sf::Text* text = new sf::Text(previews[i].title, font);
			text->setCharacterSize(16);

			text->setFillColor(sf::Color(0,0,0));

			Object* text_obj= new Object(text, text, text->getLocalBounds(), b->get_position());
			b->insert_node(new node<Object> (text_obj, true));
			item_list.insert_node(new node<MultiShapeButton>(b, true));
		}
	}

	index = 0;
}


void PreviewItemList::draw(sf::RenderWindow * win)
{
	set_scale(sf::Vector2f(1,item_list.get_count()));

	Button::draw(win);
	item_list.reset_iterate();
	for (int i = 0; i < item_list.get_count(); i++)
	{
		Button* b = item_list.iterate();
		b->draw(win);
	}
}