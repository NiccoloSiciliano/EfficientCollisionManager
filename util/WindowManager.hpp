#pragma once
#include "Window.hpp"
#include "WinBuilder.hpp"
#include "TextInputBar.hpp"
#include "PreviewItemList.hpp"
#include "MultiShapeButton.hpp"
#include "Resources.hpp"
#include "MirrorObj.hpp"
#include "MirrorTxtObj.hpp"
#include "../application/util/PlaySection.hpp"
#include "../backend/util/Logic.hpp"
#include "../backend/util/MsgObject.hpp"

#include <SFML/Graphics.hpp>
extern sf::Vector2f screen_size;
extern Resources resources;

class WindowManager
{
	Window *windows[3];
	sf::RenderWindow *screen;
	int current_win;
	Receiver recv;
	//ConnectionManager connection_manager;

	
	public:
		WindowManager(Logic* logic);
		void set_screen(sf::RenderWindow* screen);
		void update(sf::Event event);
		void draw();
};