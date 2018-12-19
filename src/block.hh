#include<iostream>
#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class Block
{
public:
  void draw()
  {
			al_draw_filled_rectangle(10, 10, 300, 300, al_map_rgb(200, 200, 200));
  }
};
