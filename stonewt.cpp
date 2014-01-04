// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

void display(const Stonewt & st, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Wow! ";
    st.show_stn();
  }
}

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = STONE;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

void Stonewt::mode_stone() {
  mode = STONE;
}

void Stonewt::mode_pds() {
  mode = POUNDS_INT;
}

void Stonewt::mode_pdf(){
  mode = POUNDS_FLOAT;
}

Stonewt Stonewt::operator+(const Stonewt & b) const {
  return Stonewt(stone + b.stone, pounds + b.pounds);
}

Stonewt Stonewt::operator-(const Stonewt & b) const {
  return Stonewt(stone - b.stone , pounds - b.pounds);
}

Stonewt Stonewt::operator-() const {
  return Stonewt(-stone, -pounds);
}

Stonewt Stonewt::operator*(double n) const {
  return Stonewt((int)(n * stone), n * pounds);
}

Stonewt operator*(double n, const Stonewt & a) {
  return a * n; 
}

std::ostream & operator << (std::ostream & os, const Stonewt & v) {
  if (v.mode == Stonewt::STONE)  {
    os <<  v.stone << " stone\n ";
  } else if (v.mode == Stonewt::POUNDS_FLOAT) {
    os << v.pounds << " pounds\n";
  } else {
    os << v.pounds + v.pds_left << " pounds\n";
  }
  return os;
}