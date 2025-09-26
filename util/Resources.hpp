#pragma once
#include <SFML/Graphics.hpp>
struct TextureInfo
{
	sf::Texture texture;
	int width, height;
};
class Resources
{
	const int n_textures = 14;
	const int n_fonts = 1;
	sf::Font fonts[1];
	TextureInfo textures[14];
	int screen_w;
	int screen_h;
	int cell_dim;
	public:
		sf::Event event;
		void load(char* fonts_src[], char* textures_src[],int screen_w, int screen_h);
		sf::Font* get_font(int ind);
		sf::Texture* get_texture(int ind);
		int get_screen_w();
		int get_screen_h();
		int get_texture_width(int ind);
		int get_texture_height(int ind);
		unsigned int get_cell_dim();
};