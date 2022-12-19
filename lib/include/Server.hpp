#pragma once
#include <chrono>
#include <cstdint>
#include <ctime>
#include <random>
#include <thread>

class Server {
 public:
  void SendData(float value){};

  uint32_t WaitNewData() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);

    std::time_t timepoint;
    std::time(&timepoint);
    std::srand(timepoint);
    return std::rand() % 32;
  }
};
