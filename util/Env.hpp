#pragma once
#include "WindowManager.hpp"
#include "../backend/util/Logic.hpp"
#include "./Resources.hpp"
#include "./Timer.hpp"
#include "./Resources.hpp"
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace std;
extern Resources resources;

class Environment
{
	sf::RenderWindow screen;
	WindowManager win_manager;
	Logic logic;
	
	//ConnectionManager connection_manager;

	
	public:
		Environment();
		int main_loop();
};