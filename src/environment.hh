#ifndef _environment_hh_
#define _environment_hh_

#include<iostream>
#include<vector>

#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "config.hh"
#include "block.hh"
#include "stream.hh"

class Environment
{
private:
  std::vector<Block> _blocks;
  std::vector<Stream> _streams;

  double _r;
  double _g;
  double _b;
public:
  Environment();

  void update();
  ALLEGRO_COLOR get_next_background_colour();
};

#endif
