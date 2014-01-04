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
  
  longline(1); //1 2, 3 
  using VECTOR::Vector;
  srand(time(0));
  double direction;
  Vector step;
  Vector result(0.0, 0.0);
  unsigned long steps = 0;
  unsigned int times = 0;
  unsigned long steps_min = kMax;
  unsigned long steps_max = 0;
  unsigned long steps_total = 0;
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
    cout << "Enter test times: ";
    if (!(cin >> times))
      break;
    unsigned t = times;
    while (t--){
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
      //加入新输出 最大步数 最小步数 平均步数
      steps_total += steps;
      steps_max = steps_max > steps ? steps_max : steps;
      steps_min = steps_min < steps ? steps_min : steps; 
      steps = 0;
      result.Reset(0.0, 0.0);
    }
    cout << "Max steps: " << steps_max << endl;
    cout << "Min steps: " << steps_min << endl;
    cout << "Average steps: " << steps_total / times << endl;
    steps_total = steps_max = steps_min = 0;
    cout << "Enter target distance (q to quit): ";     
  }
  cout << "Bye!\n";
  //1---现有库类的调用方法 实际读写
  //2-- 类内部改写不影响接口
  //3-- 应用 外部改写 不影响 类的结构
  longline(2); //2




  longline();
  system("pause");
}