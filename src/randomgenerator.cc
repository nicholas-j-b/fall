#include "randomgenerator.hh"

// LCG

//--------------------
// constructor etc

RandomGenerator::RandomGenerator(uint64_t seed)
: _x(seed)
{
  for (size_t i = 0; i < cfg::lcg::INITIAL_SPINS; ++i){
    calculate_next();
  }

}

RandomGenerator::~RandomGenerator()
{

}

//--------------------
// member functions

void RandomGenerator::calculate_next()
{
  _x = (cfg::lcg::a * _x + cfg::lcg::c) % cfg::lcg::m;
}

unsigned char RandomGenerator::get_next_char()
{
  calculate_next();
  return static_cast<unsigned char>(_x);
}

unsigned int RandomGenerator::get_next_int()
{
  calculate_next();
  return static_cast<unsigned int>(_x);
}
