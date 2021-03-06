// vect.h == Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_ 

#include <iostream>
namespace VECTOR {
  class Vector  {
  public:
    enum Mode {RECT, POL};
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void Reset(double n1, double n2, Mode form =RECT);
   	~Vector();
    double xval() const {return x;}
    double yval() const {return y;}
    double magval(); 
    double angval();
    void polar_mode();
    void rect_mode();
    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const;
    Vector operator-() const;
    Vector operator*(double n) const;
    friend Vector operator*(double n, const Vector & a);
    friend std::ostream & operator << (std::ostream & os, const Vector & v);

  private:
//     void set_mag();
//     void set_ang();
    void set_x();
    void set_y();
    double x;
    double y;
    double mag;
    double ang;
    Mode mode;
  };
}// end namespace VECTOR

#endif