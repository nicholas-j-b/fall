#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main()
{
  al_init();
  al_init_image_addon();
  ALLEGRO_BITMAP* bmp = al_create_bitmap(256, 256);
  al_set_target_bitmap(bmp);
  al_clear_to_color(al_map_rgb_f(1, 0.2, 0.5));
  al_save_bitmap("test.png", bmp);
  return 0;
}
