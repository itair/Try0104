//Inline.h  // 全局常量内联库 //资源常量

#ifndef TRY0104_TRY0104_INLINE_H
#define TRY0104_TRY0104_INLINE_H
#include <iostream>
//常用内联

inline void longline(void) { 
  std::cout<< "_________________________\n\n";
}
inline void longline(const int i) { 
  std::cout<< "\n " << i << ".__________________\n\n"; 
}

#endif //TRY0104_TRY0104_INLINE_H