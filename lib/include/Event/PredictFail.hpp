#pragma once

#include <ctime>

#include "EventBase.hpp"

class PredictFail : public EventBase {
 protected:
  uint32_t predictedValue;
  uint32_t actualValue;

 public:
  PredictFail() {
    predictedValue = 0;
    actualValue = 0;
    std::time(&timepoint);
  };
  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [PredictFail]";
    str << " predictedValue: " << predictedValue << ";";
    str << " actualValue:" << actualValue << ";";
  }
};
