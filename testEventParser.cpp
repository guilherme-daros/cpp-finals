#include <any>
#include <string>

#include "Event/Event.hpp"
#include "EventParser.hpp"
#include "Json.hpp"

int main(int argc, char const* argv[]) {
  std::vector<std::string> str_queue = {
      R"({"eventName":"Init","timepoint":1669580349})",
      R"({"eventName":"ReadOk","measuredValue":0,"timepoint":1669580349})",
      R"({"actualValue":0,"error":0,"eventName":"PredictOk","predictedValue":0,"timepoint":1669580349})",
      R"({"eventName":"Sleep","timeToSleep":0,"timepoint":1669580349})",
      R"({"eventName":"WakeUp","timepoint":1669580349})",
      R"({"eventName":"ReadOk","measuredValue":0,"timepoint":1669580349})",
      R"({"actualValue":0,"eventName":"PredictFail","predictedValue":0,"timepoint":1669580349})",
      R"({"actualValue":0,"eventName":"SendDataToServer","timepoint":1669580349})",
      R"({"eventName":"NewModelArrived","modelName":"","timepoint":1669580349})",
      R"({"eventName":"Sleep","timeToSleep":0,"timepoint":1669580349})",
      R"({"eventName":"WakeUp","timepoint":1669580349})",
      R"({"errorMsg":"","eventName":"ReadFail","timepoint":1669580349})",
      R"({"eventName":"ReadOk","measuredValue":0,"timepoint":1669580349})",
      R"({"actualValue":0,"error":0,"eventName":"PredictOk","predictedValue":0,"timepoint":1669580349})",
      R"({"eventName":"Sleep","timeToSleep":0,"timepoint":1669580349})",
  };

  std::vector<EventBase*> queue;
  for (auto i : str_queue) {
    std::cout << i << std::endl;
    queue.emplace_back(EventParser::ParseEvent(i));
  }
  for (auto i : queue) {
    std::cout << *i << std::endl;
  }
  return 0;
}
