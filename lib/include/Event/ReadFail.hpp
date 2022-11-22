#pragma once

#include <ctime>
#include <string>

#include "EventBase.hpp"

class ReadFail : public EventBase {
 protected:
  std::string ErrorMsg;

 public:
  ReadFail() {
    ErrorMsg = "";
    std::time(&timepoint);
  };
  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [ReadFail]";
    str << " ErrorMsg: " << ErrorMsg << ";";
  }
};
