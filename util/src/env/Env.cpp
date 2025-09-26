#include "../../Env.hpp"
sf::Vector2f screen_size = sf::Vector2f(1000, 1000);
unsigned int Timer::frame_from_start;
unsigned int Timer::last_frame_per_second;
unsigned int Timer::current_time_seconds;
unsigned int Timer::obj_count;

extern Resources resources;
Environment::Environment() :screen(sf::VideoMode(2240, 1400), "GAme", sf::Style::Fullscreen), win_manager(&logic)
{
	cout<<"Building Environment..."<<endl;
	win_manager.set_screen(&screen);
    screen.setFramerateLimit(60);
    Timer::frame_from_start = 0;
    Timer::last_frame_per_second = 0;
    Timer::current_time_seconds = 0;
    Timer::obj_count = 0;
    sf::View worldview(screen.getDefaultView());
    worldview.setCenter(sf::Vector2f(0,0));
}

int Environment::main_loop()
{
	while (screen.isOpen())
    {
        while (screen.pollEvent(resources.event))
        {
            if (resources.event.type == sf::Event::Closed)
                screen.close();
        }
        win_manager.update(resources.event);
        screen.clear(sf::Color(2.4,2.9,20.6));
    	win_manager.draw();    
        screen.display();
        logic.update();
        Timer::update();
    }
	return 0;
}