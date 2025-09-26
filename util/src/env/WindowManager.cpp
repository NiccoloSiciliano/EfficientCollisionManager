#include "../../WindowManager.hpp"
WindowManager::WindowManager(Logic* logic)
{
	current_win = 0;
	//Building Menu Window
	{
		WinBuilder *winbuilder = new WinBuilder();

		sf::CircleShape *play_btn = new sf::CircleShape(80.f, 3);
		play_btn->setFillColor(sf::Color(255,255,255));
		play_btn->setOrigin(0,play_btn->getGlobalBounds().height);


		//play_btn->setOrigin( play_btn->getLocalBounds().width / 2.f, play_btn->getLocalBounds().height / 2.f );
		play_btn->setScale(0.3f, 0.3f);
		play_btn->setRotation(90); 
		play_btn->setPosition(screen_size.x/2,(screen_size.y/2) -play_btn->getGlobalBounds().height/2);

		
		//Object* play_btn_obj = new Object(play_btn,play_btn ,play_btn->getLocalBounds(),play_btn->getPosition()); 
		PlaySection *play_section = new PlaySection(play_btn, play_btn->getPosition(), 1);
		logic->get_win_mng_sendr()->set_receiver(&this->recv);
		play_section->get_sender()->set_receiver(logic->get_receiver());
		winbuilder->set_size(sf::Vector2f(screen_size.x, screen_size.y))->set_position(sf::Vector2f(0, 0))->add_button_obj(play_section, sf::Vector2f(play_btn->getGlobalBounds().width/screen_size.x, play_btn->getGlobalBounds().height/screen_size.y));
		
		this->windows[0] = winbuilder->build();
	}
	//Building Player entering Window
	{
		WinBuilder *winbuilder = new WinBuilder();

		sf::RectangleShape *border = new sf::RectangleShape(sf::Vector2f(screen_size.x*3/4, screen_size.y*3/4));
		border->setFillColor(sf::Color(0,0,0));
		border->setOrigin(border->getGlobalBounds().width/2,border->getGlobalBounds().height/2);
		border->setOutlineThickness(screen_size.x/100);
		border->setOutlineColor(sf::Color(255,255,255));

		//play_btn->setOrigin( play_btn->getLocalBounds().width / 2.f, play_btn->getLocalBounds().height / 2.f );
		border->setPosition(screen_size.x/2,screen_size.y/2);
		Object* border_obj = new Object(border, border, border->getGlobalBounds(), border->getPosition());
		
		sf::CircleShape *play_btn = new sf::CircleShape(80.f, 3);
		play_btn->setFillColor(sf::Color(255,255,255));
		play_btn->setOrigin(0,play_btn->getGlobalBounds().height);


		//play_btn->setOrigin( play_btn->getLocalBounds().width / 2.f, play_btn->getLocalBounds().height / 2.f );
		play_btn->setScale(0.3f, 0.3f);
		play_btn->setRotation(90); 
		play_btn->setPosition(screen_size.x/2, screen_size.y/2 +screen_size.y*3/8 +play_btn->getGlobalBounds().height);

		PlaySection *play_section = new PlaySection(play_btn, play_btn->getPosition(), 4);
		play_section->get_sender()->set_receiver(logic->get_receiver());
		//Object* play_btn_obj = new Object(play_btn,play_btn ,play_btn->getLocalBounds(),play_btn->getPosition()); 
		winbuilder->set_size(sf::Vector2f(screen_size.x, screen_size.y))->set_position(sf::Vector2f(0, 0))->set_static_obj_count(1)->add_static_obj(border_obj, sf::Vector2f(border->getGlobalBounds().width/screen_size.x, border->getGlobalBounds().height/screen_size.y))->add_button_obj(play_section,sf::Vector2f(play_btn->getGlobalBounds().width/screen_size.x, play_btn->getGlobalBounds().height/screen_size.y));
		
		this->windows[1] = winbuilder->build();
	}
	//Building Player entering Window
	{
		WinBuilder *winbuilder = new WinBuilder();

		//Object* play_btn_obj = new Object(play_btn,play_btn ,play_btn->getLocalBounds(),play_btn->getPosition()); 
		winbuilder->set_size(sf::Vector2f(screen_size.x, screen_size.y))->set_position(sf::Vector2f(0, 0));
		
		this->windows[2] = winbuilder->build();
	}
}

