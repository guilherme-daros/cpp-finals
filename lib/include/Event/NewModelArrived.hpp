#pragma once
#include "EventBase.hpp"

class NewModelArrived : public EventBase {
 protected:
  std::string modelName;
  uint32_t seed;

 public:
  NewModelArrived() {
    modelName = "";
    std::time(&timepoint);
  }

  NewModelArrived(std::string modelName_p) {
    modelName = modelName_p;
    std::time(&timepoint);
  }

  NewModelArrived(json j) {
    modelName = j["modelName"];
    timepoint = j["timepoint"];
    seed = j["seed"];
  }

  json toJson() override {
    return {{"eventName", "NewModelArrived"},
            {"timepoint", timepoint},
            {"modelName", modelName},
            {"seed", seed}};
  }

  void print(std::ostream& str) override {
    char buf[100];
    strftime(buf, 100, "%d %b %Y %T", localtime(&timepoint));

    str << buf;
    str << " - [NewModelArrived] - ";
    str << "modelName: " << modelName;
    str << "seed" << seed;
  }
};
