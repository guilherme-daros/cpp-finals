#pragma once
#include "Sensor.hpp"

// Dummy Implementation
class TemperatureSensor : public Sensor {
 public:
  float read() override {
    float value{25};
    return value;
  }
};