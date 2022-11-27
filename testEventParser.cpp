#include <string>
#include <any>

#include "Json.hpp"
#include "Event/Event.hpp"


EventBase* ParseEvent(std::string input) {
  json j = json::parse(input);
  std::string type = j["eventName"];

  if (type == "Error") return new Error(j);
  else if (type == "Init") return new Init(j);
  else if (type == "NewModelArrived") return new NewModelArrived(j);
  else if (type == "PredictFail") return new PredictFail(j);
  else if (type == "PredictOk") return new PredictOk(j);
  else if (type == "ReadFail") return new ReadFail(j);
  else if (type == "ReadOk") return new ReadOk(j);
  else if (type == "SendDataToServer") return new SendDataToServer(j);
  else if (type == "Sleep") return new Sleep(j);
  else if (type == "WakeUp") return new WakeUp(j);
  return {};
}

int main(int argc, char const *argv[])
{   
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
    
    std::vector<EventBase *> queue;
    for (auto i: str_queue){
        queue.emplace_back(ParseEvent(i));
    } 
    for (auto i: queue){
        std::cout << *i << std::endl;
    }
    return 0;
}
