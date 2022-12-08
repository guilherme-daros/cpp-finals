#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "AppMenu.hpp"
#include "Event/Event.hpp"
#include "Json.hpp"

int main(int argc, char const* argv[]) {
  using namespace std::chrono_literals;

  std::vector<EventBase*> queue;

  queue.emplace_back(new Init);
  queue.emplace_back(new ReadOk);
  queue.emplace_back(new PredictOk);
  queue.emplace_back(new Sleep);
  queue.emplace_back(new WakeUp);
  queue.emplace_back(new ReadOk);
  queue.emplace_back(new PredictFail);
  queue.emplace_back(new SendDataToServer);
  queue.emplace_back(new NewModelArrived);
  queue.emplace_back(new Sleep);
  queue.emplace_back(new WakeUp);
  queue.emplace_back(new ReadFail);
  queue.emplace_back(new ReadOk);
  queue.emplace_back(new PredictOk);
  queue.emplace_back(new Sleep);

  AppMenu::printQueueSlice(queue);

  for (auto i : queue) {
    std::cout << i->toJson() << std::endl;
  }
}
