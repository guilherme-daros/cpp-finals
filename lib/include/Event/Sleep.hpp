#pragma once

#include <ctime>

#include "EventBase.hpp"

class Sleep : public EventBase {
 protected:
  uint32_t timeToSleep;

 public:
  Sleep() {
    timeToSleep = 0;
    std::time(&timepoint);
  };
  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [Sleep]";
    str << " timeToSleep: " << timeToSleep << ";";
  }
};
