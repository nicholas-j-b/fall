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
public:
  Environment();

  void update();
};

#endif
