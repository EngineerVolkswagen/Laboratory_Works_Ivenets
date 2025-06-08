#include <iostream>
#include <iomanip>
#include "function.h"


int main()
{
    int32_t** mtr;
    int32_t line{0}, column{0};
    std::cin >> line ;
    std::cin >> column;
    std::cout << '\n' ;
    CreatArray(mtr, line, column);
    InputElementArray(mtr, line ,column);
    std::cout << '\n';
    OutputElementArray(mtr, line ,column);
    //output(mtr, line ,column);
   // SMENA(mtr, line , column);
    //int32_t a{MaxElementInARRay(mtr, line, column)};
  
    //std::cout << "max: " <<MaxElementInARRay( mtr,  line , column)  << "fgh: " << elementmencshzadanogo(mtr,line,column,a) << " ff: " << mtr[Index_I(mtr,line,column,elementmencshzadanogo(mtr,line,column,a))][Index_J(mtr,line,column,elementmencshzadanogo(mtr,line,column,a))];
      
    //smena(mtr,line,column);
    //std::cout << dfg(mtr,line,column);
    std::cout << "Result: "<< CheckIfStringNegative(mtr,column,line);
    std::cout << '\n';
    OutputElementArray(mtr, line ,column);
    std::cout << '\n';
    return 0;
}