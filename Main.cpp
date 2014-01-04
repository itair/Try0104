/*-----------------------------------------
//   C++ Primer Plus 课后习题 p422 11.9
//   by itAir
//   Try to use Google C++ programing style   
----------------------------------------- */    
#include "Try.h"
#include "GobalFuc.h"
#include "Inline.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "vect.h"

void main()
{
  using namespace std;
  showtitle();
  longline();
  
  longline(1); //1  
  using VECTOR::Vector;
  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  double target;
  double dstep;
   fstream fout;
   fout.open("out.txt", ios_base::in | ios_base::out | ios_base::trunc ); // w+
   if (!fout.is_open()) {
     cout << "I/O Error! ";
     system("pause");
     exit(EXIT_FAILURE);
   }
  cout << "Enter target distance (q to quit): ";
  while (cin >> target)
  {
    cout << "Enter step length: ";
    if (!(cin >> dstep))
      break;
    //加入文件读写
    fout << "Target Distance: " << target <<", Step Size: " << dstep << endl;
    fout << steps << ": (x,y) = ("
         << result.xval() << ", " << result.yval() << ")\n";
    while (result.magval() < target)
    {
      direction = rand() % 360;
      step.Reset(dstep, direction, Vector::POL);
      result = result + step;
      steps++;
      fout << steps << ": (x,y) = (" 
           << result.xval() << ", " << result.yval() << ")\n";
    }
    cout << "After " << steps << " steps, the subject "
      "has the following location:\n";
    fout << "After " << steps << " steps, the subject "
      "has the following location:\n";
    cout << result << endl;
    fout <<  result << endl;
    result.polar_mode();
    cout << " or\n" << result << endl;
    cout << "Average outward distance per step = "
      << result.magval()/steps << endl;
    fout << " or\n" << result << endl;
    fout << "Average outward distance per step = "
      << result.magval()/steps << endl;
    steps = 0;
    result.Reset(0.0, 0.0);
    cout << "Enter target distance (q to quit): ";
  }
  cout << "Bye!\n";
  //现有库类的调用方法 实际读写
  longline(2); //2




  longline();
  system("pause");
}