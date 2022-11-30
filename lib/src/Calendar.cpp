#include "Calendar.hpp"

Calendar::Calendar(int d, int m, int y) {
  day = d;
  mo = m;
  yr = y;
}

void Calendar::setCalendar(int d, int m, int y) {
  day = d;
  mo = m;
  yr = y;
}

void Calendar::readCalendar(int& d, int& m, int& y) {
  d = day;
  m = mo;
  y = yr;
}

void Calendar::advance() {
  day++;
  if (day > 30) {
    day = 1;
    mo++;
    if (mo > 12) {
      mo = 1;
      yr++;
    }
  }
}
