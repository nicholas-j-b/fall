#include "block.hh"


Block::Block(uint64_t seed, std::vector<Stream&> streams)
:_rg(seed), _velx(0), _vely(0), _size(2), _streams(streams)
{
  _posx = _rg.get_next_int() % 403;
  _posy = _rg.get_next_int() % 403;
  _colour = al_map_rgb(200, 200, 200);
}

void Block::draw()
{
  _colour = al_map_rgb(200, 200, 200);
  al_draw_filled_rectangle(_iPosx - _size, _iPosy - _size, _iPosx + _size, _iPosy + _size, _colour);
}

void Block::params_to_ints()
{
  _iPosx = _posx;
  _iPosy = _posy;
}

void Block::update()
{
  interact_stream();
  _vely += cfg::physics::g;

  _posx += _velx;
  _posy += _vely;

  params_to_ints();
}

void Block::interact_stream()
{
  for(auto& s : _streams){
    if(_posy > s->_lower && _posy < s->_upper){
      _velx += s->_power;
    }
  }
}
