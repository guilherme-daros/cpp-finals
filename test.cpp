#include <chrono>
#include <iostream>
#include <thread>

#include "Serial.hpp"

int main() {
  Serial serial("/dev/ttyUSB0", B9600);

  std::cout << "[Serial] Connecting\n";
  while (serial.openPort() < 0) {
  }
  std::cout << "[Serial] Connected\n";

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(5s);

  std::cout << serial.readPort();
  std::cout << serial.readPort();
  std::cout << serial.readPort();

  std::cout << "[Serial] Disconnecting\n";
  if (serial.closePort() < 0) {
  }
  std::cout << "[Serial] Disconnected\n";

  return 0;
}