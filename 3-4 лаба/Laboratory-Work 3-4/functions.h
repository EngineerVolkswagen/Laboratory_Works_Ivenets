#include <iostream>
#include "functions.cpp"


bool IsNatural(int32_t); // 1 1
void InputSize(int32_t&); // вводит размер массива 1 1
void CreateArray (int32_t , double*& ); // создает динамический массив 1
void Delete(double*& ); // очищает память массива 1
template<class Type>
void FillArray(int32_t , Type); // заполнения массива 1 1
template<class Type>
void OutputArray(int32_t , Type ); // вывод массива 1 1

// вариант 6 зад 1
template<class Type>
int32_t LastNumberModulMinELementArray(int32_t, Type); // находит номер минимального по модулю элемента массива (если таких элементов несколько, найти максимальный номер) 1 1
// ваиант 6 зад 2
template<class Type>
int32_t FirstMinusElementArray(int32_t, Type); // находит первый отрицательный элемент в массиве 1 1
template<class Type>
double SumElementsAfterFirstMinusElementArray (int32_t , Type ); // находит сумму элементов после первого отрицательного элемета 1 1
// вариант 6 зад 3
template<class Type>
void DeleteNumberFromArray(int32_t& , Type ); // удаляет все элементы заданые введенному числу 1 1


template<class Type>
void ShiftElementArray(int32_t , Type , int32_t  , int32_t); //удаляет элемент на заданой позиции сдвигом 1 1

//void DeleteElenment(int32_t&  , double*&, int32_t); // удаляет элемент на заданой позиции DinamicArray 1 0
//void AddElementInArray(int32_t & , double*& , int32_t , double ); // добавляет елемент на заданую позицию DinamicArray  1 0

// вариант 15 зад 1
template<class Type>
void SortAscending(int32_t&, Type);// сортирует массив по возрастанию удаляя минимум елементов 1 1
// вариант 15 зад 2
template<class Type>
int32_t LastMinElementArray(int32_t , Type); // находит позицию поледнего минимального элемента 1 1
template<class Type>
int32_t LastMaxElementArray(int32_t , Type );// находит позицию поледнего максимального элемента 1 1
template<class Type>
double ProductArrayElements(int32_t , Type , int32_t, int32_t); // считает произведение элементов между задаными элементами 1 1
// вариант 15 зад 3
template<class Type>
void SortEvenElementArray(int32_t& , Type); // 1 1
template<class Type>
void BubleSort(int32_t& , Type); // 1 1
void swap(double&, double& ); // 1 1