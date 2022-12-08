#include <iostream>

#include "DataStructures/List.hpp"
#include "Event/Event.hpp"

int main(int argc, char const* argv[]) {
  Linkedlist<EventBase*> event_list;

  event_list.emplace_back(new Init);
  event_list.emplace_back(new ReadOk);
  event_list.emplace_back(new PredictOk);
  event_list.emplace_back(new Sleep);
  event_list.emplace_back(new WakeUp);
  event_list.emplace_back(new ReadOk);
  event_list.emplace_back(new PredictFail);
  event_list.emplace_back(new SendDataToServer);
  event_list.emplace_back(new NewModelArrived);
  event_list.emplace_back(new Sleep);
  event_list.emplace_back(new WakeUp);
  event_list.emplace_back(new ReadFail);
  event_list.emplace_back(new ReadOk);
  event_list.emplace_back(new PredictOk);
  event_list.emplace_back(new Sleep);

  std::cout << "operator[] Test\n";
  std::cout << *event_list[2] << std::endl;

  std::cout << "\nranged For Test\n";
  for (auto i : event_list) {
    std::cout << *i << std::endl;
  }

  return 0;
}
