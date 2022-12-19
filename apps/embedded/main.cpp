#include <chrono>
#include <cstdlib>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include "AIModel.hpp"
#include "DataStructures/Queue.hpp"
#include "Event/Event.hpp"
#include "Log.hpp"
#include "Serial.hpp"
#include "Server.hpp"
#include "TemperatureSensor.hpp"

// Global Variables
Queue<EventBase*> event_queue;
std::mutex event_queue_mtx;

bool readBtn() {
  return false;
}

void UserListener() {
  Serial serial("/dev/ttyACM0", B9600);
  if (readBtn()) {
    while (!event_queue.isEmpty()) {
      std::stringstream stream;

      event_queue_mtx.lock();
      stream << event_queue.pop();
      event_queue_mtx.unlock();

      serial.writePort(stream.str());
    }
  }
}

int main() {
  // Namespaces
  using namespace std::chrono_literals;

  // Constants
  constexpr float max_error = 0.5;

  // Objects
  TemperatureSensor sensor;
  Server server;
  AIModel model;

  // Other Threads
  std::thread UserListenerThread(UserListener);

  // Init
  event_queue_mtx.lock();
  event_queue.push(new Init());
  event_queue_mtx.unlock();
  Log("Station", "Init");

  while (true) {
    // Predict
    float predict = model.predictTemperature();

    // Read
    float read = sensor.read();
    event_queue_mtx.lock();
    event_queue.push(new ReadOk(read));
    event_queue_mtx.unlock();
    Log("Station", "ReadOk");

    float error = std::abs(predict - read);

    // Compare
    if (error > max_error) {
      // Different
      event_queue_mtx.lock();
      event_queue.push(new PredictFail(predict, read));
      event_queue_mtx.unlock();
      Log("Station", "PredictFail");

      // Send Data to Server
      server.SendData(read);
      event_queue_mtx.lock();
      event_queue.push(new SendDataToServer(read));
      event_queue_mtx.unlock();
      Log("Station", "SendDataToServer");

      // Wait New Model
      uint32_t newModel = server.WaitNewData();
      model.setModel(newModel);
      event_queue_mtx.lock();
      event_queue.push(new NewModelArrived(std::to_string(newModel)));
      event_queue_mtx.unlock();
      Log("Station", "NewModelArrived");

    } else {
      // Equal
      event_queue_mtx.lock();
      event_queue.push(new PredictOk(predict, read));
      event_queue_mtx.unlock();
      Log("Station", "PredictOk");
    }

    // Sleep
    event_queue_mtx.lock();
    event_queue.push(new Sleep(10));
    event_queue_mtx.unlock();
    Log("Station", "Sleep");
    std::this_thread::sleep_for(10s);

    // Wake up
    event_queue_mtx.lock();
    event_queue.push(new WakeUp());
    event_queue_mtx.unlock();
    Log("Station", "WakeUp");
  }
}
