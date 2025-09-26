#include "../../Resources.hpp"


void Resources::load(char *fonts_src[], char* textures_src[],int screen_w, int screen_h)
{
	for(int i = 0; i < n_fonts; i++)
		fonts[i].loadFromFile(fonts_src[i]);
	for(int i = 0; i < n_textures; i++)
	{
		textures[i].texture.loadFromFile(textures_src[i]);
		sf::Sprite sprite;
		sprite.setTexture(textures[i].texture);
		textures[i].width = sprite.getGlobalBounds().width;
		textures[i].height = sprite.getGlobalBounds().height;

	}
	this->screen_w = screen_w;
	this->screen_h = screen_h;
	this->cell_dim =  get_screen_h() > get_screen_w() ? get_screen_h()*0.032: get_screen_w()*0.032;
}

sf::Font* Resources::get_font(int ind)
{
	return fonts+ind;
}

sf::Texture* Resources::get_texture(int ind)
{
	return &(textures[ind].texture);
}

int Resources::get_texture_width(int ind)
{
	
	return textures[ind].width;
}

int Resources::get_texture_height(int ind)
{

	return textures[ind].height;
}

int Resources::get_screen_w()
{
	return screen_w;
}


int Resources::get_screen_h()
{
	return screen_h;
}

unsigned int Resources::get_cell_dim()
{
	return cell_dim;
}