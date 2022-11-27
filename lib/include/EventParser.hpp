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