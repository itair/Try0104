//mytime1.cpp -----Time class methods

#include "mytime1.h"
#include <iostream>


Time ::Time (){
  hours = minutes = 0;
}

Time ::~Time (){
}

Time::Time(int h, int m /* = 0 */) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes /60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time:: Reset(int h /* = 0 */, int m /* = 0 */) {
  hours = h;
  minutes = m;
}

Time Time::operator+(const Time & t) const {
  Time sum;
  sum.minutes = minutes + t.minutes;
  sum.hours = hours + t.hours;
  sum.minutes %= 60;
  return sum;
}

void Time::Show() const  {
  std::cout << hours << " hours, " << minutes << " minutes";
}