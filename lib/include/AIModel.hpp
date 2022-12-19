#pragma once

#include <cstdint>
#include <ctime>
#include <iostream>
#include <random>
#include <string>

class AIModel {
  std::time_t timepoint;
  uint32_t seed = 6;

 public:
  float predictTemperature() {
    std::time(&timepoint);
    std::srand(timepoint + seed);
    if (std::rand() % 2) {
      return 25.1;
    } else {
      return 30.2;
    }
  }
  void setModel(uint32_t n_seed) { seed = n_seed; }
};
