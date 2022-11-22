#pragma once

#include <ctime>
#include <string>

#include "EventBase.hpp"

class NewModelArrived : public EventBase {
   protected:
    std::string modelName;

   public:
    NewModelArrived() {
        modelName = "";
        std::time(&timepoint);
    };
    void print(std::ostream& str) override {
        char buf[100];
        strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

        str << buf;
        str << " - [NewModelArrived]";
        str << " modelName: " << modelName << ";";
    }
};
