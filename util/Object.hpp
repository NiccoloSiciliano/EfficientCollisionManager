#pragma once
#include <SFML/Graphics.hpp>

class Object
{
	protected:
		int *health;
		sf::Drawable* drawble;
		sf::Transformable* trans;
		sf::FloatRect bounds;
		sf::FloatRect original_bounds;
	public:
		Object();
		Object(sf::Drawable *drawble, sf::Transformable* trans, sf::FloatRect bounds,sf::Vector2f position);
		virtual void set_position(sf::Vector2f position);
		sf::Vector2f get_position();
		sf::FloatRect get_local_bounds();
		void set_shape(sf::Drawable *drawble, sf::Transformable* trans);
		sf::Transformable* get_transformable();
		sf::Drawable* get_drawable();
		void set_scale(sf::Vector2f scale);
		virtual int get_health();


		virtual void draw(sf::RenderWindow * win);
		~Object();
};