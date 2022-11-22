#pragma once

#include <ctime>

#include "EventBase.hpp"

class Init : public EventBase {
 public:
  Init() { std::time(&timepoint); };
  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [Init]";
  }
};
