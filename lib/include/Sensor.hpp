#pragma once
#include <cstdint>

class Sensor {
 protected:
  virtual float read() = 0;

 public:
  int id;
};