void WindowManager::set_screen(sf::RenderWindow* screen)
{
	this->screen = screen;
}

void WindowManager::update(sf::Event event)
{

	windows[current_win]->update(event, sf::Mouse::getPosition(*screen));

	bool recv_read = recv.is_read();
	switch(recv.read_index())
	{
		case 1:
			current_win = 1;
			break;
		case 3:
			if (!recv_read)
			{
				sf::RectangleShape *player_btn = new sf::RectangleShape(sf::Vector2f(screen_size.x*3/4, screen_size.y*3/4/10));
				player_btn->setFillColor(sf::Color(0,0,0));
				player_btn->setOutlineThickness(screen_size.x/100);
				player_btn->setOutlineColor(sf::Color(255,255,255));
				player_btn->setPosition(screen_size.x/2-screen_size.x*3/8, screen_size.y/2- screen_size.y*3/8);
				sf::Text* text = new sf::Text("Parrow", *resources.get_font(0));
				text->setCharacterSize(screen_size.x/100*4);
				text->setFillColor(sf::Color(255,255,255));
				text->setPosition(screen_size.x/2-screen_size.x*3/8 + screen_size.x/100,screen_size.y/2-screen_size.x*3/8);
				Object* text_obj= new Object(text, text, text->getLocalBounds(), player_btn->getPosition());

				MultiShapeButton *player_btn_obj = new MultiShapeButton(player_btn, player_btn, player_btn->getGlobalBounds(), player_btn->getPosition());
				player_btn_obj->insert_node(new node<Object> (text_obj, true));
				
				windows[current_win]->insert_volatile_obj(player_btn_obj); 
			}
			break;
		case 4:
			windows[current_win]->clear();
			current_win = 2;
			break;
		case 6:
			
			if (!recv_read)
			{

				LinkedList<MsgObject>* msgObjects = (LinkedList<MsgObject>*)recv.read_buff();
				msgObjects->reset_iterate();
				for (int i = 0; i < msgObjects->get_count(); i++)
				{
					MsgObject* msgObject = msgObjects->iterate();
					sf::Drawable *drawble;
					sf::Transformable* trans;
					MirrorObj *mirrorobj;
					if (msgObject->texture_ind == -1)
					{
						sf::Text *text = new sf::Text(msgObject->text, *resources.get_font(0));
						
						text->setOrigin(text->getGlobalBounds().width/2, text->getGlobalBounds().height/2);

						drawble = text;
						trans = text;
						mirrorobj = new MirrorTxtObj(text,msgObject->scale_x, msgObject->scale_y,msgObject->x, msgObject->y, msgObject->angle, msgObject->health, msgObject->text);
					}
					else
					{
						sf::Sprite* ply_sprite = new sf::Sprite (*(resources.get_texture(msgObject->texture_ind)));
						ply_sprite ->setOrigin(ply_sprite->getGlobalBounds().width/2, ply_sprite->getGlobalBounds().height/2);
						drawble = ply_sprite;
						trans = ply_sprite;
						mirrorobj = new MirrorObj(drawble, trans, msgObject->scale_x, msgObject->scale_y,msgObject->x, msgObject->y, msgObject->angle, msgObject->health);
					}
					windows[current_win]->insert_volatile_obj(mirrorobj);
				}
				msgObjects->clear();

			}
			
			break;
	}
	
}

void WindowManager::draw()
{

	windows[current_win]->draw(screen);
}
