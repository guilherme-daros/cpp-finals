#pragma once

#include <ctime>

#include "EventBase.hpp"

class ReadOk : public EventBase {
   protected:
    uint32_t measuredValue;

   public:
    ReadOk() {
        measuredValue = 0;
        std::time(&timepoint);
    };
    void print(std::ostream& str) override {
        char buf[100];
        strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

        str << buf;
        str << " - [ReadOk]";
        str << " measuredValue: " << measuredValue << ";";
    }
};
