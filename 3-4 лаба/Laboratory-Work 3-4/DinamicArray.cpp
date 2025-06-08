#include <iostream>
#include "functions.cpp"


int main()
{
   // try
    //{
        const int32_t SIZE = 100;
        int32_t size{};
        std::cout << "Введите размер массива: " ;
        InputSize(size); 
        if(!IsNatural(size) || size > SIZE)
        {
            throw ;
        }
        //double arr[100];
        double* arr = nullptr;
        CreateArray (size , arr);
        FillArray(size, arr);
        OutputArray(size, arr);
        //std::cout << "max " << LastMaxElementArray(size ,arr);
        //std::cout << " i min " << LastMinELementArray(size , arr)<< '\n';
        //std::cout << "res " << proizvedwnieelementovarray(size , arr, LastMaxElementArray(size ,arr) , LastMinELementArray(size , arr)) << '\n' ;
        //std::cout << "res " << proizvedwnieelementovarray(size , arr, 2 , 6) << '\n' ;
        //SortAscending(size, arr);
        //SortAscending(size, arr);
        //PlusElenment(size , arr, 7);
        //std::cout << LastNumberModulMinELementArray(size , arr)<< '\n';
        //std::cout << FirstMinusElementArray(size, arr) << '\n';
        //std::cout << ProductArrayElements(size , arr, LastMaxElementArray(size ,arr) , LastMinELementArray(size , arr)) << '\n';
        //ShiftElementArray(size , arr , 3 , 1);
        //DeleteNumberFromArray(size , arr);
        //ShiftElementArray(size , arr, 1 , 1);
        //PlusElenment(size , arr, 0, 52);
        //SortEvenElementArray(size , arr);
        //ShiftElementArray(size , arr, 2 , 1);
        //AddElementInArray(size , arr, 2 , 6);
        OutputArray(size, arr);
        //std::cout << NamberMinELement(size , arr);
       // std::cout << SumElementsAfterFirstMinusElementArray (size, arr) << '\n';
        //    5.65 -670.2 7  50.65 50.65 34 49 -670.2 7 45.5 50.65

 //   }
   // catch(...)
   // {
   //    std::invalid_argument ;
   //    std::cout << "не корректный размер массива";
   // }

    return 0;
}








