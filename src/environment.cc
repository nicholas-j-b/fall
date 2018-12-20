#include "environment.hh"

Environment::Environment()
{
  _streams.reserve(2);
  // for(size_t i = 0; i < 2; ++i){
    _streams.push_back(Stream(300, 500, .03))
    _streams.push_back(Stream(500, 700, -.03))
  // }
  _blocks.reserve(cfg::settings::NUMBER_OF_BLOCKS);
  for(uint64_t i = 0; i < cfg::settings::NUMBER_OF_BLOCKS; ++i){
    _blocks.push_back(Block(i*99, _stream));
  }
}


void Environment::update()
{
  for(auto& b : _blocks){
    b.update();
    b.draw();
  }
}
