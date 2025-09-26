#pragma once

#include "ItemList.hpp"
#include "MultiShapeButton.hpp"
#include "../backend/util/Preview.hpp"


class PreviewItemList: public ItemList<MultiShapeButton>
{
	Preview *previews;
	sf::Font font;
	public:
		PreviewItemList();
		PreviewItemList(sf::Drawable *drawble, sf::Transformable* trans, sf::FloatRect bounds,sf::Vector2f position, sf::Shape *item_shape);
		int interact(sf::Vector2i mouse_position);
		void update(sf::Event event);
		void draw(sf::RenderWindow * win);
		
};