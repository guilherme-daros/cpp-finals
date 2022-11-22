#pragma once
#include "Calendar.hpp"
#include "Clock.hpp"

class ClockCalendar : public Clock, public Calendar {
 public:
  ClockCalendar(int d, int m, int y, int h, int min, int s, int pm);
  void advance();
};
