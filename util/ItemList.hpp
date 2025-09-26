#pragma once
#include <SFML/Graphics.hpp>
#include "Receiver.hpp"
#include "Sender.hpp"
#include "Button.hpp"
#include "LinkedList.hpp"
template <typename T> class ItemList: public Button, public Receiver, public Sender
{
	protected:
		LinkedList<T> item_list;
		sf::Shape *item_shape;
	public:
		void set_item_shape(sf::Shape *item_shape)
		{
			this->item_shape = item_shape;
		}
		void add_item(T *item)
		{
			item_list.insert_node(item);
		}
		virtual void remove_item(int index)
		{
			if (index == -1)
			{
				item_list.clear();
			}
		}
		// void draw(sf::RenderWindow * win);
};