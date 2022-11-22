#include "Clock.hpp"

Clock::Clock(int h, int m, int s, int pm) {
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::setClock(int h, int m, int s, int pm) {
    hr = h;
    min = m;
    sec = s;
    is_pm = pm;
}

void Clock::readClock(int &h, int &m, int &s, int &pm) {
    h = hr;
    m = min;
    s = sec;
    pm = is_pm;
}

void Clock::advance() {
    sec++;

    if (sec == 60) {
        sec = 0;
        min++;
        if (min == 60) {
            min = 0;
            hr++;
            if (hr == 12) {
                is_pm = !is_pm;
                if (hr > 12) hr = 1;
            }
        }
    }
}
