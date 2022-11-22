#pragma once

class Calendar {
 protected:
  int day, mo, yr;

 public:
  Calendar(int d, int m, int y);
  void setCalendar(int d, int m, int y);
  void readCalendar(int &d, int &m, int &y);
  void advance();
};