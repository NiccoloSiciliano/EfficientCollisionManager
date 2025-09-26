#include "./util/Env.hpp"
#include "./util/Resources.hpp"
#include <iostream>
Resources resources;
int main()
{
	{
		char* fonts_src[] = {"Freshman.ttf"};
		char* textures_src[] = {"./Textures/Player.png", "./Textures/Bullet.png", "./Textures/Inventory.png", "./Textures/Brick.png", "./Textures/rect.png", "./Textures/BrickPlaceholder.png", "./Textures/trace.png","./Textures/gun.png", "./Textures/Shield.png","./Textures/ShieldI.png","./Textures/playerIcon.png","./Textures/Player2.png","./Textures/playerIcon2.png","./Textures/Bag.png"};
		resources.load(fonts_src, textures_src, sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
		
	}
	Environment env;
	env.main_loop();
}