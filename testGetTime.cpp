#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "AppMenu.hpp"
#include "DataStructures/Queue.hpp"
#include "Event/Event.hpp"
#include "EventParser.hpp"
#include "Serial.hpp"

int main() {
  using namespace std::chrono_literals;

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
    queue.emplace_back(EventParser::ParseEvent(i));
  }

  time_t initialTime = AppMenu::getTimeFromUserMenu("Begin");
  time_t endTime = AppMenu::getTimeFromUserMenu("End");

  std::vector<EventBase*> slice =
      AppMenu::getTimedSliceMenu(queue, initialTime, endTime);

  AppMenu::printQueueSlice(slice);
  return 0;
}