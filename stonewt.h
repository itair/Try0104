// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    enum Mode {STONE, POUNDS_INT, POUNDS_FLOAT };
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    Mode mode;
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format
    void mode_stone();   // swich Mode;
    void mode_pds();
    void mode_pdf() ;
    Stonewt operator+(const Stonewt & b) const;
    Stonewt operator-(const Stonewt & b) const;
    Stonewt operator-() const;
    Stonewt operator*(double n) const;
    friend Stonewt operator*(double n, const Stonewt & a);
    friend std::ostream & operator << (std::ostream & os, const Stonewt & v);
    bool operator>(const Stonewt & b) { return pounds > b.pounds; }
    bool operator<(const Stonewt & b) { return pounds < b.pounds ; }
    bool operator==(const Stonewt & b) { return pounds == b.pounds;  }
    bool operator>=(const Stonewt & b) { return !(pounds < b.pounds ); }
    bool operator<=(const Stonewt & b) { return !(pounds>b.pounds); }
    bool operator!=(const Stonewt & b) { return !(pounds == b.pounds); }
};

void display(const Stonewt & st, int n); //for stone class
#endif
