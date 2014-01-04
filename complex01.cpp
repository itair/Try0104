//complex01.cpp methods for complex class
#include "complex01.h"

Complex::Complex() {
  real = 0.0;
  imag = 0.0;
}

Complex::Complex(double r, double i /*= 0.0*/) {
  real = r;
  imag = i;
}

Complex::~Complex() {}

Complex Complex::operator+(const Complex & b) const {
  Complex tem;
  tem.real = real + b.real;
  tem.imag = imag + b.imag;
  return tem;
}

Complex Complex::operator-(const Complex & b) const {
  Complex tem;
  tem.real = real - b.real;
  tem.imag = imag - b.imag;
  return tem;
}

Complex Complex::operator~() const {
  Complex tem (real, -imag);
  return tem;
}

Complex Complex::operator*(double n) const {
  Complex tem;
  tem.real = real * n;
  tem.imag = imag * n;
  return tem;
}

Complex Complex::operator*(Complex & b) const {
  Complex tem;
  tem.real = real * b.real - imag * b.imag;
  tem.imag = real * b.imag + imag * b.real;
  return tem;
}

Complex operator*(double n , const Complex & a) {
  return a*n;
}

std::istream & operator >> (std::istream & os, Complex & v) {
  std::cout << "real: ";
  os >> v.real;
  std::cout <<"imageinary: ";
  os >> v.imag;
  return os;
}

std::ostream & operator << (std::ostream & os, const Complex & v) {
  os << "(" << v.real;
  os << "," << v.imag <<"i)";
  return os;
}

