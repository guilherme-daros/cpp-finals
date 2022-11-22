#include "ClockCalendar.hpp"

ClockCalendar::ClockCalendar(int d, int m, int y, int h, int min, int s, int pm)
    : Clock(h, min, s, pm), Calendar(d, m, y){};

void ClockCalendar::advance() {
  int was_pm = is_pm;
  Clock::advance();
  if (was_pm && !is_pm) Calendar::advance();
};