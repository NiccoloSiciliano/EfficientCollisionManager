#pragma once
#include <SFML/Graphics.hpp>
#include "./Button.hpp"
#include "./Sender.hpp"
extern sf::Vector2f screen_size;
class TextInputBar: public Button, public Sender
{
	int pre_event = 0;
	sf::String input;
	sf::Text text;
	sf::Font font;
	sf::Shape *cursor;
	sf::RectangleShape *search_bar;
	int txt_len, index = 0;
	char last_char = -1, current_char = -1;
	char* str;
	void set_cursor_to(int index);
	public:
		TextInputBar(sf::Vector2f position);
		int interact(sf::Vector2i mouse_position);
		sf::String* get_text();
		void update(sf::Event event);
		void draw(sf::RenderWindow *win);
		void set_position(sf::Vector2f position);
};