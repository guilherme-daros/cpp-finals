#pragma once

#include <ctime>

#include "EventBase.hpp"

class PredictOk : public EventBase {
 protected:
  uint32_t predictedValue;
  uint32_t actualValue;
  uint32_t error;

 public:
  PredictOk() {
    predictedValue = 0;
    actualValue = 0;
    error = abs(predictedValue - actualValue);
    std::time(&timepoint);
  };
  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [PredictOk]";
    str << " predictedValue: " << predictedValue << ";";
    str << " actualValue: " << actualValue << ";";
    str << "error: " << error << ";";
  }
};
