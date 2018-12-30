#ifndef CONFIG_HPP
#define CONFIG_HPP

#include<iostream>


namespace cfg {
  namespace lcg {
    // modulus
    const uint64_t m = 38892473;

    // multiplier
    const uint64_t a = 5101;

    // increment
    const uint64_t c = 11;

    // iniitial spins
    const size_t INITIAL_SPINS = 7;
  };

  namespace physics {
    const double g = -.01;
  };

  namespace settings {
    const int NUMBER_OF_BLOCKS = 100000;
    const int SIMULATION_LENGTH = 600;
    const int SCREEN_WIDTH = 1960;
    const int SCREEN_HEIGHT = 1080;
    const bool RECORDING = false;
  }
};


#endif
