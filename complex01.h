#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class Complex {
public:
  Complex();
  Complex(double r, double i = 0.0);
  ~Complex();
  Complex operator+(const Complex & b) const;
  Complex operator-(const Complex & b) const;
  Complex operator~() const;
  Complex operator*(double n) const;
  Complex operator*(Complex & b) const;
  friend Complex operator*(double n, const Complex & a);
  friend std::istream & operator >> (std::istream & os, Complex & v);
  friend std::ostream & operator << (std::ostream & os, const Complex & v);

private:
  double real;
  double imag;

};

#endif 