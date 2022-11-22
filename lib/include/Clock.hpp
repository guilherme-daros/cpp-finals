#pragma once
class Clock {
   protected:
    int hr, min, sec, is_pm;

   public:
    Clock(int h, int m, int s, int pm);
    void setClock(int h, int m, int s, int pm);
    void readClock(int &h, int &m, int &s, int &pm);
    void advance();
};
