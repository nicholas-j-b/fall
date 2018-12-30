#include "environment.hh"

Environment::Environment()
:_r(0), _g(0), _b(0)
{
  _streams.reserve(3);

  // for(size_t i = 0; i < 2; ++i){
    _streams.push_back(Stream(100, 300, .04));
    _streams.push_back(Stream(300, 500, -.03));
    _streams.push_back(Stream(600, 700, .03));
  // }
  _blocks.reserve(cfg::settings::NUMBER_OF_BLOCKS);
  for(uint64_t i = 0; i < cfg::settings::NUMBER_OF_BLOCKS; ++i){
    _blocks.push_back(Block(i*99, _streams));
  }
}


void Environment::update()
{
  for(auto& b : _blocks){
    b.update();
    b.draw();
  }
}

ALLEGRO_COLOR Environment::get_next_background_colour()
{
  _r = (_r + .2);
  _g = (_g + .5);
  _b = (_b + .3);
  return al_map_rgb(_r, _g, _b);
}
