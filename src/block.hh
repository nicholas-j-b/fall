#ifndef _block_hh_
#define _block_hh_

#include<iostream>
#include<vector>

#include<allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "config.hh"
#include "randomgenerator.hh"
#include "stream.hh"

class Block
{
private:
  double _posx;
  double _posy;
  int _iPosx;
  int _iPosy;
  double _velx;
  double _vely;

  std::vector<Stream&>* _streams;

  int _size;
  ALLEGRO_COLOR _colour;
  RandomGenerator _rg;
public:
  Block(uint64_t, std::vector<Stream&>);

  void draw();
  void params_to_ints();

  void update();
  void interact_stream();
};

#endif
