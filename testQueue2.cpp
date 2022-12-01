#include <iostream>

#include "Event/Event.hpp"
#include "Queue.hpp"

int main(int argc, char const* argv[]) {
  Queue<EventBase*> queue;

  queue.push(new PredictFail(12, 13));

  std::cout << *queue.pop() << std::endl;

  return 0;
}
