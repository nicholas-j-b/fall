#include<iostream>
#include<vector>
#include<string>

#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "block.hh"
#include "environment.hh"

int main()
{
	int screen_width = cfg::settings::SCREEN_WIDTH;
	int screen_height = cfg::settings::SCREEN_HEIGHT;
	float FPS = static_cast<float>(60);

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* eventQueue = NULL;
	if(!al_init())
		return -1;
	display = al_create_display(screen_width, screen_height);
	if(!display)
		return -1;
	al_set_window_position(display, 0, 0);

	al_install_keyboard();
	al_init_primitives_addon();
  // if(cfg::settings::RECORDING){
		al_init_image_addon();
	// }
	std::cout << "init addon" << '\n';

	timer = al_create_timer(1.0/FPS);
	eventQueue = al_create_event_queue();
  // if(cfg::settings::RECORDING){
  	ALLEGRO_BITMAP* bmp = al_create_bitmap(cfg::settings::SCREEN_WIDTH, cfg::settings::SCREEN_HEIGHT);
	// }
	std::cout << "create bitmap" << '\n';

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
  // if(cfg::settings::RECORDING){
  	al_set_target_bitmap(bmp);
	// }
	std::cout << "set target bitmap" << '\n';

  Environment* environment = new Environment();

	if(!cfg::settings::RECORDING){
		al_start_timer(timer);
		for(int i = 0; i < cfg::settings::SIMULATION_LENGTH; ++i)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(eventQueue, &ev);
			if(ev.type == ALLEGRO_EVENT_TIMER)
			{
	      environment->update();
				al_flip_display();
				al_clear_to_color(environment->get_next_background_colour());
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				{
					break;
				}
			}
		}
	}else {
		for(int i = 0; i < cfg::settings::SIMULATION_LENGTH; ++i)
		{
			environment->update();
			al_flip_display();
			std::string s = "out/img" + std::to_string(i) + ".png";
			const char* c = s.c_str();
			al_save_bitmap(c, bmp);
			al_clear_to_color(environment->get_next_background_colour());
			std::cout << i << " : " << cfg::settings::SIMULATION_LENGTH << '\n';
		}
	}

	al_uninstall_keyboard();
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);

	return 0;
}
