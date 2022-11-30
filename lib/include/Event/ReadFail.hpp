#pragma once
#include "EventBase.hpp"

class ReadFail : public EventBase {
 protected:
  std::string errorMsg;

 public:
  ReadFail() {
    errorMsg = "";
    std::time(&timepoint);
  }

  ReadFail(std::string& errorMsg_p) {
    errorMsg = errorMsg_p;
    std::time(&timepoint);
  }

  ReadFail(json j) {
    errorMsg = j["errorMsg"];
    timepoint = j["timepoint"];
  }

  json toJson() override {
    return {{"eventName", "ReadFail"},
            {"timepoint", timepoint},
            {"errorMsg", errorMsg}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [ReadFail] - ";
    str << "errorMsg: " << errorMsg << ";";
  }
};
