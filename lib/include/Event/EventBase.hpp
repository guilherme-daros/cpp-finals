#pragma once

#include <iostream>

class EventBase {
 protected:
  std::time_t timepoint;

  virtual void print(std::ostream& str) = 0;

 public:
  std::time_t getTime() { return timepoint; }

  friend std::ostream& operator<<(std::ostream& os, EventBase& data) {
    data.print(os);
    return os;
  };
};
