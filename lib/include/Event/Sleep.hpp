#pragma once
#include "EventBase.hpp"

class Sleep : public EventBase {
   protected:
    uint32_t timeToSleep;

   public:
    Sleep() {
        timeToSleep = 0;
        std::time(&timepoint);
    }

    Sleep(uint32_t timeToSleep_p) {
        timeToSleep = timeToSleep_p;
        std::time(&timepoint);
    }

    Sleep(json j) {
        timepoint = j["timepoint"];
        timeToSleep = j["timeToSleep"];
    }

    json toJson() override {
        return {{"eventName", "Sleep"}, {"timeToSleep", timeToSleep}, {"timepoint", timepoint}};
    }

    void print(std::ostream& str) override {
        char buf[100];
        strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

        str << buf;
        str << " - [Sleep] - ";
        str << "timeToSleep: " << timeToSleep << ";";
    }
};
