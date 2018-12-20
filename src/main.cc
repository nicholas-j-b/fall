#include<iostream>
#include<vector>
#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "block.hh"
#include "environment.hh"



int main()
{
	int screen_width = 1400;
	int screen_height = 900;
	float FPS = static_cast<float>(60);

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* eventQueue = NULL;
	if(!al_init())
		return -1;
	display = al_create_display(screen_width, screen_height);
	if(!display)
		return -1;
	al_set_window_position(display, 10, 10);

	al_init_primitives_addon();
	al_install_keyboard();

	timer = al_create_timer(1.0/FPS);
	eventQueue = al_create_event_queue();

	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

  Environment* environment = new Environment();

	al_start_timer(timer);
	for(int i = 0; i < cfg::settings::SIMULATION_LENGTH; ++i)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(eventQueue, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
      environment->update();
			al_flip_display();

			al_clear_to_color(al_map_rgb(50 + i / 2,250 - i / 2,30 + i / 2 ));
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				break;
			}
		}
	}



	al_uninstall_keyboard();
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);

	return 0;
}
