//mytime1.h ----Time class befor operator overloading
#ifndef MYTIME1_H
#define  MYTIME1_H
class Time {
public:
  Time ();
  ~Time ();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset (int h = 0, int m = 0);
  Time operator + (const Time & t) const;
  void Show () const;
  
private:
  int hours;
  int minutes;

};







#endif// MYTIME1_H