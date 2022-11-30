#pragma once

#include <ctime>
#include <iostream>
#include <string>

#include "Json.hpp"

using json = nlohmann::json;

class EventBase {
 protected:
  std::time_t timepoint;

  virtual void print(std::ostream& str) = 0;

 public:
  virtual json toJson() = 0;
  std::time_t getTime() { return timepoint; }

  friend std::ostream& operator<<(std::ostream& os, EventBase& data) {
    data.print(os);
    return os;
  }
};