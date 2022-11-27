#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "Serial.hpp"
#include "Event/Event.hpp"
#include "EventParser.hpp"

int main() {

    using namespace std::chrono_literals;
    
    Serial serial("/dev/ttyUSB0", B9600);
    
    std::vector<EventBase *> queue;
        
    std::cout << "[Serial] Connecting\n";
    while (serial.openPort() < 0){}
    std::cout << "[Serial] Connected\n";
    std::this_thread::sleep_for(5s);

    while(serial.available()){
        std::string A = serial.readPort();
        queue.emplace_back(ParseEvent(A));
    }

    for (auto i: queue){
        std::cout << *i << std::endl;
    }

    std::cout << "[Serial] Disconnecting\n";
    if (serial.closePort() < 0) {}
    std::cout << "[Serial] Disconnected\n";

    return 0;
}