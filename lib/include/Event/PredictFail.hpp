#pragma once
#include "EventBase.hpp"

class PredictFail final : public EventBase {
 protected:
  uint32_t predictedValue;
  uint32_t actualValue;

 public:
  PredictFail() {
    predictedValue = 0;
    actualValue = 0;
    std::time(&timepoint);
  }

  PredictFail(uint32_t predictedValue_p, uint32_t actualValue_p) {
    predictedValue = predictedValue_p;
    actualValue = actualValue_p;
    std::time(&timepoint);
  }

  PredictFail(json j) {
    predictedValue = j["predictedValue"];
    actualValue = j["actualValue"];
    timepoint = j["timepoint"];
  }

  json toJson() override {
    return {{"eventName", "PredictFail"},
            {"timepoint", timepoint},
            {"predictedValue", predictedValue},
            {"actualValue", actualValue}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [PredictFail] - ";
    str << "predictedValue: " << predictedValue << " ";
    str << "actualValue:" << actualValue << " ";
  }
};
