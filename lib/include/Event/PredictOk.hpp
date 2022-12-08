#pragma once
#include <cstdlib>
#include "EventBase.hpp"

class PredictOk : public EventBase {
 protected:
  int32_t predictedValue;
  int32_t actualValue;
  uint32_t error;

 public:
  PredictOk() {
    predictedValue = 0;
    actualValue = 0;
    error = abs(predictedValue - actualValue);
    std::time(&timepoint);
  }

  PredictOk(uint32_t predictedValue_p, uint32_t actualValue_p) {
    predictedValue = predictedValue_p;
    actualValue = actualValue_p;
    error = abs(predictedValue - actualValue);
    std::time(&timepoint);
  }

  PredictOk(json j) {
    predictedValue = j["predictedValue"];
    actualValue = j["actualValue"];
    error = abs(predictedValue - actualValue);
    timepoint = j["timepoint"];
  }

  json toJson() override {
    return {{"eventName", "PredictOk"},
            {"timepoint", timepoint},
            {"predictedValue", predictedValue},
            {"actualValue", actualValue},
            {"error", error}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [PredictOk] - ";
    str << "predictedValue: " << predictedValue << ";";
    str << "actualValue: " << actualValue << ";";
    str << "error: " << error << ";";
  }
};
