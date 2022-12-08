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

  Serial serial("/dev/ttyUSB0", B9600);

  std::vector<EventBase*> queue;

  std::cout << "[Host] - Initializing Serial\n";
  bool first_run = true;
  while (serial.openPort() < 0) {
    if (first_run) {
      std::cout << "[Host] - Serial device not found\n";
      std::cout << "[Host] - Please connect to the Station\n";
      first_run = false;
    }
  }
  std::cout << "[Host] - Station serial found\n";
  // Wait for connection to stabilize
  std::this_thread::sleep_for(1s);

  std::cout << "[Host] - Press button on Station to receive data\n";
  std::this_thread::sleep_for(5s);
  uint32_t data_count{0};

  while (serial.available()) {
    std::string A = serial.readPort();
    queue.emplace_back(EventParser::ParseEvent(A));
    data_count++;
  }

  std::cout << "[Host] - Received " << data_count << " events from station\n";

  while (true) {
    time_t initialTime = AppMenu::getTimeFromUserMenu("Initial");
    time_t endTime = AppMenu::getTimeFromUserMenu("End");

    std::vector<EventBase*> slice =
        AppMenu::getTimedSliceMenu(queue, initialTime, endTime);

    AppMenu::printQueueSlice(slice);

    char exit_ = 0;
    std::cout << "[Host] - Press 0 to exit or other key to search again\n";
    std::cin >> exit_;
    if (exit_ == '0') {
      break;
    }
  }
  return 0;
}