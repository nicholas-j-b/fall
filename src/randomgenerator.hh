#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include<iostream>

#include "config.hh"

class RandomGenerator {
private:
  uint64_t _x;
public:
  RandomGenerator(uint64_t);
  ~RandomGenerator();

  void calculate_next();
  unsigned char get_next_char();
  unsigned int get_next_int();
  double get_next_double();
};


#endif
