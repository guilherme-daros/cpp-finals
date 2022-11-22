#pragma once

#include <ctime>

#include "EventBase.hpp"

class SendDataToServer : public EventBase {
   protected:
    uint32_t actualValue;

   public:
    SendDataToServer() {
        actualValue = 0;
        std::time(&timepoint);
    };
    void print(std::ostream& str) override {
        char buf[100];
        strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

        str << buf;
        str << " - [SendDataToServer]";
        str << " actualValue:" << actualValue << ";";
    }
};
