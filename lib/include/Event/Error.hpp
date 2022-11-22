#pragma once

#include <ctime>
#include <string>

#include "EventBase.hpp"

class Error : public EventBase {
 protected:
  std::string errorMsg;

 public:
  Error() {
    errorMsg = "";
    std::time(&timepoint);
  };
  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [Error]";
    str << " errorMsg: " << errorMsg << ";";
  }
};
