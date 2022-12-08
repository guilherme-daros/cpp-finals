#include <iostream>

#include "DataStructures/Queue.hpp"
#include "Event/Event.hpp"

int main(int argc, char const* argv[]) {
  Queue<EventBase*> queue;

  queue.push(new Init);
  queue.push(new ReadOk);
  queue.push(new PredictOk);
  queue.push(new Sleep);
  queue.push(new WakeUp);
  queue.push(new ReadOk);
  queue.push(new PredictFail);
  queue.push(new SendDataToServer);
  queue.push(new NewModelArrived);
  queue.push(new Sleep);
  queue.push(new WakeUp);
  queue.push(new ReadFail);
  queue.push(new ReadOk);
  queue.push(new PredictOk);
  queue.push(new Sleep);

  auto size = queue.getSize();
  for (auto i{0}; i < size; i++) {
    std::cout << queue.getSize() << " - ";
    std::cout << *queue.pop() << std::endl;
  }

  return 0;
}
