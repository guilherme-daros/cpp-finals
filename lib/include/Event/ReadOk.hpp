#pragma once
#include "EventBase.hpp"

class ReadOk : public EventBase {
 protected:
  float measuredValue;

 public:
  ReadOk() {
    measuredValue = 0;
    std::time(&timepoint);
  }

  ReadOk(float measuredValue_p) {
    measuredValue = measuredValue_p;
    std::time(&timepoint);
  }

  ReadOk(json j) {
    timepoint = j["timepoint"];
    measuredValue = j["measuredValue"];
  }

  json toJson() override {
    return {{"eventName", "ReadOk"},
            {"timepoint", timepoint},
            {"measuredValue", measuredValue}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [ReadOk] - ";
    str << "measuredValue: " << measuredValue << ";";
  }
};
