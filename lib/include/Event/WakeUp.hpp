#pragma once
#include "EventBase.hpp"

class WakeUp : public EventBase {
   public:
    WakeUp() { std::time(&timepoint); };

    WakeUp(json j) { timepoint = j["timepoint"]; }

    json toJson() override { return {{"eventName", "WakeUp"}, {"timepoint", timepoint}}; }

    void print(std::ostream& str) override {
        char buf[100];
        strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

        str << buf;
        str << " - [WakeUp]";
    }
};
