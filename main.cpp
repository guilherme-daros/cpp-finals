#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "AppMenu.hpp"
#include "Event/Init.hpp"
#include "Event/NewModelArrived.hpp"
#include "Event/PredictFail.hpp"
#include "Event/PredictOk.hpp"
#include "Event/ReadFail.hpp"
#include "Event/ReadOk.hpp"
#include "Event/SendDataToServer.hpp"
#include "Event/Sleep.hpp"
#include "Event/WakeUp.hpp"

int main(int argc, char const *argv[]) {
    using namespace std::chrono_literals;

    std::vector<EventBase *> queue;

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

    const time_t initialTime{AppMenu::getTimeFromUserMenu("Initial Time")};

    const time_t endTime{AppMenu::getTimeFromUserMenu("End Time")};

    int option = AppMenu::getEventTypeMenu();

    std::vector<EventBase *> slice = AppMenu::getTimedSliceMenu(queue, initialTime, endTime);

    AppMenu::printQueueSlice(slice);
}
