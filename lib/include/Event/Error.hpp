#pragma once
#include "EventBase.hpp"

class Error : public EventBase {
 protected:
  std::string errorMsg;

 public:
  Error() {
    errorMsg = "";
    std::time(&timepoint);
  }

  Error(std::string errorMsg_p) {
    errorMsg = errorMsg_p;
    std::time(&timepoint);
  }

  Error(json j) {
    errorMsg = j["errorMsg"];
    timepoint = j["timepoint"];
  }

  json toJson() override {
    return {{"eventName", "Error"},
            {"timepoint", timepoint},
            {"errorMsg", errorMsg}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [Error] - ";
    str << "errorMsg: " << errorMsg << ";";
  }
};
