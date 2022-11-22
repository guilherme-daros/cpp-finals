#include <chrono>
#include <iostream>
#include <thread>

#include "Serial.hpp"

int main() {
    Serial serial("/dev/ttyUSB0", 9600);

    std::cout << "[Serial] Connecting\n";
    while (serial.openPort() < 0) {
    }
    std::cout << "[Serial] Connected\n";

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(120s);

    std::string str;
    serial.readPort(str);

    std::cout << "[Serial] Disconnecting\n";
    if (serial.closePort() < 0) {
    }
    std::cout << "[Serial] Disconnected\n";

    return 0;
}