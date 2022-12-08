#pragma once
#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

#include "Event/EventBase.hpp"

namespace AppMenu {

int getEventTypeMenu() {
  int sel{-1};

  std::vector<int> valid_input = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  while (sel == -1) {
    std::cout << "\n====================Menu====================";
    std::cout << "\nWanna search for what event type?";
    std::cout << "\n [1] - Init";
    std::cout << "\n [2] - ReadOk";
    std::cout << "\n [3] - ReadFail";
    std::cout << "\n [4] - PredictOk";
    std::cout << "\n [5] - PredictFail";
    std::cout << "\n [6] - SendDataToServer";
    std::cout << "\n [7] - NewModelArrived";
    std::cout << "\n [8] - Sleep";
    std::cout << "\n [9] - WakeUp";
    std::cout << "\n [0] - Error";
    std::cout << "\n============================================";
    std::cout << "\n Input: ";
    std::cin >> sel;

    if (!(std::find(valid_input.begin(), valid_input.end(), sel) !=
          valid_input.end())) {
      sel = -1;
    }
  }
  return sel;
}

std::time_t getTimeFromUserMenu(std::string const prompt) {
  uint16_t d, mo, y;
  uint16_t h, m, s;

  std::time_t rawtime;
  struct std::tm* timeinfo;

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  std::cout << "\n====================" << prompt << "====================\n";
  std::cout << "Day Month Year\n";
  std::cin >> d >> mo >> y;
  std::cout << "Hour Minute Second\n";
  std::cin >> h >> m >> s;
  timeinfo->tm_mday = d;
  timeinfo->tm_mon = mo - 1;
  timeinfo->tm_year = y - 1900;
  timeinfo->tm_hour = h;
  timeinfo->tm_min = m;
  timeinfo->tm_sec = s;

  std::cout << std::flush;

  return std::mktime(timeinfo);
}

std::time_t getTimeFromCodeMenu(uint16_t d,
                                uint16_t mo,
                                uint16_t y,
                                uint16_t h,
                                uint16_t m,
                                uint16_t s) {
  std::time_t rawtime;
  struct std::tm* timeinfo;
  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  timeinfo->tm_mday = d;
  timeinfo->tm_mon = mo - 1;
  timeinfo->tm_year = y - 1900;
  timeinfo->tm_hour = h;
  timeinfo->tm_min = m;
  timeinfo->tm_sec = s;

  std::cout << std::flush;

  return std::mktime(timeinfo);
}

std::vector<EventBase*> getTimedSliceMenu(
    std::vector<EventBase*> vector_to_slice,
    time_t beginTime,
    time_t endTime) {
  EventBase* SliceBegin;
  for (auto i{0}; i < vector_to_slice.size(); i++) {
    if (vector_to_slice[i]->getTime() > beginTime) {
      if (i == 0)
        SliceBegin = vector_to_slice[i];
      else
        SliceBegin = vector_to_slice[i - 1];
      break;
    }
  }

  EventBase* SliceEnd;
  for (auto i{0}; i < vector_to_slice.size(); i++) {
    if (i == vector_to_slice.size() - 1) {
      SliceEnd = vector_to_slice[i];
      break;
    } else if (vector_to_slice[i]->getTime() > endTime) {
      if (i == 0)
        SliceEnd = vector_to_slice[i];
      else
        SliceEnd = vector_to_slice[i - 1];
      break;
    }
  }

  std::vector<EventBase*> slice;
  bool inSlice{false};
  for (auto i : vector_to_slice) {
    if (i == SliceBegin) {
      inSlice = true;
    }
    if (i == SliceEnd) {
      inSlice = false;
    }
    if (inSlice) {
      slice.emplace_back(i);
    }
  }

  return slice;
};

void printQueueSlice(std::vector<EventBase*>& slice) {
  std::cout << "\n====================Found Data====================";
  std::cout << "\n====================" << slice.size()
            << " Entries====================\n";
  for (auto i : slice) {
    std::cout << *i << "\n";
  }
}

}  // namespace AppMenu
