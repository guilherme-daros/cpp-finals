#pragma once
#include "EventBase.hpp"

class SendDataToServer : public EventBase {
 protected:
  float actualValue;

 public:
  SendDataToServer() {
    actualValue = 0;
    std::time(&timepoint);
  }

  SendDataToServer(float actualValue_p) {
    actualValue = actualValue_p;
    std::time(&timepoint);
  }

  SendDataToServer(json j) {
    timepoint = j["timepoint"];
    actualValue = j["actualValue"];
  }

  json toJson() override {
    return {{"eventName", "SendDataToServer"},
            {"timepoint", timepoint},
            {"actualValue", actualValue}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [SendDataToServer] - ";
    str << "actualValue:" << actualValue << ";";
  }
};
