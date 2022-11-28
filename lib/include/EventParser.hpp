#include <unordered_map>
#include <functional>
#include "Json.hpp"
#include "Event/Event.hpp"


namespace EventParser{

std::unordered_map<std::string, std::function<EventBase*(json)>> eventMap = {
    {"Error",           [](json j){return new Error(j);}},
    {"Init",            [](json j){return new Init(j);}},
    {"NewModelArrived", [](json j){return new NewModelArrived(j);}},
    {"PredictFail",     [](json j){return new PredictFail(j);}},
    {"PredictOk",       [](json j){return new PredictOk(j);}},
    {"ReadFail",        [](json j){return new ReadFail(j);}},
    {"ReadOk",          [](json j){return new ReadOk(j);}},
    {"SendDataToServer",[](json j){return new SendDataToServer(j);}},
    {"Sleep",           [](json j){return new Sleep(j);}},
    {"WakeUp",          [](json j){return new WakeUp(j);}}
};

EventBase* ParseEvent(std::string input) {
  json j = json::parse(input);
  std::string type = j["eventName"];

  if(auto option{eventMap.find(type)}; option != eventMap.end()){
    return option->second(j);
  } else {
    return {};
  }
}

}